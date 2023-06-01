#ifndef SCALING_CONTROL_H
#define SCALING_CONTROL_H

#include <QDoubleSpinBox>
#include <QObject>
#include <QStatusBar>
#include <QToolButton>
#include <QWidget>

#include "widget.h"

class ScalingControl {
 public:
  ScalingControl() = default;
  void SetupScalingControl(Widget* widget, QStatusBar* status_bar,
                           QDoubleSpinBox* scale_box,
                           QToolButton* scale_down_button,
                           QToolButton* scale_up_button);
  void SetupConnections();

 public slots:
  void Normalize();
  void UpdateScale();
  void ScaleDown();
  void ScaleUp();

 private:
  void ApplyScale(double new_scale);

  Widget* widget_;
  QDoubleSpinBox* scale_box_;
  QToolButton* scale_down_button_;
  QToolButton* scale_up_button_;
  QStatusBar* status_bar_;
  double currect_scale_ = 100.0;
};

#endif  // SCALING_CONTROL_H
