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

  Controller *controller_;

  void setAppPath(QString path) { appPath = path; };  // to google-style
  const QString *getAppPath() { return &appPath; };   // to google-style

 private slots:

  void SetupControls();

  // main
  void LoadFile();
  void on_actionOpen_OBJ_file_triggered();
  void on_actionModel_information_triggered();
  void DefaultControls();
  void EnableControls(bool enable);
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

  void load_setting_from_file();             // to google-style
  void save_setting_to_file();               // to google-style
  void setupRadiobuttons();                  // to google-style
  int fileNameErrorDialog(const char *msg);  // to google-style

  // screenshot
  void saveImageAs();
  void on_actionSave_OBJ_to_Image_triggered();
  void on_pushButton_image_clicked();
  void on_pushButton_record_clicked();
  void recordTimerAlarm();

  //

 signals:
  void settingsChanged(widgetSettings *);  // to google-style

 private:
  Ui::MainWindow *ui;  // TODO заменить все на ui_

  MovementControl movement_control_;
  RotationControl rotation_control_;
  ScalingControl scaling_control_;
  ModelInformation model_information_;
  ModelData model_data_;

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
