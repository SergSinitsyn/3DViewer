#include "controller.h"

#include <../model/vmodel.h>
#include <../view/mainwindow.h>

namespace s21 {

void Controller::SetModel(s21::VModel& model) { model_ = &model; }

void Controller::SetView(s21::MainWindow& view) {
  view_ = &view;
  view_->SetController(*this);
}

void Controller::LoadFile(const std::string& file_name) {
  model_->ReadModelFile(file_name);
  model_->Inscribe();
  // just_loaded_model_->SetState(&model_);  // ! fix
  view_->SetModelInformation(model_->GetInformation());
  UpdateView();
}

void Controller::RestoreModel() {
  // model_ = *just_loaded_model_.GetState();   // ! fix
  UpdateView();
}

void Controller::RotateAroundXAxis(int angle) {
  model_->XRotation(static_cast<double>(angle));
  UpdateView();
}

void Controller::RotateAroundYAxis(int angle) {
  model_->YRotation(static_cast<double>(angle));
  UpdateView();
}

void Controller::RotateAroundZAxis(int angle) {
  model_->ZRotation(static_cast<double>(angle));
  UpdateView();
}

void Controller::ShiftOnXAxis(double length) {
  model_->XShift(length);
  UpdateView();
}

void Controller::ShiftOnYAxis(double length) {
  model_->YShift(length);
  UpdateView();
}

void Controller::ShiftOnZAxis(double length) {
  model_->ZShift(length);
  UpdateView();
}

void Controller::Scaling(double scale) {
  model_->Scaling(scale);
  UpdateView();
}

void Controller::UpdateView() {
  view_->SetModelData(model_->GetVertices(), model_->GetEdges());
  view_->UpdateWidget();
}

};  // namespace s21
