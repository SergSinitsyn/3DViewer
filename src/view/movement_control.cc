#include "movement_control.h"

#include <QMessageBox>

#include "../controller/controller.h"

MovementControl::MovementControl(){};

MovementControl::MovementControl(
    QStatusBar* status_bar, QDoubleSpinBox* x_box, QDoubleSpinBox* y_box,
    QDoubleSpinBox* z_box, QToolButton* x_positive, QToolButton* x_negative,
    QToolButton* y_positive, QToolButton* y_negative, QToolButton* z_positive,
    QToolButton* z_negative)
    : status_bar_(status_bar),
      x_box_(x_box),
      y_box_(y_box),
      z_box_(z_box),
      x_positive_(x_positive),
      x_negative_(x_negative),
      y_positive_(y_positive),
      y_negative_(y_negative),
      z_positive_(z_positive),
      z_negative_(z_negative) {
  SetupConnections();
}

void MovementControl::SetupMovementControl(
    QStatusBar* status_bar, QDoubleSpinBox* x_box, QDoubleSpinBox* y_box,
    QDoubleSpinBox* z_box, QToolButton* x_positive, QToolButton* x_negative,
    QToolButton* y_positive, QToolButton* y_negative, QToolButton* z_positive,
    QToolButton* z_negative) {
  status_bar_ = status_bar;
  x_box_ = x_box;
  y_box_ = y_box;
  z_box_ = z_box;
  x_positive_ = x_positive;
  x_negative_ = x_negative;
  y_positive_ = y_positive;
  y_negative_ = y_negative;
  z_positive_ = z_positive;
  z_negative_ = z_negative;
  SetupConnections();
}

void MovementControl::SetupConnections() {
  connect(x_positive_, SIGNAL(clicked()), this, SLOT(MoveOnXAxisPositive()));
  connect(x_negative_, SIGNAL(clicked()), this, SLOT(MoveOnXAxisNegative()));
  connect(y_positive_, SIGNAL(clicked()), this, SLOT(MoveOnYAxisPositive()));
  connect(y_negative_, SIGNAL(clicked()), this, SLOT(MoveOnYAxisNegative()));
  connect(z_positive_, SIGNAL(clicked()), this, SLOT(MoveOnZAxisPositive()));
  connect(z_negative_, SIGNAL(clicked()), this, SLOT(MoveOnZAxisNegative()));
}

void MovementControl::SetController(Controller& controller) {
  controller_ = &controller;
}

void MovementControl::MoveOnXAxisPositive() {
  MoveOnXAxis(MovementControl::kPositive);
}

void MovementControl::MoveOnXAxisNegative() {
  MoveOnXAxis(MovementControl::kNegative);
}

void MovementControl::MoveOnYAxisPositive() {
  MoveOnYAxis(MovementControl::kPositive);
}

void MovementControl::MoveOnYAxisNegative() {
  MoveOnYAxis(MovementControl::kNegative);
}

void MovementControl::MoveOnZAxisPositive() {
  MoveOnZAxis(MovementControl::kPositive);
}

void MovementControl::MoveOnZAxisNegative() {
  MoveOnZAxis(MovementControl::kNegative);
}

void MovementControl::MoveOnXAxis(MovementControl::Direction direction) {
  double movement = direction * x_box_->value();
  try {
    controller_->ShiftOnXAxis(movement);
  } catch (const std::exception& e) {
    QString myQString = QString::fromStdString(e.what());
    qDebug() << myQString;
  }
  status_bar_->showMessage(QString("movement on axis x: %1").arg(movement));
}

void MovementControl::MoveOnYAxis(MovementControl::Direction direction) {
  double movement = direction * y_box_->value();
  controller_->ShiftOnYAxis(movement);
  status_bar_->showMessage(QString("movement on axis y: %1").arg(movement));
}

void MovementControl::MoveOnZAxis(MovementControl::Direction direction) {
  double movement = direction * z_box_->value();
  controller_->ShiftOnZAxis(movement);
  status_bar_->showMessage(QString("movement on axis z: %1").arg(movement));
}
