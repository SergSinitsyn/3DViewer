#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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

class Controller;
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void SetController(Controller &controller);

  Controller *controller_;

  void setAppPath(QString path) { appPath = path; };
  const QString *getAppPath() { return &appPath; };

  // !это пример
  // void HandleButtonClick() {
  //   int newData = 0 /* Получить новые данные */;
  //   controller->SetData(newData);
  // }

 private slots:

  void SetupControls();

  // main
  int load_file();
  void on_actionOpen_OBJ_file_triggered();
  void on_actionModel_information_triggered();
  void DefaultControls();
  void EnableControls(bool enable);
  void on_actionOpen_documentation_triggered();

  void on_pushButton_normalize_clicked();

  // settings
  void on_actionColor_edges_triggered();
  void on_actionColor_vertices_triggered();
  void on_actionBackground_color_triggered();
  void on_actionThickness_triggered();
  void on_actionSize_triggered();
  void load_setting_from_file();
  void save_setting_to_file();
  void on_actionNone_triggered(bool checked);
  void on_actionCircle_triggered(bool checked);
  void on_actionSquare_triggered(bool checked);
  void on_actionSolid_triggered(bool checked);
  void on_actionDashed_triggered(bool checked);
  void on_actionParallel_triggered(bool checked);
  void on_actionCentral_triggered(bool checked);
  void setupRadiobuttons();
  int fileNameErrorDialog(const char *msg);

  // screenshot
  void saveImageAs();
  void on_actionSave_OBJ_to_Image_triggered();
  void on_pushButton_image_clicked();
  void on_pushButton_record_clicked();
  void recordTimerAlarm();

  //

 signals:
  void settingsChanged(widgetSettings *);

 private:
  Ui::MainWindow *ui;

  MovementControl movement_control_;
  RotationControl rotation_control_;
  ScalingControl scaling_control_;

  widgetSettings settings;

  // video recording variables
  bool record = false;
  QTimer recordTimer;
  int frames;
  QString gifFileName;
  GifAnim ganim;
  GifWriter gwriter;
  QString appPath;
};
#endif  // MAINWINDOW_H
