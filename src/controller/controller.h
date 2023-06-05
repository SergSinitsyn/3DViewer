#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
 public:
  Controller(Model& model, View& view) : model_(model), view_(view) {}

  void HandleUserInput(const std::string& user_input) {
    // Обработка пользовательского ввода
    model_.UpdateData(user_input);
    view_.Render(model_.GetData());
  }

 private:
  Model& model_;
  View& view_;
};

#endif  // CONTROLLER_H