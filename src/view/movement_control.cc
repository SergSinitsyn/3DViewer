#include "movement_control.h"

MovementControl::MovementControl() {}

void MovementControl::SetupMovementControl(Widget *widget,
                                           QStatusBar *status_bar,
                                           QDoubleSpinBox *move_x,
                                           QDoubleSpinBox *move_y,
                                           QDoubleSpinBox *move_z) {
  widget_ = widget;
  status_bar_ = status_bar;
  move_x_ = move_x;
  move_y_ = move_y;
  move_z_ = move_z;
}

void MovementControl::MoveOnXAxis(Direction direction) {
  double movement = direction * move_x_->value();
  // TODO здесь вызов контроллера а не метода виджета
  widget_->move(movement, 0.0, 0.0);
  widget_->update();
  status_bar_->showMessage(QString("movement on axis x: %1").arg(movement));
}

void MovementControl::MoveOnYAxis(Direction direction) {
  double movement = direction * move_y_->value();
  // TODO здесь вызов контроллера а не метода виджета
  widget_->move(0, movement, 0);
  widget_->update();
  status_bar_->showMessage(QString("movement on axis y: %1").arg(movement));
}

void MovementControl::MoveOnZAxis(Direction direction) {
  double movement = direction * move_z_->value();
  // TODO здесь вызов контроллера а не метода виджета
  widget_->move(0, 0, movement);
  widget_->update();
  status_bar_->showMessage(QString("movement on axis z: %1").arg(movement));
}
