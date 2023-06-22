#ifndef VIEWER_2_VIEW_CONTROLS_ROTATION_CONTROL_H
#define VIEWER_2_VIEW_CONTROLS_ROTATION_CONTROL_H

#include <QDial>
#include <QSpinBox>

namespace s21 {

class Controller;
class RotationControl : public QObject {
  Q_OBJECT

 public:
  RotationControl() = default;
  void SetupRotationControl(void (Controller::*method)(int), QSpinBox *box,
                            QDial *dial);
  void SetController(Controller &controller);
  void Default();

 private slots:
  void RotateAroundAxis(int new_angle);

 private:
  void SetupConnections();
  Controller *controller_{nullptr};
  void (Controller::*method_)(int){nullptr};
  QSpinBox *box_{nullptr};
  QDial *dial_{nullptr};
  int current_angle_{0};
};

};  // namespace s21

#endif  // VIEWER_2_VIEW_CONTROLS_ROTATION_CONTROL_H
