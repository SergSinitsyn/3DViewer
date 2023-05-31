#ifndef MOVEMENT_CONTROL_H
#define MOVEMENT_CONTROL_H

#include <QDoubleSpinBox>
#include <QStatusBar>
#include <QString>

#include "widget.h"

class MovementControl {
 public:
  enum Direction {
    kNegative = -1,
    kPositive = 1,
  };

  MovementControl();
  void SetupMovementControl(Widget* widget, QStatusBar* status_bar,
                            QDoubleSpinBox* move_x, QDoubleSpinBox* move_y,
                            QDoubleSpinBox* move_z);
  void MoveOnXAxis(Direction direction);
  void MoveOnYAxis(Direction direction);
  void MoveOnZAxis(Direction direction);

 private:
  Widget* widget_;
  QStatusBar* status_bar_;
  QDoubleSpinBox* move_x_;
  QDoubleSpinBox* move_y_;
  QDoubleSpinBox* move_z_;
};

#endif  // MOVEMENT_CONTROLLER_H
