#include "movement_control.h"

#include <QMessageBox>

#include "../controller/controller.h"

namespace s21 {

MovementControl::MovementControl(){};

MovementControl::MovementControl(QDoubleSpinBox* z_box, QToolButton* z_positive,
                                 QToolButton* z_negative)
    : box_(z_box), positive_(z_positive), negative_(z_negative) {
  SetupConnections();
}

void MovementControl::SetupMovementControl(void (Controller::*method)(double),
                                           QDoubleSpinBox* box,
                                           QToolButton* positive,
                                           QToolButton* negative) {
  method_ = method;
  box_ = box;
  positive_ = positive;
  negative_ = negative;
  SetupConnections();
}

void MovementControl::SetupConnections() {
  connect(positive_, SIGNAL(clicked()), this, SLOT(MoveOnAxisPositive()));
  connect(negative_, SIGNAL(clicked()), this, SLOT(MoveOnAxisNegative()));
}

void MovementControl::SetController(Controller& controller) {
  controller_ = &controller;
}

void MovementControl::MoveOnAxisPositive() {
  MoveOnAxis(MovementControl::kPositive);
}

void MovementControl::MoveOnAxisNegative() {
  MoveOnAxis(MovementControl::kNegative);
}

void MovementControl::MoveOnAxis(MovementControl::Direction direction) {
  double movement = direction * box_->value();
  (controller_->*method_)(movement);
}

};  // namespace s21
