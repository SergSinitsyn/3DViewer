#include "info.h"

#include <libgen.h>

#include "ui_info.h"

Info::Info(QWidget *parent, const obj_data *data)
    : QDialog(parent), ui(new Ui::Info) {
  ui->setupUi(this);
  Info::initialization_info(data);
}
Info::~Info() { delete ui; }

void Info::initialization_info(const obj_data *data) {
  QString filemane = basename(data->name_file);
  QString numberOfEdges = QString("%L1").arg(data->number_of_edges);
  QString numberOfVertices = QString("%L1").arg(data->number_of_vertex);
  QString numberOfFaces = QString("%L1").arg(data->number_of_facetes);

  ui->label_filename->setText(filemane);
  ui->label_numberOfEdges->setText(numberOfEdges);
  ui->label_numberOfVertices->setText(numberOfVertices);
  ui->label_numberOfFaces->setText(numberOfFaces);
}
