#ifndef VIEWER_2_CONTROLLER_CONTROLLER_H
#define VIEWER_2_CONTROLLER_CONTROLLER_H

#include <../model/vmodel.h>
#include <../view/mainwindow.h>

namespace s21 {

class Controller : public QObject {
  Q_OBJECT

 public:
  Controller(s21::VModel& model, s21::MainWindow& view);

  void LoadFile(const std::string& file_name);
  void RestoreModel();

 public slots:
  void RotateAroundXAxis(int angle);
  void RotateAroundYAxis(int angle);
  void RotateAroundZAxis(int angle);

  void ShiftOnXAxis(double length);
  void ShiftOnYAxis(double length);
  void ShiftOnZAxis(double length);

  void Scaling(double scale);

 private:
  void UpdateView();
  Memento<s21::VModel> just_loaded_model_;
  s21::VModel& model_;
  s21::MainWindow& view_;
};

};  // namespace s21

#endif  // CPP4_3DVIEWER2_CONTROLLER_CONTROLLER_H
