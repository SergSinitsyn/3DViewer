#ifndef INFO_H
#define INFO_H

#include <QDialog>

#include "functions/structs.h"

namespace Ui {
class Info;
}

class Info : public QDialog {
  Q_OBJECT

 public:
  //    explicit Info(QWidget *parent = nullptr);
  explicit Info(QWidget *parent = nullptr, const obj_data *data = nullptr);
  ~Info();
  void initialization_info(const obj_data *data);

 private:
  Ui::Info *ui;
};

#endif  // INFO_H
