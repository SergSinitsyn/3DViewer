#include "info.h"

#include <libgen.h>

#include "ui_info.h"

Info::Info(QWidget *parent, ModelInformation model_information)
    : QDialog(parent), ui(new Ui::Info), model_information_(model_information) {
  ui->setupUi(this);
  InitializationInfo();
}

Info::~Info() { delete ui; }

void Info::InitializationInfo() {
  QString filename = QString::fromStdString(model_information_.file_name);
  QString edges = QString::number(model_information_.edges_number);
  QString vertices = QString::number(model_information_.vertices_number);
  QString faces = QString::number(model_information_.facetes_number);

  ui->label_filename->setText(filename);
  ui->label_numberOfEdges->setText(edges);
  ui->label_numberOfVertices->setText(vertices);
  ui->label_numberOfFaces->setText(faces);
}
