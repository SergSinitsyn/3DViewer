#ifndef INFO_H
#define INFO_H

#include <QDialog>

#include "../../other/structs.h"

namespace Ui {
class Info;
}

class Info : public QDialog {
  Q_OBJECT

 public:
  Info(QWidget *parent = nullptr,
       ModelInformation model_information = ModelInformation());
  ~Info();
  void InitializationInfo();

 private:
  Ui::Info *ui;
  ModelInformation model_information_;
};

#endif  // INFO_H
