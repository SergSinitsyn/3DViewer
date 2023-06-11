#include <QApplication>

#include "controller/controller.h"
#include "model/vmodel.h"
#include "view/mainwindow.h"

int main(int argc, char* argv[]) {
  QApplication application(argc, argv);
  // Make a "deep copy" of current locale name.
  std::string prev_loc = std::setlocale(LC_ALL, nullptr);
  const char* loc = std::setlocale(LC_ALL, "en_US.UTF-8");
  MainWindow view;
  s21::VModel model;
  Controller controller(model, view);
  view.show();
  int res = application.exec();
  // Restore the previous locale.
  std::setlocale(LC_ALL, prev_loc.c_str());
  return res;
}
