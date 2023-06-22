#ifndef VIEWER2_OTHER_MEMENTO_H_
#define VIEWER2_OTHER_MEMENTO_H_

namespace s21 {

// Memento pattern
template <class T>
class Memento {
 public:
  Memento(){};
  explicit Memento(const T& s) : is_valid_{true}, state_{s} {};
  explicit Memento(const T* s) : is_valid_{true} {
    if (s != nullptr)
      state_ = *s;
    else
      is_valid_ = false;
  };
  T const* GetState() const {
    if (!is_valid_) throw std::runtime_error("Invalid state!");
    return &state_;
  };
  void SetState(const T* new_state) {
    if (new_state != nullptr && &state_ != new_state) {
      state_ = *new_state;
      is_valid_ = true;
    }
  };

 protected:
  T state_;
  bool is_valid_ = false;
};

}  // namespace s21

#endif  // VIEWER2_OTHER_MEMENTO_H_
