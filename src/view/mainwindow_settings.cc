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
  QColor c = QColorDialog::getColor(settings_.edgeColor(), this,
                                    "Choose color for edges");
  if (c.isValid()) {
    settings_.edgeColor() = c;
    emit SettingsChanged(&settings_);
  }
}

void MainWindow::on_actionColor_vertices_triggered() {
  QColor c = QColorDialog::getColor(settings_.vertexColor(), this,
                                    "Choose color for vertices");
  if (c.isValid()) {
    settings_.vertexColor() = c;
    emit SettingsChanged(&settings_);
  }
}

void MainWindow::on_actionBackground_color_triggered() {
  QColor c = QColorDialog::getColor(settings_.backgroundColor(), this,
                                    "Choose background color");
  if (c.isValid()) {
    settings_.backgroundColor() = c;
    emit SettingsChanged(&settings_);
  }
}

void MainWindow::on_actionThickness_triggered() {
  bool ok;
  int i = QInputDialog::getInt(this, "Settings", "Thickness of the edges",
                               settings_.edgeThickness(), 1, 10, 1, &ok);
  if (ok) {
    settings_.edgeThickness() = i;
    emit SettingsChanged(&settings_);
  }
}

void MainWindow::on_actionSize_triggered() {
  bool ok;
  int i = QInputDialog::getInt(this, "Settings", "Size of the vertices",
                               settings_.vertexSize(), 1, 10, 1, &ok);
  if (ok) {
    settings_.vertexSize() = i;
    emit SettingsChanged(&settings_);
  }
}

void MainWindow::LoadSettingFromFile() {
  settings_.LoadSettingsFromFile();
  emit SettingsChanged(&settings_);
}

void MainWindow::SaveSettingToFile() { settings_.SaveSettingsToFile(); }

void MainWindow::on_actionNone_triggered(bool checked) {
  if (checked) {
    settings_.displayVertexes() = kNone;
  }
  emit SettingsChanged(&settings_);
}
void MainWindow::on_actionCircle_triggered(bool checked) {
  if (checked) {
    settings_.displayVertexes() = kCircle;
  }
  emit SettingsChanged(&settings_);
}
void MainWindow::on_actionSquare_triggered(bool checked) {
  if (checked) {
    settings_.displayVertexes() = kSquare;
  }
  emit SettingsChanged(&settings_);
}
void MainWindow::on_actionSolid_triggered(bool checked) {
  if (checked) {
    settings_.lineType() = kSolid;
  }
  emit SettingsChanged(&settings_);
}
void MainWindow::on_actionDashed_triggered(bool checked) {
  if (checked) {
    settings_.lineType() = kDashed;
  }
  emit SettingsChanged(&settings_);
}
void MainWindow::on_actionParallel_triggered(bool checked) {
  if (checked) {
    settings_.projection() = kParallel;
  }
  emit SettingsChanged(&settings_);
}
void MainWindow::on_actionCentral_triggered(bool checked) {
  if (checked) {
    settings_.projection() = kCentral;
  }
  emit SettingsChanged(&settings_);
}

void MainWindow::on_actionRestore_settings_triggered() {
  settings_ = *start_settindgs_->GetState();
  emit SettingsChanged(&settings_);
}

};  // namespace s21
