#include "movement_control.h"

MovementControl::MovementControl(){};

MovementControl::MovementControl(Widget* widget, QStatusBar* status_bar,
                                 QDoubleSpinBox* x_box, QDoubleSpinBox* y_box,
                                 QDoubleSpinBox* z_box)
    : widget_(widget),
      status_bar_(status_bar),
      x_box_(x_box),
      y_box_(y_box),
      z_box_(z_box) {
  SetupConnections();
}

void MovementControl::SetupMovementControl(Widget* widget,
                                           QStatusBar* status_bar,
                                           QDoubleSpinBox* x_box,
                                           QDoubleSpinBox* y_box,
                                           QDoubleSpinBox* z_box) {
  widget_ = widget;
  status_bar_ = status_bar;
  x_box_ = x_box;
  y_box_ = y_box;
  z_box_ = z_box;
  SetupConnections();
}

void MovementControl::SetupConnections() {
  // TODO сделать коннекты от кнопок здесь?
}

void MovementControl::MoveOnXAxis(Direction direction) {
  double movement = direction * x_box_->value();
  // TODO здесь вызов контроллера а не метода виджета
  widget_->move(movement, 0.0, 0.0);
  widget_->update();
  status_bar_->showMessage(QString("movement on axis x: %1").arg(movement));
}

void MovementControl::MoveOnYAxis(Direction direction) {
  double movement = direction * y_box_->value();
  // TODO здесь вызов контроллера а не метода виджета
  widget_->move(0, movement, 0);
  widget_->update();
  status_bar_->showMessage(QString("movement on axis y: %1").arg(movement));
}

void MovementControl::MoveOnZAxis(Direction direction) {
  double movement = direction * z_box_->value();
  // TODO здесь вызов контроллера а не метода виджета
  widget_->move(0, 0, movement);
  widget_->update();
  status_bar_->showMessage(QString("movement on axis z: %1").arg(movement));
}
