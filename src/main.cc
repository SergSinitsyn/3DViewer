#include <QApplication>

#include "controller/controller.h"
#include "model/vmodel.h"
#include "view/mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication application(argc, argv);
  // Make a "deep copy" of current locale name.
  std::string previous_locale = setlocale(LC_ALL, nullptr);
  const char* loc = setlocale(LC_ALL, "en_US.UTF-8");
  s21::MainWindow view;
  s21::VModel model;
  s21::Controller controller;
  controller.SetModel(model);
  controller.SetView(view);
  view.show();
  int result = application.exec();
  // Restore the previous locale.
  setlocale(LC_ALL, previous_locale.c_str());
  return result;
}
