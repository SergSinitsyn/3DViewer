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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      model_information_(),
      model_data_() {
  ui->setupUi(this);
  SetupControls();

  setAppPath(QCoreApplication::applicationDirPath());
  load_setting_from_file();
  setupRadiobuttons();
  DefaultControls();
  EnableControls(false);
}

MainWindow::~MainWindow() {
  save_setting_to_file();
  delete ui;
}

void MainWindow::SetController(Controller &controller) {
  controller_ = &controller;
}

void MainWindow::SetModelData(const std::vector<double> &vertices,
                              const std::vector<int> &edges) {
  model_data_.vertices = vertices;
  model_data_.edges = edges;
  ui->widget->SetModelData(model_data_);
}

void MainWindow::SetupControls() {
  rotation_control_.SetupRotationControl(ui->statusbar, ui->spinBox_x,
                                         ui->spinBox_y, ui->spinBox_z,
                                         ui->dial_x, ui->dial_y, ui->dial_z);
  movement_control_.SetupMovementControl(
      ui->statusbar, ui->doubleSpinBox_move_x, ui->doubleSpinBox_move_y,
      ui->doubleSpinBox_move_z, ui->toolButton_xPos, ui->toolButton_xNeg,
      ui->toolButton_yPos, ui->toolButton_yNeg, ui->toolButton_zPos,
      ui->toolButton_zNeg);
  scaling_control_.SetupScalingControl(
      ui->statusbar, ui->doubleSpinBox_scale, ui->pushButton_scale,
      ui->toolButton_scaleL, ui->toolButton_scaleH);
  rotation_control_.SetController(*controller_);
  movement_control_.SetController(*controller_);
  scaling_control_.SetController(*controller_);
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
  ui->statusbar->showMessage(
      "File: '" + filename + "', Edges: " + number_of_edges +
      ", Vertices: " + number_of_vertices + ", Faces: " + number_of_faces);
  ui->actionModel_information->setEnabled(true);
}

void MainWindow::setupRadiobuttons() {
  QActionGroup *typeGroup = new QActionGroup(this);
  QActionGroup *display_methodGroup = new QActionGroup(this);
  QActionGroup *projectionGroup = new QActionGroup(this);
  projectionGroup->addAction(ui->actionParallel);
  projectionGroup->addAction(ui->actionCentral);
  typeGroup->addAction(ui->actionSolid);
  typeGroup->addAction(ui->actionDashed);
  display_methodGroup->addAction(ui->actionNone);
  display_methodGroup->addAction(ui->actionCircle);
  display_methodGroup->addAction(ui->actionSquare);
  switch (settings.projection) {
    case PARALLEL:
      ui->actionParallel->setChecked(true);
      break;
    case CENTRAL:
      ui->actionCentral->setChecked(true);
      break;
    default:
      ui->actionCentral->setChecked(true);
      break;
  }
  switch (settings.line) {
    case SOLID:
      ui->actionSolid->setChecked(true);
      break;
    case DASHED:
      ui->actionDashed->setChecked(true);
      break;
    default:
      ui->actionDashed->setChecked(true);
      break;
  }
  switch (settings.displayVertexes) {
    case NONE:
      ui->actionNone->setChecked(true);
      break;
    case CIRCLE:
      ui->actionCircle->setChecked(true);
      break;
    case SQUARE:
      ui->actionSquare->setChecked(true);
      break;
    default:
      ui->actionSquare->setChecked(true);
      break;
  }
}

void MainWindow::LoadFile() {
  // TODO декомпозировать
  ui->statusbar->showMessage("Loading file...");
  QDir::currentPath();
  QString new_filename = QFileDialog::getOpenFileName(0, "Open", "", "*.obj");
  if (new_filename.isEmpty()) {
    ui->statusbar->showMessage("File not selected");
    return;
  }
  DefaultControls();  //? здесь

  // TODO fix
  // ?это все связано с названием
  // QString old_title = windowTitle(), separator = " @ ";
  // //  QString old_filename = *ui->widget->getObjFileName();
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
    ui->statusbar->showMessage("Error loading file: '" + new_filename + "'" +
                               ", error:" + e.what());
    EnableControls(false);
    // TODO fix
    // ?это все связано с названием 3
    // setWindowTitle(old_title);
  }
}

void MainWindow::on_actionOpen_OBJ_file_triggered() { LoadFile(); }

void MainWindow::on_actionModel_information_triggered() {
  Info info(nullptr, model_information_);
  info.setModal(true);
  info.exec();
}

void MainWindow::DefaultControls() {
  ui->centralwidget->blockSignals(true);

  ui->dial_x->setValue(0);
  ui->dial_y->setValue(0);
  ui->dial_z->setValue(0);
  ui->spinBox_x->setValue(0);
  ui->spinBox_y->setValue(0);
  ui->spinBox_z->setValue(0);
  ui->doubleSpinBox_move_x->setValue(0.05);
  ui->doubleSpinBox_move_y->setValue(0.05);
  ui->doubleSpinBox_move_z->setValue(0.05);
  ui->doubleSpinBox_scale->setValue(100);

  ui->widget->height();
  ui->widget->width();
  ui->actionModel_information->setEnabled(false);

  ui->centralwidget->blockSignals(false);
}

void MainWindow::EnableControls(bool enable) {
  ui->centralwidget->setEnabled(enable);
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
    ui->statusbar->showMessage("Documentation file is open");
  } else {
    ui->statusbar->showMessage("Documentation file not found");
  }
}
