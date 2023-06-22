#include "mainwindow.h"

#include <libgen.h>

#include <QActionGroup>
#include <QColor>
#include <QColorDialog>
#include <QDebug>
#include <QDesktopServices>
#include <QFileDialog>
#include <QFileInfo>
#include <QInputDialog>
#include <QMessageBox>
#include <QUrl>
#include <QWindow>
#include <algorithm>
#include <functional>

#include "../../controller/controller.h"
#include "../info/info.h"
#include "../widget/widget.h"
#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui_(new Ui::MainWindow),
      model_information_(),
      model_data_() {
  ui_->setupUi(this);
  SetupControls();

  LoadSettingFromFile();
  start_settindgs_ = new Memento<WidgetSettings>(settings_);
  SetupRadioButtons();
  CreateRecentFilesMenu();

  DefaultControls();
  EnableControls(false);
  setWindowTitle(window_title_);
}

MainWindow::~MainWindow() {
  SaveSettingToFile();
  delete start_settindgs_;
  delete ui_;
}

void MainWindow::SetController(Controller &controller) {
  controller_ = &controller;
  rotation_control_x_.SetController(*controller_);
  rotation_control_y_.SetController(*controller_);
  rotation_control_z_.SetController(*controller_);
  movement_control_x_.SetController(*controller_);
  movement_control_y_.SetController(*controller_);
  movement_control_z_.SetController(*controller_);
  scaling_control_.SetController(*controller_);
}

void MainWindow::SetModelData(const std::vector<double> &vertices,
                              const std::vector<int> &edges) {
  model_data_.vertices = vertices;
  model_data_.edges = edges;
  ui_->widget->SetModelData(model_data_);
}

void MainWindow::SetModelInformation(const ModelInformation &information) {
  model_information_ = information;
  ShowInformation();
}

void MainWindow::UpdateWidget() { ui_->widget->update(); }

void MainWindow::DefaultControls() {
  rotation_control_x_.Default();
  rotation_control_y_.Default();
  rotation_control_z_.Default();
  movement_control_x_.Default();
  movement_control_y_.Default();
  movement_control_z_.Default();
  scaling_control_.Default();
}

void MainWindow::EnableControls(bool enable) {
  ui_->centralwidget->setEnabled(enable);
  ui_->actionModel_information->setEnabled(enable);
  ui_->actionSave_OBJ_to_Image->setEnabled(enable);
}

void MainWindow::LoadFile() {
  ui_->statusbar->showMessage("Loading file...");
  QDir::currentPath();
  QString new_filename = QFileDialog::getOpenFileName(0, "Open", "", "*.obj");
  if (new_filename.isEmpty()) {
    ui_->statusbar->showMessage("File not selected");
    return;
  }
  try {
    controller_->LoadFile(new_filename.toStdString());
    settings_.RememberRecentFile(new_filename);
    UpdateRecentFilesMenu();
    DefaultControls();
    EnableControls(true);
    setWindowTitle(QString::fromStdString(model_information_.file_name) +
                   " @ " + window_title_);
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
    ui_->statusbar->showMessage("Error loading file: '" + new_filename + "'" +
                                ", error:" + e.what());
    DefaultControls();
    EnableControls(false);
    UpdateWidget();
  }
}

void MainWindow::SetupControls() {
  rotation_control_x_.SetupRotationControl(&Controller::RotateAroundXAxis,
                                           ui_->spinBox_x, ui_->dial_x);
  rotation_control_y_.SetupRotationControl(&Controller::RotateAroundYAxis,
                                           ui_->spinBox_y, ui_->dial_y);
  rotation_control_z_.SetupRotationControl(&Controller::RotateAroundZAxis,
                                           ui_->spinBox_z, ui_->dial_z);
  movement_control_x_.SetupMovementControl(
      &Controller::ShiftOnXAxis, ui_->doubleSpinBox_move_x,
      ui_->toolButton_xPos, ui_->toolButton_xNeg);
  movement_control_y_.SetupMovementControl(
      &Controller::ShiftOnYAxis, ui_->doubleSpinBox_move_y,
      ui_->toolButton_yPos, ui_->toolButton_yNeg);
  movement_control_z_.SetupMovementControl(
      &Controller::ShiftOnZAxis, ui_->doubleSpinBox_move_z,
      ui_->toolButton_zPos, ui_->toolButton_zNeg);
  scaling_control_.SetupScalingControl(
      &Controller::Scaling, ui_->doubleSpinBox_scale, ui_->pushButton_scale,
      ui_->toolButton_scaleL, ui_->toolButton_scaleH);
}

void MainWindow::ShowInformation() {
  QString number_of_edges =
      QString::number(model_information_.edges_number, 'g', 8);
  QString number_of_vertices =
      QString::number(model_information_.vertices_number, 'g', 8);
  QString number_of_faces =
      QString::number(model_information_.facetes_number, 'g', 8);
  ui_->statusbar->showMessage(
      "File: '" + QString::fromStdString(model_information_.file_name) +
      "', Edges: " + number_of_edges + ", Vertices: " + number_of_vertices +
      ", Faces: " + number_of_faces);
}

int MainWindow::LoadRecentFile() {
  QAction *action = qobject_cast<QAction *>(QObject::sender());
  try {
    controller_->LoadFile(action->text().toStdString());
    EnableControls(true);
  } catch (std::exception &e) {
    QMessageBox::warning(this, "Error loading file" + action->text(), e.what());
  }
  return 0;
}

void MainWindow::CreateRecentFilesMenu() {
  const auto recent_files = settings_.GetRecentFiles();
  if (!recent_files->empty()) {
    recent_files_menu_ = ui_->menuFile->addMenu("Recent files");
    for (const auto &file : *recent_files) {
      auto action = recent_files_menu_->addAction(file);
      connect(action, &QAction::triggered, this, &MainWindow::LoadRecentFile);
    }
  }
}

void MainWindow::RemoveRecentFilesMenu() {
  if (recent_files_menu_)
    ui_->menuFile->removeAction(recent_files_menu_->menuAction());
}

void MainWindow::UpdateRecentFilesMenu() {
  RemoveRecentFilesMenu();
  CreateRecentFilesMenu();
}

void MainWindow::SetActualSettingsMenu() {
  switch (settings_.projection()) {
    case kParallel:
      ui_->actionParallel->setChecked(true);
      break;
    case kCentral:
      ui_->actionCentral->setChecked(true);
      break;
    default:
      ui_->actionCentral->setChecked(true);
      break;
  }
  switch (settings_.lineType()) {
    case kSolid:
      ui_->actionSolid->setChecked(true);
      break;
    case kDashed:
      ui_->actionDashed->setChecked(true);
      break;
    default:
      ui_->actionDashed->setChecked(true);
      break;
  }
  switch (settings_.displayVertexes()) {
    case kNone:
      ui_->actionNone->setChecked(true);
      break;
    case kCircle:
      ui_->actionCircle->setChecked(true);
      break;
    case kSquare:
      ui_->actionSquare->setChecked(true);
      break;
    default:
      ui_->actionSquare->setChecked(true);
      break;
  }
}

void MainWindow::SetupRadioButtons() {
  QActionGroup *typeGroup = new QActionGroup(this);
  QActionGroup *display_methodGroup = new QActionGroup(this);
  QActionGroup *projectionGroup = new QActionGroup(this);
  projectionGroup->addAction(ui_->actionParallel);
  projectionGroup->addAction(ui_->actionCentral);
  typeGroup->addAction(ui_->actionSolid);
  typeGroup->addAction(ui_->actionDashed);
  display_methodGroup->addAction(ui_->actionNone);
  display_methodGroup->addAction(ui_->actionCircle);
  display_methodGroup->addAction(ui_->actionSquare);
  SetActualSettingsMenu();
}

void MainWindow::on_actionOpen_OBJ_file_triggered() { LoadFile(); }

void MainWindow::on_actionModel_information_triggered() {
  s21::Info info(nullptr, model_information_);
  info.setModal(true);
  info.exec();
}

void MainWindow::on_actionOpen_documentation_triggered() {
#ifdef Q_OS_LINUX
  QString link = QCoreApplication::applicationDirPath() + "/index.html";
#else
  QString link =
      QCoreApplication::applicationDirPath() + "/../../../index.html";
#endif
  if (QFile::exists(link)) {
    QDesktopServices::openUrl(QUrl("file:///" + link));
    ui_->statusbar->showMessage("Documentation file is open");
  } else {
    ui_->statusbar->showMessage("Documentation file not found");
  }
}

void MainWindow::on_undoButton_clicked() {
  DefaultControls();
  controller_->RestoreModel();
}

}  // namespace s21
