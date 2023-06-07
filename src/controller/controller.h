#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <../model/vmodel.h>
#include <../view/mainwindow.h>

class Controller : public QObject {
  Q_OBJECT
 public:
  Controller(s21::VModel& model, MainWindow& view);

  void LoadFile(std::string file_name);

 public slots:
  void RotateAroundXAxis(int angle);
  void RotateAroundYAxis(int angle);
  void RotateAroundZAxis(int angle);

  void ShiftOnXAxis(double length);
  void ShiftOnYAxis(double length);
  void ShiftOnZAxis(double length);

  void Scaling(double scale);

 private:
  s21::VModel& model_;
  MainWindow& view_;
};

#endif  // CONTROLLER_H
