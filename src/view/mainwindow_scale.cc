#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_pushButton_normalize_clicked() {
  double newValue = ui->widget->norm() * old_scale;
  ui->doubleSpinBox_scale->setValue(newValue);
  newScale(newValue);
}

void MainWindow::on_pushButton_scale_clicked() {
  double newValue = ui->doubleSpinBox_scale->value();
  newScale(newValue);
}

void MainWindow::on_doubleSpinBox_scale_editingFinished() {
  double newValue = ui->doubleSpinBox_scale->value();
  newScale(newValue);
}

void MainWindow::on_toolButton_scaleL_clicked() {
  ui->doubleSpinBox_scale->stepDown();
  double newValue = ui->doubleSpinBox_scale->value();
  newScale(newValue);
}

void MainWindow::on_toolButton_scaleH_clicked() {
  ui->doubleSpinBox_scale->stepUp();
  double newValue = ui->doubleSpinBox_scale->value();
  newScale(newValue);
}

void MainWindow::newScale(double newValue) {
  double oldValue = old_scale;
  double scale = newValue / oldValue;
  old_scale = newValue;
  ui->widget->Widget::scale(scale);
  ui->statusbar->showMessage("scale");
}
