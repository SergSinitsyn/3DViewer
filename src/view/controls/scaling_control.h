#ifndef VIEWER_2_VIEW_CONTROLS_SCALING_CONTROL_H_
#define VIEWER_2_VIEW_CONTROLS_SCALING_CONTROL_H_

#include <QDoubleSpinBox>
#include <QPushButton>
#include <QToolButton>

namespace s21 {

class Controller;
class ScalingControl : public QObject {
  Q_OBJECT
 public:
  ScalingControl() = default;
  void SetupScalingControl(void (Controller::*method)(double),
                           QDoubleSpinBox* scale_box, QPushButton* scale_button,
                           QToolButton* scale_down_button,
                           QToolButton* scale_up_button);
  void SetController(Controller& controller);
  void Default();

 private slots:
  void UpdateScale();
  void ScaleDown();
  void ScaleUp();

 private:
  void ApplyScale(double new_scale);
  void SetupConnections();
  Controller* controller_{nullptr};
  void (Controller::*method_)(double){nullptr};
  QDoubleSpinBox* scale_box_{nullptr};
  QPushButton* scale_button_{nullptr};
  QToolButton* scale_down_button_{nullptr};
  QToolButton* scale_up_button_{nullptr};
  double currect_scale_{100.0};
};

}  // namespace s21

#endif  // VIEWER_2_VIEW_CONTROLS_SCALING_CONTROL_H_
