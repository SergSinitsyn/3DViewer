#include "scaling_control.h"

#include "../../controller/controller.h"

namespace s21 {

void ScalingControl::SetupScalingControl(void (Controller::*method)(double),
                                         QDoubleSpinBox* scale_box,
                                         QPushButton* scale_button,
                                         QToolButton* scale_down_button,
                                         QToolButton* scale_up_button) {
  method_ = method;
  scale_box_ = scale_box;
  scale_button_ = scale_button;
  scale_down_button_ = scale_down_button;
  scale_up_button_ = scale_up_button;
  SetupConnections();
}

void ScalingControl::SetupConnections() {
  connect(scale_box_, SIGNAL(editingFinished()), this, SLOT(UpdateScale()));
  connect(scale_button_, SIGNAL(clicked()), this, SLOT(UpdateScale()));
  connect(scale_down_button_, SIGNAL(clicked()), this, SLOT(ScaleDown()));
  connect(scale_up_button_, SIGNAL(clicked()), this, SLOT(ScaleUp()));
}

void ScalingControl::SetController(Controller& controller) {
  controller_ = &controller;
}

void ScalingControl::Default() {
  scale_box_->blockSignals(true);
  scale_box_->setValue(100.0);
  currect_scale_ = 100.0;
  scale_box_->blockSignals(false);
}

void ScalingControl::UpdateScale() { ApplyScale(scale_box_->value()); }

void ScalingControl::ScaleDown() {
  scale_box_->blockSignals(true);
  scale_box_->stepDown();
  ApplyScale(scale_box_->value());
  scale_box_->blockSignals(false);
}

void ScalingControl::ScaleUp() {
  scale_box_->blockSignals(true);
  scale_box_->stepUp();
  ApplyScale(scale_box_->value());
  scale_box_->blockSignals(false);
}

void ScalingControl::ApplyScale(double new_scale) {
  scale_box_->blockSignals(true);
  (controller_->*method_)(new_scale / currect_scale_);
  currect_scale_ = new_scale;
  scale_box_->setValue(currect_scale_);
  scale_box_->blockSignals(false);
}

};  // namespace s21
