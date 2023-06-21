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
  MovementControl() = default;
  void SetupMovementControl(void (Controller::*method)(double),
                            QDoubleSpinBox* box, QToolButton* positive,
                            QToolButton* negative);
  void SetController(Controller& controller);
  void Default();

 private slots:
  void MoveOnAxisPositive();
  void MoveOnAxisNegative();

 private:
  void SetupConnections();
  Controller* controller_{nullptr};
  void (Controller::*method_)(double){nullptr};
  QDoubleSpinBox* box_{nullptr};
  QToolButton* positive_{nullptr};
  QToolButton* negative_{nullptr};
  void MoveOnAxis(MovementControl::Direction direction);
};

};  // namespace s21

#endif  // MOVEMENT_CONTROLLER_H
