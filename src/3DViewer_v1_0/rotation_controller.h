

class RotationController {
 public:
  RotationController(QWidget* widget, QStatusBar* status_bar,
                     QDoubleSpinBox* rotate_X_value,
                     QDoubleSpinBox* rotate_Y_value,
                     QDoubleSpinBox* rotate_Z_value, QDial* rotate_X_value,
                     QDial* rotate_Y_value, QDial* rotate_Z_value, )
      : widget_(widget),
        status_bar_(status_bar),
        rotate_X_(rotate_X_value),
        rotate_Y_(rotate_Y_value),
        rotate_Z_(rotate_Z_value){};

  RotateX(int position) {
    rotate_x(position - x_angle_);
    x_angle_ = position;
    X_box_.setValue(x_angle_);
    X_dial_.setValue(x_angle_);
    status_bar_->showMessage(QString("rotation on axis x: %1").arg(position));
  };

  RotateY(int position) {
    rotate_y(position - y_angle_);
    y_angle_ = position;
    Y_box_.setValue(y_angle_);
    Y_dial_.setValue(y_angle_);
    status_bar_->showMessage(QString("rotation on axis y: %1").arg(position));
  };

  RotateZ(int position) {
    rotate_z(position - z_angle_);
    z_angle_ = position;
    Z_box_.setValue(z_angle_);
    Z_dial_.setValue(z_angle_);
    status_bar_->showMessage(QString("rotation on axis z: %1").arg(position));
  };

 private:
  QWidget* widget_;
  QStatusBar* status_bar_;
  int x_angle_;
  int y_angle_;
  int z_angle_;

  QDoubleSpinBox* X_box_;
  QDoubleSpinBox* Y_box_;
  QDoubleSpinBox* Z_box_;
  QDial* X_dial_;
  QDial* Y_dial_;
  QDial* Z_dial_;
};