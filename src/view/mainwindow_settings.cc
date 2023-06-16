#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QSettings>

#include "info/info.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

void MainWindow::on_actionColor_edges_triggered() {
  QColor c = QColorDialog::getColor(settings.edgeColor(), this,
                                    "Choose color for edges");
  if (c.isValid()) {
    settings.edgeColor() = c;
    ui_->statusbar->showMessage("correct color");
    emit settingsChanged(&settings);
  }
}

void MainWindow::on_actionColor_vertices_triggered() {
  QColor c = QColorDialog::getColor(settings.vertexColor(), this,
                                    "Choose color for vertices");
  if (c.isValid()) {
    settings.vertexColor() = c;
    ui_->statusbar->showMessage("correct color");
    emit settingsChanged(&settings);
  }
}

void MainWindow::on_actionBackground_color_triggered() {
  QColor c = QColorDialog::getColor(settings.backgroundColor(), this,
                                    "Choose background color");
  if (c.isValid()) {
    settings.backgroundColor() = c;
    ui_->statusbar->showMessage("correct color");
    emit settingsChanged(&settings);
  }
}

void MainWindow::on_actionThickness_triggered() {
  bool ok;
  int i = QInputDialog::getInt(this, "Settings", "Thickness of the edges",
                               settings.edgeThickness(), 1, 10, 1, &ok);
  if (ok) {
    settings.edgeThickness() = i;
    emit settingsChanged(&settings);
  }
}

void MainWindow::on_actionSize_triggered() {
  bool ok;
  int i = QInputDialog::getInt(this, "Settings", "Size of the vertices",
                               settings.vertexSize(), 1, 10, 1, &ok);
  if (ok) {
    settings.vertexSize() = i;
    emit settingsChanged(&settings);
  }
}

void MainWindow::load_setting_from_file() {
  settings.loadSettingsFromFile();
  emit settingsChanged(&settings);
}

void MainWindow::save_setting_to_file() { settings.saveSettingsToFile(); }

void MainWindow::on_actionNone_triggered(bool checked) {
  if (checked) {
    settings.displayVertexes() = kNone;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionCircle_triggered(bool checked) {
  if (checked) {
    settings.displayVertexes() = kCircle;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionSquare_triggered(bool checked) {
  if (checked) {
    settings.displayVertexes() = kSquare;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionSolid_triggered(bool checked) {
  if (checked) {
    settings.lineType() = kSolid;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionDashed_triggered(bool checked) {
  if (checked) {
    settings.lineType() = kDashed;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionParallel_triggered(bool checked) {
  if (checked) {
    settings.projection() = kParallel;
  }
  emit settingsChanged(&settings);
}
void MainWindow::on_actionCentral_triggered(bool checked) {
  if (checked) {
    settings.projection() = kCentral;
  }
  emit settingsChanged(&settings);
}

void MainWindow::on_actionRestore_settings_triggered() {
  settings = *start_settindgs_->GetState();
  emit settingsChanged(&settings);
}

};  // namespace s21
