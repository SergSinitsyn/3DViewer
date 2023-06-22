#ifndef VIEWER_2_CONTROLLER_CONTROLLER_H_
#define VIEWER_2_CONTROLLER_CONTROLLER_H_

#include "../model/vmodel.h"
#include "../other/decorator.h"
#include "../view/mainwindow/mainwindow.h"

namespace s21 {

// Singleton pattern
template <typename T>
class Singleton {
 public:
  static T& GetInstance() {
    static T instance;
    return instance;
  }

 protected:
  Singleton() = default;
  virtual ~Singleton() = default;

 private:
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
};

class Controller : public Singleton<Controller> {
 public:
  friend class Singleton<Controller>;

  void LoadFile(const std::string& file_name);
  void RestoreModel();
  void SetModel(s21::VModel& model);
  void SetView(s21::MainWindow& view);

  void RotateAroundXAxis(int angle);
  void RotateAroundYAxis(int angle);
  void RotateAroundZAxis(int angle);

  void ShiftOnXAxis(double length);
  void ShiftOnYAxis(double length);
  void ShiftOnZAxis(double length);

  void Scaling(double scale);

 private:
  Controller() = default;
  void UpdateView();
  s21::VModel* model_{nullptr};
  s21::MainWindow* view_{nullptr};
};

}  // namespace s21

#endif  // VIEWER_2_CONTROLLER_CONTROLLER_H_
