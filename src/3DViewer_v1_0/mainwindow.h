#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "gifanim/gifanim.h"
#include "widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void setAppPath(QString path) { appPath = path; };
  const QString *getAppPath() { return &appPath; };

 private slots:

  // main
  int load_file();
  void on_actionOpen_OBJ_file_triggered();
  void on_actionModel_information_triggered();
  void defaultControls();
  void enableControls(int enable);
  void on_actionOpen_documentation_triggered();

  // rotate
  void on_dial_x_sliderMoved(int position);
  void on_dial_y_sliderMoved(int position);
  void on_dial_z_sliderMoved(int position);
  void on_spinBox_x_editingFinished();
  void on_spinBox_y_editingFinished();
  void on_spinBox_z_editingFinished();
  void rotate_x(int x);
  void rotate_y(int y);
  void rotate_z(int z);
  void on_dial_x_valueChanged(int value);
  void on_dial_y_valueChanged(int value);
  void on_dial_z_valueChanged(int value);

  // scale
  void on_pushButton_scale_clicked();
  void on_pushButton_normalize_clicked();
  void on_doubleSpinBox_scale_editingFinished();
  void on_toolButton_scaleL_clicked();
  void on_toolButton_scaleH_clicked();
  void newScale(double newValue);

  // move
  void on_toolButton_xNeg_clicked();
  void on_toolButton_xPos_clicked();
  void on_toolButton_yNeg_clicked();
  void on_toolButton_yPos_clicked();
  void on_toolButton_zNeg_clicked();
  void on_toolButton_zPos_clicked();

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
  widgetSettings settings;
  double old_scale = 100;
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
