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

#include "info.h"
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
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QString path = QCoreApplication::applicationDirPath();
  setAppPath(path);
  load_setting_from_file();
  setupRadiobuttons();
  MainWindow::defaultControls();
  MainWindow::enableControls(0);
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
    defaultControls();
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
      enableControls(1);

      setWindowTitle(QString(basename(data->name_file)) + separator + oldTitle);
    } else {
      enableControls(0);
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

void MainWindow::defaultControls() {
  ui->dial_x->setValue(0);
  ui->dial_y->setValue(0);
  ui->dial_z->setValue(0);
  ui->doubleSpinBox_move_x->setValue(0.05);
  ui->doubleSpinBox_move_y->setValue(0.05);
  ui->doubleSpinBox_move_z->setValue(0.05);
  ui->doubleSpinBox_scale->setValue(100);
  old_scale = 100;
  ui->widget->height();
  ui->widget->width();
  ui->actionModel_information->setEnabled(false);
}

void MainWindow::enableControls(int enable) {
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
