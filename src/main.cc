#include <QApplication>

#include "controller/controller.h"
#include "model/vmodel.h"
#include "view/mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication application(argc, argv);
  setlocale(LC_ALL, "C");
  s21::MainWindow view;
  s21::VModel model;
  s21::Controller& controller = s21::Controller::GetInstance();
  controller.SetModel(model);
  controller.SetView(view);
  view.show();
  int result = application.exec();
  return result;
}
