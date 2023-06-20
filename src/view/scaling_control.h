#ifndef SCALING_CONTROL_H
#define SCALING_CONTROL_H

#include <QDoubleSpinBox>
#include <QObject>
#include <QPushButton>
#include <QStatusBar>
#include <QToolButton>
#include <QWidget>

#include "widget.h"

namespace s21 {

class Controller;
class ScalingControl : public QObject {
  Q_OBJECT
 public:
  ScalingControl() = default;
  void SetupScalingControl(void (Controller::*method)(double),
                           QDoubleSpinBox* scale_box, QPushButton* scale_button,
                           QToolButton* scale_down_button,
                           QToolButton* scale_up_button);
  void SetController(Controller& controller);
  void Default();

 private slots:
  void UpdateScale();
  void ScaleDown();
  void ScaleUp();

 private:
  void ApplyScale(double new_scale);
  void SetupConnections();
  Controller* controller_;
  void (Controller::*method_)(double);
  QDoubleSpinBox* scale_box_;
  QPushButton* scale_button_;
  QToolButton* scale_down_button_;
  QToolButton* scale_up_button_;
  double currect_scale_{100.0};
};

};  // namespace s21

#endif  // SCALING_CONTROL_H
