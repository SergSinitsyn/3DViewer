#include "scaling_control.h"

void ScalingControl::SetupScalingControl(Widget* widget, QStatusBar* status_bar,
                                         QDoubleSpinBox* scale_box,
                                         QToolButton* scale_down_button,
                                         QToolButton* scale_up_button) {
  widget_ = widget;
  status_bar_ = status_bar;
  scale_box_ = scale_box;
  scale_down_button_ = scale_down_button;
  scale_up_button_ = scale_up_button;
  SetupConnections();
}

void ScalingControl::SetupConnections() {
  //    connect(scale_box_, SIGNAL(editingFinished()), this,
  //                            SLOT(Scale()));
  //  connect(scale_down_button_, SIGNAL(clicked()), this, SLOT(ScaleDown()));
  //  connect(scale_up_button_, SIGNAL(clicked()), this, SLOT(ScaleUp()));
}

void ScalingControl::Normalize() {
  // widget_->norm() сам делает сдвиг модели (оставить так?)
  double new_scale =
      widget_->norm() * currect_scale_;  // TODO вызов контроллера
  ApplyScale(new_scale);
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
  double scale_factor = new_scale / currect_scale_;
  currect_scale_ = new_scale;
  widget_->scale(scale_factor);  // TODO вызов контроллера
  scale_box_->blockSignals(true);
  scale_box_->setValue(currect_scale_);
  scale_box_->blockSignals(false);
  status_bar_->showMessage("scale");
}