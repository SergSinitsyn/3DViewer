#ifndef MOVEMENT_CONTROL_H
#define MOVEMENT_CONTROL_H

#include <QDoubleSpinBox>
#include <QStatusBar>
#include <QString>
#include <QToolButton>

#include "widget.h"

namespace s21 {

class Controller;
class MovementControl : public QObject {
  Q_OBJECT
 public:
  enum Direction {
    kNegative = -1,
    kPositive = 1,
  };
  MovementControl();
  MovementControl(QDoubleSpinBox* box, QToolButton* positive,
                  QToolButton* negative);
  void SetupMovementControl(void (Controller::*method)(double),
                            QDoubleSpinBox* box, QToolButton* positive,
                            QToolButton* negative);
  void SetController(Controller& controller);

 private slots:
  void MoveOnAxisPositive();
  void MoveOnAxisNegative();

 private:
  void SetupConnections();
  Controller* controller_;
  void (Controller::*method_)(double);
  QDoubleSpinBox* box_;
  QToolButton* positive_;
  QToolButton* negative_;
  void MoveOnAxis(MovementControl::Direction direction);
};

};  // namespace s21

#endif  // MOVEMENT_CONTROLLER_H
