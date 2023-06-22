#ifndef VIEWER_2_VIEW_INFO_INFO_H_
#define VIEWER_2_VIEW_INFO_INFO_H_

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
                const ModelInformation &model_information = ModelInformation());
  ~Info();
  void InitializationInfo();

 private:
  Ui::Info *ui_;
  ModelInformation model_information_;
};

}  // namespace s21

#endif  // VIEWER_2_VIEW_INFO_INFO_H_
