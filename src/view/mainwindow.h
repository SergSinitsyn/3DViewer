#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "../other/structs.h"
#include "gifanim/gifanim.h"
#include "movement_control.h"
#include "rotation_control.h"
#include "scaling_control.h"
#include "widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class Controller;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void SetController(Controller &controller);
  void SetModelData(const std::vector<double> &vertices,
                    const std::vector<int> &edges);
  void SetModelInformation(const ModelInformation &information);
  void UpdateWidget();

 private slots:
  void on_actionOpen_OBJ_file_triggered();
  void on_actionModel_information_triggered();
  void on_actionOpen_documentation_triggered();

  // settings  //TODO перенести в отдельный класс?
  void on_actionColor_edges_triggered();
  void on_actionColor_vertices_triggered();
  void on_actionBackground_color_triggered();
  void on_actionThickness_triggered();
  void on_actionSize_triggered();
  void on_actionNone_triggered(bool checked);
  void on_actionCircle_triggered(bool checked);
  void on_actionSquare_triggered(bool checked);
  void on_actionSolid_triggered(bool checked);
  void on_actionDashed_triggered(bool checked);
  void on_actionParallel_triggered(bool checked);
  void on_actionCentral_triggered(bool checked);
  void on_actionRestore_settings_triggered();
  void LoadSettingFromFile();
  void SaveSettingToFile();
  void SetupRadioButtons();
  void CreateRecentFilesMenu();
  void RemoveRecentFilesMenu();
  int LoadRecentFile();
  int FileNameErrorDialog(const char *msg);

  // screenshot
  void on_actionSave_OBJ_to_Image_triggered();
  void on_pushButton_image_clicked();
  void on_pushButton_record_clicked();
  void SaveImageAs();       //!
  void RecordTimerAlarm();  //!

 signals:
  void SettingsChanged(WidgetSettings *);

 private:
  void DefaultControls();
  void EnableControls(bool enable);
  void LoadFile();
  void SetupControls();
  void ShowInformation();

  Ui::MainWindow *ui_;
  ModelData model_data_;
  ModelInformation model_information_;
  MovementControl movement_control_;
  RotationControl rotation_control_;
  ScalingControl scaling_control_;
  Controller *controller_;
  const QString window_title_ = "3D Viewer v2.0 - Old Perrers Team";

  // Settings variables
  QMenu *recent_files_menu_ = nullptr;
  WidgetSettings settings_;
  Memento<WidgetSettings> *start_settindgs_;

  // video recording variables
  bool record_ = false;
  QTimer record_timer_;
  int frames_;
  QString gif_file_name_;
  GifAnim ganim_;
  GifWriter gwriter_;
};

}  // namespace s21

#endif  // MAINWINDOW_H
