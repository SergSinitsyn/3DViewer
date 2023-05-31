#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QSettings>

#include "info/info.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_actionColor_edges_triggered() {
  QColor c = QColorDialog::getColor(settings.edgeColor, this,
                                    "Choose color for edges");
  if (c.isValid()) {
    settings.edgeColor = c;
    ui->statusbar->showMessage("correct color");
    emit settingsChanged(&settings);
  }
}

void MainWindow::on_actionColor_vertices_triggered() {
  QColor c = QColorDialog::getColor(settings.vertexColor, this,
                                    "Choose color for vertices");
  if (c.isValid()) {
    settings.vertexColor = c;
    ui->statusbar->showMessage("correct color");
    emit settingsChanged(&settings);
  }
}

void MainWindow::on_actionBackground_color_triggered() {
  QColor c = QColorDialog::getColor(settings.backgroundColor, this,
                                    "Choose background color");
  if (c.isValid()) {
    settings.backgroundColor = c;
    ui->statusbar->showMessage("correct color");
    emit settingsChanged(&settings);
  }
}

void MainWindow::on_actionThickness_triggered() {
  bool ok;
  int i = QInputDialog::getInt(this, "Settings", "Thickness of the edges",
                               settings.edgeThickness, 1, 10, 1, &ok);
  if (ok) {
    settings.edgeThickness = i;
    emit settingsChanged(&settings);
  }
}

void MainWindow::on_actionSize_triggered() {
  bool ok;
  int i = QInputDialog::getInt(this, "Settings", "Size of the vertices",
                               settings.vertexSize, 1, 10, 1, &ok);
  if (ok) {
    settings.vertexSize = i;
    emit settingsChanged(&settings);
  }
}

void MainWindow::load_setting_from_file() {
  QSettings settingsFile(appPath + "/viewer_settings.conf",
                         QSettings::IniFormat);
  qDebug() << appPath;
  settingsFile.beginGroup("WidgetParameters");
  settings.edgeThickness = settingsFile.value("edgeThickness", 1).toInt();
  settings.vertexSize = settingsFile.value("vertexSize", 1).toInt();
  settings.displayVertexes =
      (Display_method)settingsFile.value("displayMethod", CIRCLE).toInt();
  settings.projection =
      (Projection_type)settingsFile.value("projectionType", CENTRAL).toInt();
  settings.line = (Line_type)settingsFile.value("lineType", SOLID).toInt();
  settings.backgroundColor =
      settingsFile.value("backgroundColor", QColor(Qt::yellow)).value<QColor>();
  settings.vertexColor =
      settingsFile.value("vertexColor", QColor(Qt::black)).value<QColor>();
  settings.edgeColor =
      settingsFile.value("edgeColor", QColor(Qt::red)).value<QColor>();
  settingsFile.endGroup();
  emit settingsChanged(&settings);
}

void MainWindow::save_setting_to_file() {
  QSettings settingsFile(appPath + "/viewer_settings.conf",
                         QSettings::IniFormat);
  qDebug() << appPath + "/viewer_settings.conf";
  settingsFile.beginGroup("WidgetParameters");
  settingsFile.setValue("edgeThickness", settings.edgeThickness);
  settingsFile.setValue("vertexSize", settings.vertexSize);
  settingsFile.setValue("displayMethod", settings.displayVertexes);
  settingsFile.setValue("projectionType", settings.projection);
  settingsFile.setValue("lineType", settings.line);

  if (settings.backgroundColor.isValid()) {
    settingsFile.setValue("backgroundColor", settings.backgroundColor);
    ui->statusbar->showMessage("backgroundColor setting stored");
  }
  if (settings.vertexColor.isValid()) {
    settingsFile.setValue("vertexColor", settings.vertexColor);
    ui->statusbar->showMessage("Vertex color setting stored");
  }
  if (settings.edgeColor.isValid()) {
    settingsFile.setValue("edgeColor", settings.edgeColor);
    ui->statusbar->showMessage("edgeColor setting stored");
  }
  settingsFile.endGroup();
}

void MainWindow::on_actionNone_triggered(bool checked) {
  if (checked) {
    settings.displayVertexes = NONE;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionCircle_triggered(bool checked) {
  if (checked) {
    settings.displayVertexes = CIRCLE;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionSquare_triggered(bool checked) {
  if (checked) {
    settings.displayVertexes = SQUARE;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionSolid_triggered(bool checked) {
  if (checked) {
    settings.line = SOLID;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionDashed_triggered(bool checked) {
  if (checked) {
    settings.line = DASHED;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionParallel_triggered(bool checked) {
  if (checked) {
    settings.projection = PARALLEL;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionCentral_triggered(bool checked) {
  if (checked) {
    settings.projection = CENTRAL;
  }
  emit settingsChanged(&settings);
}
