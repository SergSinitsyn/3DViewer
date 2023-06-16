#include "rotation_control.h"

#include <functional>

#include "../controller/controller.h"

namespace s21 {

RotationControl::RotationControl(){};

RotationControl::RotationControl(QSpinBox* box, QDial* dial)
    : box_(box), dial_(dial) {
  SetupConnections();
}

void RotationControl::SetupRotationControl(void (Controller::*method)(int),
                                           QSpinBox* box, QDial* dial) {
  method_ = method;
  box_ = box;
  dial_ = dial;
  current_angle_ = 0;
  SetupConnections();
}

void RotationControl::SetupConnections() {
  connect(box_, SIGNAL(valueChanged(int)), this, SLOT(RotateAroundAxis(int)));
  connect(dial_, SIGNAL(valueChanged(int)), this, SLOT(RotateAroundAxis(int)));
  connect(dial_, SIGNAL(sliderMoved(int)), this, SLOT(RotateAroundAxis(int)));
}

void RotationControl::SetController(Controller& controller) {
  controller_ = &controller;
}

void RotationControl::RotateAroundAxis(int new_angle) {
  box_->blockSignals(true);
  dial_->blockSignals(true);

  (controller_->*method_)(new_angle - current_angle_);
  current_angle_ = new_angle;
  box_->setValue(current_angle_);
  dial_->setValue(current_angle_);

  box_->blockSignals(false);
  dial_->blockSignals(false);
}

};  // namespace s21
