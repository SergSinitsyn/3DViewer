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
  QColor color = QColorDialog::getColor(settings_.edgeColor(), this,
                                        "Choose color for edges");
  if (color.isValid()) {
    settings_.setEdgeColor(color);
    emit SettingsChanged(&settings_);
  }
}

void MainWindow::on_actionColor_vertices_triggered() {
  QColor vertex_color = QColorDialog::getColor(settings_.vertexColor(), this,
                                               "Choose color for vertices");
  if (vertex_color.isValid()) {
    settings_.setVertexColor(vertex_color);
    emit SettingsChanged(&settings_);
  }
}

void MainWindow::on_actionBackground_color_triggered() {
  QColor color = QColorDialog::getColor(settings_.backgroundColor(), this,
                                        "Choose background color");
  if (color.isValid()) {
    settings_.setBackgroundColor(color);
    emit SettingsChanged(&settings_);
  }
}

void MainWindow::on_actionThickness_triggered() {
  bool is_ok;
  const int default_edge_thickness = settings_.edgeThickness();

  int edge_thickness = QInputDialog::getInt(
      this, kSettingsTitle, kEdgeThicknessMessage, default_edge_thickness,
      kMinDrawingSize, kMaxDrawingSize, kDrawingSizeStep, &is_ok);
  if (is_ok) {
    settings_.setEdgeThickness(edge_thickness);
    emit SettingsChanged(&settings_);
  }
}

void MainWindow::on_actionSize_triggered() {
  const int currentVertexSize = settings_.vertexSize();
  bool ok;
  const int newVertexSize = QInputDialog::getInt(
      this, kSettingsTitle, kVertexSizeMessage, currentVertexSize,
      kMinDrawingSize, kMaxDrawingSize, kDrawingSizeStep, &ok);
  if (ok) {
    settings_.setVertexSize(newVertexSize);
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
    settings_.setDisplayVertexes(kNone);
    emit SettingsChanged(&settings_);
  }
}
void MainWindow::on_actionCircle_triggered(bool checked) {
  if (checked) {
    settings_.setDisplayVertexes(kCircle);
    emit SettingsChanged(&settings_);
  }
}
void MainWindow::on_actionSquare_triggered(bool checked) {
  if (checked) {
    settings_.setDisplayVertexes(kSquare);
    emit SettingsChanged(&settings_);
  }
}
void MainWindow::on_actionSolid_triggered(bool checked) {
  if (checked) {
    settings_.setLineType(kSolid);
    emit SettingsChanged(&settings_);
  }
}
void MainWindow::on_actionDashed_triggered(bool checked) {
  if (checked) {
    settings_.setLineType(kDashed);
    emit SettingsChanged(&settings_);
  }
}
void MainWindow::on_actionParallel_triggered(bool checked) {
  if (checked) {
    settings_.setProjection(kParallel);
    emit SettingsChanged(&settings_);
  }
}
void MainWindow::on_actionCentral_triggered(bool checked) {
  if (checked) {
    settings_.setProjection(kCentral);
    emit SettingsChanged(&settings_);
  }
}

void MainWindow::on_actionRestore_settings_triggered() {
  settings_ = *start_settindgs_->GetState();
  emit SettingsChanged(&settings_);
}

};  // namespace s21
