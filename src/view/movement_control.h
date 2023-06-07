#ifndef MOVEMENT_CONTROL_H
#define MOVEMENT_CONTROL_H

#include <QDoubleSpinBox>
#include <QStatusBar>
#include <QString>
#include <QToolButton>

#include "widget.h"

class Controller;
class MovementControl : public QObject {
  Q_OBJECT
 public:
  enum Direction {
    kNegative = -1,
    kPositive = 1,
  };
  MovementControl();
  MovementControl(Widget* widget, QStatusBar* status_bar, QDoubleSpinBox* x_box,
                  QDoubleSpinBox* y_box, QDoubleSpinBox* z_box,
                  QToolButton* x_positive, QToolButton* x_negative,
                  QToolButton* y_positive, QToolButton* y_negative,
                  QToolButton* z_positive, QToolButton* z_negative);

  void SetupMovementControl(Widget* widget, QStatusBar* status_bar,
                            QDoubleSpinBox* x_box, QDoubleSpinBox* y_box,
                            QDoubleSpinBox* z_box, QToolButton* x_positive,
                            QToolButton* x_negative, QToolButton* y_positive,
                            QToolButton* y_negative, QToolButton* z_positive,
                            QToolButton* z_negative);
  void SetController(Controller& controller);

 private slots:
  void MoveOnXAxisPositive();
  void MoveOnXAxisNegative();
  void MoveOnYAxisPositive();
  void MoveOnYAxisNegative();
  void MoveOnZAxisPositive();
  void MoveOnZAxisNegative();

 private:
  void SetupConnections();
  Controller* controller_;
  Widget* widget_;
  QStatusBar* status_bar_;
  QDoubleSpinBox* x_box_;
  QDoubleSpinBox* y_box_;
  QDoubleSpinBox* z_box_;
  QToolButton* x_positive_;
  QToolButton* x_negative_;
  QToolButton* y_positive_;
  QToolButton* y_negative_;
  QToolButton* z_positive_;
  QToolButton* z_negative_;

  void MoveOnXAxis(MovementControl::Direction direction);
  void MoveOnYAxis(MovementControl::Direction direction);
  void MoveOnZAxis(MovementControl::Direction direction);
};

#endif  // MOVEMENT_CONTROLLER_H
