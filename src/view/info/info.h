#ifndef INFO_H
#define INFO_H

#include <QDialog>

#include "../../other/structs.h"

namespace Ui {
class Info;
}

namespace s21 {

class Info : public QDialog {
  Q_OBJECT

 public:
  explicit Info(QWidget *parent = nullptr,
                ModelInformation model_information = ModelInformation());
  ~Info();
  void InitializationInfo();

 private:
  Ui::Info *ui_;
  ModelInformation model_information_;
};

};  // namespace s21

#endif  // INFO_H
