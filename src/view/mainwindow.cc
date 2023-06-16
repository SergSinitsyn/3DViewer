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

#include "../controller/controller.h"
#include "info/info.h"
#include "movement_control.h"
#include "rotation_control.h"
#include "ui_mainwindow.h"
#include "widget.h"

namespace s21 {
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui_(new Ui::MainWindow),
      model_information_(),
      model_data_() {
  ui_->setupUi(this);
  SetupControls();
  setAppPath(QCoreApplication::applicationDirPath());
  load_setting_from_file();
  setupRadiobuttons();
  DefaultControls();
  EnableControls(false);
  setWindowTitle(window_title_);

  // // Set up recent files menu
  // QMenu *recent_files_menu = ui_->menuRecent_Files;
  // QAction *recent_files_action = recent_files_menu->menuAction();
  // recent_files_menu->clear();
  // recent_files_menu->addAction(recent_files_action);
}

MainWindow::~MainWindow() {
  save_setting_to_file();
  delete ui_;
}

void MainWindow::SetController(Controller &controller) {
  controller_ = &controller;
  rotation_control_x_.SetController(*controller_);
  rotation_control_y_.SetController(*controller_);
  rotation_control_z_.SetController(*controller_);
  movement_control_.SetController(*controller_);
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
  const int angle = 0;
  const double size = 0.05;
  const double scale = 100;

  ui_->centralwidget->blockSignals(true);

  ui_->dial_x->setValue(angle);
  ui_->dial_y->setValue(angle);
  ui_->dial_z->setValue(angle);
  ui_->spinBox_x->setValue(angle);
  ui_->spinBox_y->setValue(angle);
  ui_->spinBox_z->setValue(angle);
  ui_->doubleSpinBox_move_x->setValue(size);
  ui_->doubleSpinBox_move_y->setValue(size);
  ui_->doubleSpinBox_move_z->setValue(size);
  ui_->doubleSpinBox_scale->setValue(scale);

  ui_->widget->height();
  ui_->widget->width();
  ui_->actionModel_information->setEnabled(false);

  ui_->centralwidget->blockSignals(false);
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
    DefaultControls();
    EnableControls(true);
    setWindowTitle(QString::fromStdString(model_information_.file_name) +
                   " @ " + window_title_);
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
    ui_->statusbar->showMessage("Error loading file: '" + new_filename + "'" +
                                ", error:" + e.what());
  }
}

void my_func(int a) { qDebug() << a; }

void MainWindow::SetupControls() {
  rotation_control_x_.SetupRotationControl(my_func, ui_->spinBox_x,
                                           ui_->dial_x);
  rotation_control_y_.SetupRotationControl(my_func, ui_->spinBox_y,
                                           ui_->dial_y);
  rotation_control_z_.SetupRotationControl(my_func, ui_->spinBox_z,
                                           ui_->dial_z);

  movement_control_.SetupMovementControl(
      ui_->statusbar, ui_->doubleSpinBox_move_x, ui_->doubleSpinBox_move_y,
      ui_->doubleSpinBox_move_z, ui_->toolButton_xPos, ui_->toolButton_xNeg,
      ui_->toolButton_yPos, ui_->toolButton_yNeg, ui_->toolButton_zPos,
      ui_->toolButton_zNeg);
  scaling_control_.SetupScalingControl(
      ui_->statusbar, ui_->doubleSpinBox_scale, ui_->pushButton_scale,
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

void MainWindow::setupRadiobuttons() {
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
  switch (settings.projection) {
    case PARALLEL:
      ui_->actionParallel->setChecked(true);
      break;
    case CENTRAL:
      ui_->actionCentral->setChecked(true);
      break;
    default:
      ui_->actionCentral->setChecked(true);
      break;
  }
  switch (settings.line) {
    case SOLID:
      ui_->actionSolid->setChecked(true);
      break;
    case DASHED:
      ui_->actionDashed->setChecked(true);
      break;
    default:
      ui_->actionDashed->setChecked(true);
      break;
  }
  switch (settings.displayVertexes) {
    case NONE:
      ui_->actionNone->setChecked(true);
      break;
    case CIRCLE:
      ui_->actionCircle->setChecked(true);
      break;
    case SQUARE:
      ui_->actionSquare->setChecked(true);
      break;
    default:
      ui_->actionSquare->setChecked(true);
      break;
  }
}
// TODO переделать в сигнал?
void MainWindow::on_actionOpen_OBJ_file_triggered() { LoadFile(); }

void MainWindow::on_actionModel_information_triggered() {
  s21::Info info(nullptr, model_information_);
  info.setModal(true);
  info.exec();
}

void MainWindow::on_actionOpen_documentation_triggered() {
  //! правильные пути!
#ifdef Q_OS_LINUX
  QString link =
      QCoreApplication::applicationDirPath() + "/../documentation/index.html";
#else
  QString link = QCoreApplication::applicationDirPath() +
                 "/../../../../documentation/index.html";
#endif
  if (QFile::exists(link)) {
    QDesktopServices::openUrl(QUrl("file:///" + link));
    ui_->statusbar->showMessage("Documentation file is open");
  } else {
    ui_->statusbar->showMessage("Documentation file not found");
  }
}

// std::deque<QString> MainWindow::GetRecentFiles() const { return
// recent_files_; }

// void MainWindow::on_actionOpen_OBJ_file_triggered() {
//   QString file_name = QFileDialog::getOpenFileName(
//       this, tr("Open OBJ File"), *getAppPath(), tr("OBJ Files (*.obj)"));
//   if (!file_name.isEmpty()) {
//     LoadFile(file_name);

//     // Add the opened file to the list of recent files
//     recent_files_.push_front(file_name);
//     if (recent_files_.size() > kMaxRecentFiles) {
//       recent_files_.pop_back();
//     }

//     // Update recent files menu
//     QMenu *recent_files_menu = ui_->menuRecent_Files;
//     recent_files_menu->clear();
//     QAction *recent_files_action = recent_files_menu->menuAction();
//     recent_files_menu->addAction(recent_files_action);
//     for (const auto &recent_file : recent_files_) {
//       QAction *action = new QAction(recent_file, this);
//       connect(action, &QAction::triggered, [this, recent_file]() {
//       LoadFile(recent_file); }); recent_files_menu->addAction(action);
//     }
//   }
// }

};  // namespace s21
