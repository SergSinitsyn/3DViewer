#include "info.h"

#include <libgen.h>

#include "ui_info.h"

namespace s21 {

Info::Info(QWidget *parent, ModelInformation &model_information)
    : QDialog(parent),
      ui_(new Ui::Info),
      model_information_(model_information) {
  ui_->setupUi(this);
  InitializationInfo();
}

Info::~Info() { delete ui_; }

void Info::InitializationInfo() {
  QString filename = QString::fromStdString(model_information_.file_name);
  QString edges = QString::number(model_information_.edges_number);
  QString vertices = QString::number(model_information_.vertices_number);
  QString faces = QString::number(model_information_.facetes_number);

  ui_->label_filename->setText(filename);
  ui_->label_numberOfEdges->setText(edges);
  ui_->label_numberOfVertices->setText(vertices);
  ui_->label_numberOfFaces->setText(faces);
}

};  // namespace s21
