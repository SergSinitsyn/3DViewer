#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <../model/vmodel.h>
#include <../view/mainwindow.h>

class Controller {
 public:
  Controller(Model& model, View& view);

  void LoadFile(std::string file_name);

  void RotateAroundXAxis(int angle);
  void RotateAroundYAxis(int angle);
  void RotateAroundZAxis(int angle);

  void ShiftOnXAxis(double length);
  void ShiftOnYAxis(double length);
  void ShiftOnZAxis(double length);

  void Scaling(double scale);

 private:
  VModel& model_;
  MainWindow& view_;
};

#endif  // CONTROLLER_H