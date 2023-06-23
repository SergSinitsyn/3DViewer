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

void MainWindow::CreateRecentFilesMenu() {
  const auto recent_files = settings_.GetRecentFiles();
  if (!recent_files->empty()) {
    recent_files_menu_ = ui_->menuFile->addMenu("Recent files");
    for (const auto &file : *recent_files) {
      auto action = recent_files_menu_->addAction(file);
      connect(action, &QAction::triggered, this, &MainWindow::LoadRecentFile);
    }
  }
}

void MainWindow::RemoveRecentFilesMenu() {
  if (recent_files_menu_)
    ui_->menuFile->removeAction(recent_files_menu_->menuAction());
}

void MainWindow::UpdateRecentFilesMenu() {
  RemoveRecentFilesMenu();
  CreateRecentFilesMenu();
}

void MainWindow::SetActualSettingsMenu() {
  switch (settings_.projection()) {
    case kParallel:
      ui_->actionParallel->setChecked(true);
      break;
    case kCentral:
      ui_->actionCentral->setChecked(true);
      break;
    default:
      ui_->actionCentral->setChecked(true);
      break;
  }
  switch (settings_.lineType()) {
    case kSolid:
      ui_->actionSolid->setChecked(true);
      break;
    case kDashed:
      ui_->actionDashed->setChecked(true);
      break;
    default:
      ui_->actionDashed->setChecked(true);
      break;
  }
  switch (settings_.displayVertexes()) {
    case kNone:
      ui_->actionNone->setChecked(true);
      break;
    case kCircle:
      ui_->actionCircle->setChecked(true);
      break;
    case kSquare:
      ui_->actionSquare->setChecked(true);
      break;
    default:
      ui_->actionSquare->setChecked(true);
      break;
  }
}

void MainWindow::SetupRadioButtons() {
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
  SetActualSettingsMenu();
}

}  // namespace s21
