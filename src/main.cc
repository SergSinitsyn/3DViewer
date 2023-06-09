#include <QApplication>

#include "controller/controller.h"
#include "model/vmodel.h"
#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication application(argc, argv);
  MainWindow view;
  s21::VModel model;
  Controller controller(model, view);
  view.show();
  return application.exec();
}
