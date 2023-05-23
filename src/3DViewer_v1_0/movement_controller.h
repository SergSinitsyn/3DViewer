#ifndef MOVEMENT_CONTROLLER_H
#define MOVEMENT_CONTROLLER_H

#include <QDoubleSpinBox>
#include <QStatusBar>
#include <QString>

#include "widget.h"

class MovementController {
 public:
  MovementController(){};
  void SetupMove(Widget* widget, QStatusBar* status_bar, QDoubleSpinBox* move_x,
                 QDoubleSpinBox* move_y, QDoubleSpinBox* move_z) {
    widget_ = widget;
    status_bar_ = status_bar;
    move_x_ = move_x;
    move_y_ = move_y;
    move_z_ = move_z;
  }

  void MoveOnX(double direction) {
    double movement = direction * move_x_->value();
    if (1) {
      widget_->move(movement, 0.0, 0.0);
      widget_->update();
    }
    widget_->update();
    status_bar_->showMessage(QString("movement on axis x: %1").arg(movement));
  }

  void MoveOnY(double direction) {
    double movement = direction * move_y_->value();
    //    widget_->move(0, movement, 0);
    widget_->update();
    status_bar_->showMessage(QString("movement on axis y: %1").arg(movement));
  }

  void MoveOnZ(double direction) {
    double movement = direction * move_z_->value();
    //    widget_->move(0, 0, movement);

    widget_->update();
    status_bar_->showMessage(QString("movement on axis z: %1").arg(movement));
  }

 private:
  Widget* widget_;
  QStatusBar* status_bar_;
  QDoubleSpinBox* move_x_;
  QDoubleSpinBox* move_y_;
  QDoubleSpinBox* move_z_;
};

#endif  // MOVEMENT_CONTROLLER_H
