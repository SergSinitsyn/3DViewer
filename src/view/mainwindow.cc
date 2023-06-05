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
#include <QUrl>
#include <QWindow>

#include "info/info.h"
#include "movement_control.h"
#include "rotation_control.h"
#include "ui_mainwindow.h"
#include "widget.h"

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)

// !не рабатает через конструктор и список инициализации
// ,
// movement_control_(ui->widget, ui->statusbar, ui->doubleSpinBox_move_x,
//                   ui->doubleSpinBox_move_y, ui->doubleSpinBox_move_z),
// rotation_control_(ui->widget, ui->statusbar, ui->spinBox_x, ui->spinBox_y,
//                   ui->spinBox_z, ui->dial_x, ui->dial_y, ui->dial_z),
// scaling_control_(ui->widget, ui->statusbar, ui->doubleSpinBox_scale,
//                  ui->toolButton_scaleL, ui->toolButton_scaleH)

{
  ui->setupUi(this);

  movement_control_.SetupMovementControl(
      ui->widget, ui->statusbar, ui->doubleSpinBox_move_x,
      ui->doubleSpinBox_move_y, ui->doubleSpinBox_move_z);
  rotation_control_.SetupRotationControl(
      ui->widget, ui->statusbar, ui->spinBox_x, ui->spinBox_y, ui->spinBox_z,
      ui->dial_x, ui->dial_y, ui->dial_z);
  scaling_control_.SetupScalingControl(
      ui->widget, ui->statusbar, ui->doubleSpinBox_scale, ui->toolButton_scaleL,
      ui->toolButton_scaleH);

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

int MainWindow::load_file() {
  ui->statusbar->showMessage("Loading file...");
  int error_code = 0;
  QDir::currentPath();
  QString newFileName = QFileDialog::getOpenFileName(0, "Open", "", "*.obj");
  std::string str = newFileName.toStdString();
  char *c_string = ((char *)str.c_str());
  if (*c_string == 0) {
    error_code = 1;
    ui->statusbar->showMessage("File not selected");
  } else {
    DefaultControls();
    QString oldTitle = windowTitle(), separator = " @ ";
    QString oldFileName = *ui->widget->getObjFileName();
    if (oldFileName != "") {
      oldFileName = basename(oldFileName.toLocal8Bit().data());
      if (oldTitle.contains(oldFileName))
        oldTitle =
            oldTitle.remove(0, oldFileName.length() + separator.length());
    }
    int load_ok = ui->widget->loadFile(&newFileName);
    const obj_data *data = ui->widget->getObjData();
    QString numberOfEdges = QString::number(data->number_of_edges, 'g', 8);
    QString numberOfVertices = QString::number(data->number_of_vertex, 'g', 8);
    QString numberOfFaces = QString::number(data->number_of_facetes, 'g', 8);
    if (load_ok) {
      ui->statusbar->showMessage(
          "File: '" + newFileName + "', Edges: " + numberOfEdges +
          ", Vertexes: " + numberOfVertices + ", Faces: " + numberOfFaces);
      ui->actionModel_information->setEnabled(true);
      EnableControls(true);

      setWindowTitle(QString(basename(data->name_file)) + separator + oldTitle);
    } else {
      EnableControls(false);
      ui->statusbar->showMessage("Error loading file: '" + newFileName + "'");
      setWindowTitle(oldTitle);
    }
  }
  return error_code;
}

void MainWindow::on_actionOpen_OBJ_file_triggered() { load_file(); }

void MainWindow::on_actionModel_information_triggered() {
  Info info(nullptr, ui->widget->getObjData());
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

// movement_block
// TODO переместить в виде коннектов внутрь класса

void MainWindow::on_toolButton_xNeg_clicked() {
  movement_control_.MoveOnXAxis(movement_control_.kNegative);
}

void MainWindow::on_toolButton_xPos_clicked() {
  movement_control_.MoveOnXAxis(movement_control_.kPositive);
}

void MainWindow::on_toolButton_yNeg_clicked() {
  movement_control_.MoveOnYAxis(movement_control_.kNegative);
}

void MainWindow::on_toolButton_yPos_clicked() {
  movement_control_.MoveOnYAxis(movement_control_.kPositive);
}

void MainWindow::on_toolButton_zNeg_clicked() {
  movement_control_.MoveOnZAxis(movement_control_.kNegative);
}

void MainWindow::on_toolButton_zPos_clicked() {
  movement_control_.MoveOnZAxis(movement_control_.kPositive);
}

// rotation_block
// TODO переместить в виде коннектов внутрь класса

void MainWindow::on_dial_x_sliderMoved(int position) {
  rotation_control_.RotateAroundXAxis(position);
}

void MainWindow::on_dial_y_sliderMoved(int position) {
  rotation_control_.RotateAroundYAxis(position);
}

void MainWindow::on_dial_z_sliderMoved(int position) {
  rotation_control_.RotateAroundZAxis(position);
}

void MainWindow::on_dial_x_valueChanged(int value) {
  rotation_control_.RotateAroundXAxis(value);
}

void MainWindow::on_dial_y_valueChanged(int value) {
  rotation_control_.RotateAroundYAxis(value);
}

void MainWindow::on_dial_z_valueChanged(int value) {
  rotation_control_.RotateAroundZAxis(value);
}

void MainWindow::on_spinBox_x_editingFinished() {}

void MainWindow::on_spinBox_y_editingFinished() {}

void MainWindow::on_spinBox_z_editingFinished() {}

void MainWindow::on_spinBox_x_valueChanged(int arg1) {
  rotation_control_.RotateAroundXAxis(arg1);
}

void MainWindow::on_spinBox_y_valueChanged(int arg1) {
  rotation_control_.RotateAroundYAxis(arg1);
}

void MainWindow::on_spinBox_z_valueChanged(int arg1) {
  rotation_control_.RotateAroundZAxis(arg1);
}

// scale_block
// TODO переместить в виде коннектов внутрь класса

void MainWindow::on_pushButton_normalize_clicked() {
  scaling_control_.Normalize();
}

void MainWindow::on_pushButton_scale_clicked() {
  scaling_control_.UpdateScale();
}

void MainWindow::on_doubleSpinBox_scale_editingFinished() {
  scaling_control_.UpdateScale();
}

void MainWindow::on_toolButton_scaleL_clicked() {
  scaling_control_.ScaleDown();
}

void MainWindow::on_toolButton_scaleH_clicked() { scaling_control_.ScaleUp(); }
