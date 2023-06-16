#ifndef ROTATION_CONTROL_H
#define ROTATION_CONTROL_H

#include <QAbstractSlider>
#include <QDial>
#include <QSpinBox>
#include <QStatusBar>
#include <QString>

#include "widget.h"

namespace s21 {

class Controller;
class RotationControl : public QObject {
  Q_OBJECT

 public:
  RotationControl();
  RotationControl(QSpinBox *box, QDial *dial);
  void SetupRotationControl(void (Controller::*method)(int), QSpinBox *box,
                            QDial *dial);
  void SetController(Controller &controller);

 private slots:
  void RotateAroundAxis(int new_angle);

 private:
  void SetupConnections();
  Controller *controller_;
  void (Controller::*method_)(int);
  QSpinBox *box_;
  QDial *dial_;
  int current_angle_{0};
};

};  // namespace s21

#endif  // ROTATION_CONTROL_H
