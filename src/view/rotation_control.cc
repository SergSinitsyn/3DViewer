#include "rotation_control.h"

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
}

void RotationControl::SetupConnections() {
  // TODO сделать коннекты от кнопок здесь

  // QObject::connect(x_dial_, SIGNAL(valueChanged(int)), this,
  //                  SLOT(RotateAroundXAxis(int)));

  //  QObject::connect(x_dial_, &QDial::valueChanged, this,
  //                   &RotationControl::RotateAroundXAxis);
}

void RotationControl::RotateAroundXAxis(int position) {
  widget_->rotate(position - current_x_angle_, 0, 0);
  current_x_angle_ = position;
  x_box_->setValue(current_x_angle_);
  x_dial_->setValue(current_x_angle_);
  status_bar_->showMessage(
      QString("rotation on axis x: %1").arg(position - current_x_angle_));
}

void RotationControl::RotateAroundYAxis(int position) {
  widget_->rotate(0, position - current_y_angle_, 0);
  current_y_angle_ = position;
  y_box_->setValue(current_y_angle_);
  y_dial_->setValue(current_y_angle_);
  status_bar_->showMessage(
      QString("rotation on axis y: %1").arg(position - current_y_angle_));
}

void RotationControl::RotateAroundZAxis(int position) {
  widget_->rotate(0, 0, position - current_z_angle_);
  current_z_angle_ = position;
  z_box_->setValue(current_z_angle_);
  z_dial_->setValue(current_z_angle_);
  status_bar_->showMessage(
      QString("rotation on axis z: %1").arg(position - current_z_angle_));
}
