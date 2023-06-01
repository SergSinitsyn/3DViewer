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
                            QDoubleSpinBox* x_box, QDoubleSpinBox* y_box,
                            QDoubleSpinBox* z_box);

  void MoveOnXAxis(Direction direction);
  void MoveOnYAxis(Direction direction);
  void MoveOnZAxis(Direction direction);

 private:
  void SetupConnections();
  Widget* widget_;
  QStatusBar* status_bar_;
  QDoubleSpinBox* x_box_;
  QDoubleSpinBox* y_box_;
  QDoubleSpinBox* z_box_;
};

#endif  // MOVEMENT_CONTROLLER_H
