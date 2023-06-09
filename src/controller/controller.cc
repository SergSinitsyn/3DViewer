#include "controller.h"

#include <../model/vmodel.h>
#include <../view/mainwindow.h>

Controller::Controller(s21::VModel &model, MainWindow &view)
    : model_(model), view_(view) {
  view_.SetController(*this);
}

void Controller::LoadFile(std::string file_name) {
  model_.ReadModelFile(file_name);

  view_.SetModelData(model_.GetVertices(), model_.GetEdges());
  view_.SetModelInformation(model_.GetInformation());
}

void Controller::RotateAroundXAxis(int angle) {
  model_.XRotation((double)angle);
}

void Controller::RotateAroundYAxis(int angle) {
  model_.YRotation((double)angle);
}

void Controller::RotateAroundZAxis(int angle) {
  model_.ZRotation((double)angle);
}

void Controller::ShiftOnXAxis(double length) { model_.XShift(length); }

void Controller::ShiftOnYAxis(double length) { model_.YShift(length); }

void Controller::ShiftOnZAxis(double length) { model_.ZShift(length); }

void Controller::Scaling(double scale) { model_.Scaling(scale); }
