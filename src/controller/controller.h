#ifndef VIEWER_2_CONTROLLER_CONTROLLER_H
#define VIEWER_2_CONTROLLER_CONTROLLER_H

#include <../model/vmodel.h>
#include <../view/mainwindow.h>

namespace s21 {

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

class Controller : public QObject, public Singleton<Controller> {
  Q_OBJECT

 public:
  friend class Singleton<Controller>;

  void LoadFile(const std::string& file_name);
  void RestoreModel();
  void SetModel(s21::VModel& model);
  void SetView(s21::MainWindow& view);

 public slots:
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
  Memento<s21::VModel> just_loaded_model_;
  s21::VModel* model_{nullptr};
  s21::MainWindow* view_{nullptr};
};

};  // namespace s21

#endif  // VIEWER_2_CONTROLLER_CONTROLLER_H