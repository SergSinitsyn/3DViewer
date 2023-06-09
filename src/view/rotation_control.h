#ifndef ROTATION_CONTROL_H
#define ROTATION_CONTROL_H

#include <QAbstractSlider>
#include <QDial>
#include <QSpinBox>
#include <QStatusBar>
#include <QString>

#include "widget.h"

class Controller;
class RotationControl : public QObject {
  Q_OBJECT
 public:
  RotationControl();
  RotationControl(QStatusBar *status_bar, QSpinBox *x_box, QSpinBox *y_box,
                  QSpinBox *z_box, QDial *x_dial, QDial *y_dial, QDial *z_dial);

  void SetupRotationControl(QStatusBar *status_bar, QSpinBox *x_box,
                            QSpinBox *y_box, QSpinBox *z_box, QDial *x_dial,
                            QDial *y_dial, QDial *z_dial);
  void SetController(Controller &controller);

 public slots:
  void RotateAroundXAxis(int position);
  void RotateAroundYAxis(int position);
  void RotateAroundZAxis(int position);

 private:
  void SetupConnections();
  Controller *controller_;
  QStatusBar *status_bar_;

  int current_x_angle_ = 0;
  int current_y_angle_ = 0;
  int current_z_angle_ = 0;

  QSpinBox *x_box_;
  QSpinBox *y_box_;
  QSpinBox *z_box_;
  QDial *x_dial_;
  QDial *y_dial_;
  QDial *z_dial_;
};

#endif  // ROTATION_CONTROL_H
