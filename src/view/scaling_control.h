#ifndef SCALING_CONTROL_H
#define SCALING_CONTROL_H

#include <QDoubleSpinBox>
#include <QObject>
#include <QPushButton>
#include <QStatusBar>
#include <QToolButton>
#include <QWidget>

#include "widget.h"

class Controller;
class ScalingControl : public QObject {
  Q_OBJECT
 public:
  ScalingControl() = default;
  ScalingControl(Widget* widget, QStatusBar* status_bar,
                 QDoubleSpinBox* scale_box, QPushButton* scale_button,
                 QToolButton* scale_down_button, QToolButton* scale_up_button)
      : widget_(widget),
        status_bar_(status_bar),
        scale_button_(scale_button),
        scale_box_(scale_box),
        scale_down_button_(scale_down_button),
        scale_up_button_(scale_up_button),
        currect_scale_(100.0) {
    SetupConnections();
  }
  void SetupScalingControl(Widget* widget, QStatusBar* status_bar,
                           QDoubleSpinBox* scale_box, QPushButton* scale_button,
                           QToolButton* scale_down_button,
                           QToolButton* scale_up_button);
  void SetController(Controller& controller);

 public slots:
  void Normalize();

 private:
  void ApplyScale(double new_scale);
  void SetupConnections();
  Controller* controller_;
  Widget* widget_;
  QStatusBar* status_bar_;
  QDoubleSpinBox* scale_box_;
  QPushButton* scale_button_;
  QToolButton* scale_down_button_;
  QToolButton* scale_up_button_;
  double currect_scale_{100.0};

 private slots:
  void UpdateScale();
  void ScaleDown();
  void ScaleUp();
};

#endif  // SCALING_CONTROL_H
