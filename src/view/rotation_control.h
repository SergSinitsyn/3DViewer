#ifndef ROTATION_CONTROL_H
#define ROTATION_CONTROL_H

#include <QDial>
#include <QSpinBox>
#include <QStatusBar>
#include <QString>

#include "widget.h"

class RotationControl {
 public:
  RotationControl(){};
  void SetupRotationControl(Widget* widget, QStatusBar* status_bar,
                            QSpinBox* X_box, QSpinBox* Y_box, QSpinBox* Z_box,
                            QDial* X_dial, QDial* Y_dial, QDial* Z_dial) {
    widget_ = widget;
    status_bar_ = status_bar;
    X_box_ = X_box;
    Y_box_ = Y_box;
    Z_box_ = Z_box;
    X_dial_ = X_dial;
    Y_dial_ = Y_dial;
    Z_dial_ = Z_dial;
    X_box_->setValue(0);
    Y_box_->setValue(0);
    Z_box_->setValue(0);
    X_dial_->setValue(0);
    Y_dial_->setValue(0);
    Z_dial_->setValue(0);
  };

  void RotateAroundXAxis(int position) {
    widget_->rotate(position - current_x_angle_, 0, 0);
    current_x_angle_ = position;
    X_box_->setValue(current_x_angle_);
    X_dial_->setValue(current_x_angle_);
    status_bar_->showMessage(
        QString("rotation on axis x: %1").arg(position - current_x_angle_));
  };

  void RotateAroundYAxis(int position) {
    widget_->rotate(0, position - current_y_angle_, 0);
    current_y_angle_ = position;
    Y_box_->setValue(current_y_angle_);
    Y_dial_->setValue(current_y_angle_);
    status_bar_->showMessage(
        QString("rotation on axis y: %1").arg(position - current_y_angle_));
  };

  void RotateAroundZAxis(int position) {
    widget_->rotate(0, 0, position - current_z_angle_);
    current_z_angle_ = position;
    Z_box_->setValue(current_z_angle_);
    Z_dial_->setValue(current_z_angle_);
    status_bar_->showMessage(
        QString("rotation on axis z: %1").arg(position - current_z_angle_));
  };

 private:
  Widget* widget_;
  QStatusBar* status_bar_;
  int current_x_angle_ = 0;
  int current_y_angle_ = 0;
  int current_z_angle_ = 0;

  QSpinBox* X_box_;
  QSpinBox* Y_box_;
  QSpinBox* Z_box_;
  QDial* X_dial_;
  QDial* Y_dial_;
  QDial* Z_dial_;
};

#endif  // ROTATION_CONTROL_H
