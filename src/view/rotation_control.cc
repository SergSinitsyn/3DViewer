#include "rotation_control.h"

#include "../controller/controller.h"

RotationControl::RotationControl(){};

RotationControl::RotationControl(Widget* widget, QStatusBar* status_bar,
                                 QSpinBox* x_box, QSpinBox* y_box,
                                 QSpinBox* z_box, QDial* x_dial, QDial* y_dial,
                                 QDial* z_dial)
    : widget_(widget),
      status_bar_(status_bar),
      x_box_(x_box),
      y_box_(y_box),
      z_box_(z_box),
      x_dial_(x_dial),
      y_dial_(y_dial),
      z_dial_(z_dial) {
  SetupConnections();
}

void RotationControl::SetupRotationControl(Widget* widget,
                                           QStatusBar* status_bar,
                                           QSpinBox* x_box, QSpinBox* y_box,
                                           QSpinBox* z_box, QDial* x_dial,
                                           QDial* y_dial, QDial* z_dial) {
  widget_ = widget;
  status_bar_ = status_bar;
  x_box_ = x_box;
  y_box_ = y_box;
  z_box_ = z_box;
  x_dial_ = x_dial;
  y_dial_ = y_dial;
  z_dial_ = z_dial;
  SetupConnections();
}

void RotationControl::SetupConnections() {
  connect(x_dial_, SIGNAL(valueChanged(int)), this,
          SLOT(RotateAroundXAxis(int)));
  connect(x_dial_, SIGNAL(sliderMoved(int)), this,
          SLOT(RotateAroundXAxis(int)));
  connect(x_box_, SIGNAL(valueChanged(int)), this,
          SLOT(RotateAroundXAxis(int)));
  connect(y_dial_, SIGNAL(valueChanged(int)), this,
          SLOT(RotateAroundYAxis(int)));
  connect(y_dial_, SIGNAL(sliderMoved(int)), this,
          SLOT(RotateAroundYAxis(int)));
  connect(y_box_, SIGNAL(valueChanged(int)), this,
          SLOT(RotateAroundYAxis(int)));
  connect(z_dial_, SIGNAL(valueChanged(int)), this,
          SLOT(RotateAroundZAxis(int)));
  connect(z_dial_, SIGNAL(sliderMoved(int)), this,
          SLOT(RotateAroundZAxis(int)));
  connect(z_box_, SIGNAL(valueChanged(int)), this,
          SLOT(RotateAroundZAxis(int)));
}

void RotationControl::SetController(Controller& controller) {
  controller_ = &controller;
}

void RotationControl::RotateAroundXAxis(int position) {
  x_box_->blockSignals(true);
  x_dial_->blockSignals(true);

  int new_angle = position - current_x_angle_;
  widget_->rotate(new_angle, 0, 0);  // TODO удалить это
  controller_->RotateAroundXAxis(new_angle);

  current_x_angle_ = position;
  x_box_->setValue(current_x_angle_);
  x_dial_->setValue(current_x_angle_);
  status_bar_->showMessage(QString("rotation on axis x: %1").arg(new_angle));

  x_box_->blockSignals(false);
  x_dial_->blockSignals(false);
}

void RotationControl::RotateAroundYAxis(int position) {
  y_box_->blockSignals(true);
  y_dial_->blockSignals(true);

  int new_angle = position - current_y_angle_;
  widget_->rotate(0, new_angle, 0);  // TODO удалить это
  controller_->RotateAroundYAxis(new_angle);

  current_y_angle_ = position;
  y_box_->setValue(current_y_angle_);
  y_dial_->setValue(current_y_angle_);
  status_bar_->showMessage(QString("rotation on axis y: %1").arg(new_angle));

  y_box_->blockSignals(false);
  y_dial_->blockSignals(false);
}

void RotationControl::RotateAroundZAxis(int position) {
  z_box_->blockSignals(true);
  z_dial_->blockSignals(true);

  int new_angle = position - current_z_angle_;
  widget_->rotate(0, 0, new_angle);  // TODO удалить это
  controller_->RotateAroundYAxis(new_angle);

  current_z_angle_ = position;
  z_box_->setValue(current_z_angle_);
  z_dial_->setValue(current_z_angle_);
  status_bar_->showMessage(QString("rotation on axis z: %1").arg(new_angle));

  z_box_->blockSignals(false);
  z_dial_->blockSignals(false);
}
