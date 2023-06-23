#ifndef VIEWER_2_VIEW_MAINWINDOW_MAINWINDOW_H_
#define VIEWER_2_VIEW_MAINWINDOW_MAINWINDOW_H_

#include <QMainWindow>
#include <QTimer>

#include "../../other/memento.h"
#include "../../other/structs.h"
#include "../controls/movement_control.h"
#include "../controls/rotation_control.h"
#include "../controls/scaling_control.h"
#include "../gifanim/gifanim.h"
#include "../widget/widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void SetController(Controller &controller);
  void SetModelData(const std::vector<double> &vertices,
                    const std::vector<int> &edges);
  void SetModelInformation(const ModelInformation &information);
  void UpdateWidget();

 private:
  void DefaultControls();
  void EnableControls(bool enable);
  void LoadFile();
  void SetupControls();
  void ShowInformation();
  void InformationWidget();

  Ui::MainWindow *ui_;
  ModelData model_data_;
  ModelInformation model_information_;
  MovementControl movement_control_x_;
  MovementControl movement_control_y_;
  MovementControl movement_control_z_;
  RotationControl rotation_control_x_;
  RotationControl rotation_control_y_;
  RotationControl rotation_control_z_;
  ScalingControl scaling_control_;
  Controller *controller_;
  const QString window_title_ = "3D Viewer v2.0 - Old Perrers Team";

  // Settings variables
  template <class T>
  void SetSetting(void (WidgetSettings::*SetMetod)(const T &), const T &value);
  const QString kSettingsTitle = "Settings";
  const QString kVertexSizeMessage = "Size of the vertices";
  const QString kEdgeThicknessMessage = "Thickness of the edges";
  const int kMinDrawingSize = 1;
  const int kMaxDrawingSize = 10;
  const int kDrawingSizeStep = 1;
  QMenu *recent_files_menu_ = nullptr;
  WidgetSettings settings_;
  Memento<WidgetSettings> *start_settindgs_ = nullptr;

  // Video recording variables
  const int kCancelScreenCast = -1;
  const int kRetryScreenCast = 0;
  const int kEndScreenCast = 0;
  const int kMaxFrames = 50;
  bool start_recording_ = false;
  QTimer record_timer_;
  int frames_;
  QString gif_file_name_;
  GifAnim ganim_;
  GifWriter gwriter_;

 private slots:
  void on_actionOpen_OBJ_file_triggered();
  void on_actionModel_information_triggered();
  void on_actionOpen_documentation_triggered();
  void on_undoButton_clicked();
  void on_pushButton_model_info_clicked();

  // Settings
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
  void SetActualSettingsMenu();
  void CreateRecentFilesMenu();
  void RemoveRecentFilesMenu();
  void UpdateRecentFilesMenu();
  int LoadRecentFile();
  int FileNameErrorDialog(const char *msg);

  // Screenshot
  int ValidateGifFilename();
  void on_actionSave_OBJ_to_Image_triggered();
  void on_pushButton_image_clicked();
  void on_pushButton_record_clicked();

  void SaveImageAs();
  void RecordTimerAlarm();

 signals:
  void SettingsChanged(WidgetSettings *);
};

}  // namespace s21

#endif  // VIEWER_2_VIEW_MAINWINDOW_MAINWINDOW_H_
