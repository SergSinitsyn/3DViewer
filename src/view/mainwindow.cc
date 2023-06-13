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
}

MainWindow::~MainWindow() {
  save_setting_to_file();
  delete ui_;
}

void MainWindow::SetController(Controller &controller) {
  controller_ = &controller;
  rotation_control_.SetController(*controller_);
  movement_control_.SetController(*controller_);
  scaling_control_.SetController(*controller_);
}

void MainWindow::SetModelData(const std::vector<double> &vertices,
                              const std::vector<int> &edges) {
  model_data_.vertices = vertices;
  model_data_.edges = edges;
  ui_->widget->SetModelData(model_data_);
}

void MainWindow::SetupControls() {
  rotation_control_.SetupRotationControl(ui_->statusbar, ui_->spinBox_x,
                                         ui_->spinBox_y, ui_->spinBox_z,
                                         ui_->dial_x, ui_->dial_y, ui_->dial_z);
  movement_control_.SetupMovementControl(
      ui_->statusbar, ui_->doubleSpinBox_move_x, ui_->doubleSpinBox_move_y,
      ui_->doubleSpinBox_move_z, ui_->toolButton_xPos, ui_->toolButton_xNeg,
      ui_->toolButton_yPos, ui_->toolButton_yNeg, ui_->toolButton_zPos,
      ui_->toolButton_zNeg);
  scaling_control_.SetupScalingControl(
      ui_->statusbar, ui_->doubleSpinBox_scale, ui_->pushButton_scale,
      ui_->toolButton_scaleL, ui_->toolButton_scaleH);
  //  rotation_control_.SetController(*controller_);
  //  movement_control_.SetController(*controller_);
  //  scaling_control_.SetController(*controller_);
}

void MainWindow::SetModelInformation(const ModelInformation &information) {
  model_information_ = information;
  //  ShowInformation();  // TODO
  QString number_of_edges =
      QString::number(model_information_.edges_number, 'g', 8);
  QString number_of_vertices =
      QString::number(model_information_.vertices_number, 'g', 8);
  QString number_of_faces =
      QString::number(model_information_.facetes_number, 'g', 8);

  QString filename = QString::fromStdString(model_information_.file_name);
  ui_->statusbar->showMessage(
      "File: '" + filename + "', Edges: " + number_of_edges +
      ", Vertices: " + number_of_vertices + ", Faces: " + number_of_faces);
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

void MainWindow::LoadFile() {
  // TODO декомпозировать
  ui_->statusbar->showMessage("Loading file...");
  QDir::currentPath();
  QString new_filename = QFileDialog::getOpenFileName(0, "Open", "", "*.obj");
  if (new_filename.isEmpty()) {
    ui_->statusbar->showMessage("File not selected");
    return;
  }
  DefaultControls();  //? здесь

  // TODO fix
  // ?это все связано с названием
  // QString old_title = windowTitle(), separator = " @ ";
  // //  QString old_filename = *ui_->widget->getObjFileName();
  // QString old_filename = "fix filemane";
  // if (!old_filename.isEmpty()) {
  //   old_filename = basename(old_filename.toLocal8Bit().data());
  //   if (old_title.contains(old_filename))
  //     old_title =
  //         old_title.remove(0, old_filename.length() + separator.length());
  // }

  try {
    controller_->LoadFile(new_filename.toStdString());

    EnableControls(true);

    // TODO fix
    //?это все связано с названием 2
    //    setWindowTitle(QString(basename(model_information_.file_name)) +
    //    separator +
    //                   old_title);

  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
    ui_->statusbar->showMessage("Error loading file: '" + new_filename + "'" +
                                ", error:" + e.what());
    EnableControls(false);
    // TODO fix
    // ?это все связано с названием 3
    // setWindowTitle(old_title);
  }
}

void MainWindow::on_actionOpen_OBJ_file_triggered() { LoadFile(); }

void MainWindow::on_actionModel_information_triggered() {
  s21::Info info(nullptr, model_information_);
  info.setModal(true);
  info.exec();
}

void MainWindow::DefaultControls() {
  ui_->centralwidget->blockSignals(true);

  ui_->dial_x->setValue(0);
  ui_->dial_y->setValue(0);
  ui_->dial_z->setValue(0);
  ui_->spinBox_x->setValue(0);
  ui_->spinBox_y->setValue(0);
  ui_->spinBox_z->setValue(0);
  ui_->doubleSpinBox_move_x->setValue(0.05);
  ui_->doubleSpinBox_move_y->setValue(0.05);
  ui_->doubleSpinBox_move_z->setValue(0.05);
  ui_->doubleSpinBox_scale->setValue(100);

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

void MainWindow::on_actionOpen_documentation_triggered() {
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

};  // namespace s21
