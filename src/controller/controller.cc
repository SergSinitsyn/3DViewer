#include "controller.h"

Controller::Controller(Model& model, View& view) : model_(model), view_(view) {
  view_.SetController(this);
  //  view.SetController(*this);
}

void Controller::LoadFile(std::string file_name) {
  model_.ReadModelFile(file_name);
  //   view_.SetInfo(model_.GetData());
  //   view_.SetModel(model_.GetData());
}

void Controller::RotateAroundXAxis(int angle) { model_.XRotation(angle); }

void Controller::RotateAroundYAxis(int angle) { model_.YRotation(angle); }

void Controller::RotateAroundZAxis(int angle) { model_.ZRotation(angle); }

void Controller::ShiftOnXAxis(double length) { model_.XShift(length); }

void Controller::ShiftOnYAxis(double length) { model_.YShift(length); }

void Controller::ShiftOnZAxis(double length) { model_.YShift(length); }

void Controller::Scaling(double scale) { model_.Scaling(scale); }