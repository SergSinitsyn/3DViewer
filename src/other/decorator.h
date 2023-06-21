#include "../model/vmodel.h"
#include "memento.h"

namespace s21 {

// Класс Decorator
class Decorator : public VModel {
 public:
  Decorator(){};
  Decorator(VModel* component) : VModel(*component){};

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