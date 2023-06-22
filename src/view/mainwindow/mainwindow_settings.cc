#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QSettings>

#include "../info/info.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

// Template Method pattern
template <class T>
void MainWindow::SetSetting(void (WidgetSettings::*SetMetod)(const T &),
                            const T &value) {
  (settings_.*SetMetod)(value);
  emit SettingsChanged(&settings_);
}

void MainWindow::on_actionColor_edges_triggered() {
  QColor color = QColorDialog::getColor(settings_.edgeColor(), this,
                                        "Choose color for edges");
  if (color.isValid()) SetSetting<QColor>(&WidgetSettings::setEdgeColor, color);
}

void MainWindow::on_actionColor_vertices_triggered() {
  QColor color = QColorDialog::getColor(settings_.vertexColor(), this,
                                        "Choose color for vertices");
  if (color.isValid())
    SetSetting<QColor>(&WidgetSettings::setVertexColor, color);
}

void MainWindow::on_actionBackground_color_triggered() {
  QColor color = QColorDialog::getColor(settings_.backgroundColor(), this,
                                        "Choose background color");
  if (color.isValid())
    SetSetting<QColor>(&WidgetSettings::setBackgroundColor, color);
}

void MainWindow::on_actionThickness_triggered() {
  bool is_ok;
  const int current_edge_thickness = settings_.edgeThickness();
  int edge_thickness = QInputDialog::getInt(
      this, kSettingsTitle, kEdgeThicknessMessage, current_edge_thickness,
      kMinDrawingSize, kMaxDrawingSize, kDrawingSizeStep, &is_ok);
  if (is_ok) SetSetting<int>(&WidgetSettings::setEdgeThickness, edge_thickness);
}

void MainWindow::on_actionSize_triggered() {
  const int current_vertex_size = settings_.vertexSize();
  bool ok;
  const int new_vertex_size = QInputDialog::getInt(
      this, kSettingsTitle, kVertexSizeMessage, current_vertex_size,
      kMinDrawingSize, kMaxDrawingSize, kDrawingSizeStep, &ok);
  if (ok) SetSetting<int>(&WidgetSettings::setVertexSize, new_vertex_size);
}

void MainWindow::LoadSettingFromFile() {
  settings_.LoadSettingsFromFile();
  emit SettingsChanged(&settings_);
}

void MainWindow::SaveSettingToFile() { settings_.SaveSettingsToFile(); }

void MainWindow::on_actionNone_triggered(bool checked) {
  SetSetting<DisplayMethod>(&WidgetSettings::setDisplayVertexes, kNone);
}
void MainWindow::on_actionCircle_triggered(bool checked) {
  SetSetting<DisplayMethod>(&WidgetSettings::setDisplayVertexes, kCircle);
}
void MainWindow::on_actionSquare_triggered(bool checked) {
  SetSetting<DisplayMethod>(&WidgetSettings::setDisplayVertexes, kSquare);
}
void MainWindow::on_actionSolid_triggered(bool checked) {
  SetSetting<LineType>(&WidgetSettings::setLineType, kSolid);
}
void MainWindow::on_actionDashed_triggered(bool checked) {
  SetSetting<LineType>(&WidgetSettings::setLineType, kDashed);
}
void MainWindow::on_actionParallel_triggered(bool checked) {
  SetSetting<ProjectionType>(&WidgetSettings::setProjection, kParallel);
}
void MainWindow::on_actionCentral_triggered(bool checked) {
  SetSetting<ProjectionType>(&WidgetSettings::setProjection, kCentral);
}

void MainWindow::on_actionRestore_settings_triggered() {
  settings_ = *start_settindgs_->GetState();
  SetActualSettingsMenu();
  emit SettingsChanged(&settings_);
}

}  // namespace s21
