#include "scaling_control.h"

#include "../controller/controller.h"

namespace s21 {

void ScalingControl::SetupScalingControl(QStatusBar* status_bar,
                                         QDoubleSpinBox* scale_box,
                                         QPushButton* scale_button,
                                         QToolButton* scale_down_button,
                                         QToolButton* scale_up_button) {
  status_bar_ = status_bar;
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
  double scale_factor = new_scale / currect_scale_;
  currect_scale_ = new_scale;

  controller_->Scaling(scale_factor);
  // widget_->update();

  scale_box_->setValue(currect_scale_);
  status_bar_->showMessage(QString("scale on: %1").arg(scale_factor));
  scale_box_->blockSignals(false);
}

};  // namespace s21
