#ifndef VIEWER_2_OTHER_DECORATOR_H_
#define VIEWER_2_OTHER_DECORATOR_H_

#include "../model/vmodel.h"
#include "memento.h"

namespace s21 {

// Decorator pattern
class Decorator : public VModel {
 public:
  Decorator(){};
  explicit Decorator(VModel* component) : VModel(*component){};

  void SaveModel() { just_loaded_model_.SetState(this); };
  void Inscribe() override {
    VModel::Inscribe();
    just_loaded_model_.SetState(this);
  };
  void RestoreModel() override {
    (*this).VModel::operator=(*just_loaded_model_.GetState());
  };

 private:
  Memento<VModel> just_loaded_model_;
};

}  // namespace s21

#endif  // VIEWER_2_OTHER_DECORATOR_H_
