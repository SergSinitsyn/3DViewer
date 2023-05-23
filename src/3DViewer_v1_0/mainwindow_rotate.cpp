#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_dial_x_sliderMoved(int new_position) {
  //  RotationController.RotateX(new_position);

  int step = new_position - (ui->spinBox_x->value());
  ui->spinBox_x->setValue(new_position);
  rotate_x(step);
}

void MainWindow::on_dial_y_sliderMoved(int position) {
  int step = position - (ui->spinBox_y->value());
  ui->spinBox_y->setValue(position);
  rotate_y(step);
}

void MainWindow::on_dial_z_sliderMoved(int position) {
  int step = position - (ui->spinBox_z->value());
  ui->spinBox_z->setValue(position);
  rotate_z(step);
}

void MainWindow::on_dial_x_valueChanged(int value) {
  int step = value - (ui->spinBox_x->value());
  ui->spinBox_x->setValue(value);
  rotate_x(step);
}

void MainWindow::on_dial_y_valueChanged(int value) {
  int step = value - (ui->spinBox_y->value());
  ui->spinBox_y->setValue(value);
  rotate_y(step);
}

void MainWindow::on_dial_z_valueChanged(int value) {
  int step = value - (ui->spinBox_z->value());
  ui->spinBox_z->setValue(value);
  rotate_z(step);
}

void MainWindow::on_spinBox_x_editingFinished() {
  int step = (ui->spinBox_x->value()) - (ui->dial_x->value());
  ui->dial_x->setValue(ui->spinBox_x->value());
  rotate_x(step);
}

void MainWindow::on_spinBox_y_editingFinished() {
  int step = (ui->spinBox_y->value()) - (ui->dial_y->value());
  ui->dial_y->setValue(ui->spinBox_y->value());
  rotate_y(step);
}

void MainWindow::on_spinBox_z_editingFinished() {
  int step = (ui->spinBox_z->value()) - (ui->dial_z->value());
  ui->dial_z->setValue(ui->spinBox_z->value());
  rotate_z(step);
}

void MainWindow::rotate_x(int x) {
  ui->widget->Widget::rotate(x, 0, 0);
  ui->statusbar->showMessage("rotation around axis x");
}

void MainWindow::rotate_y(int y) {
  ui->widget->Widget::rotate(0, y, 0);
  ui->statusbar->showMessage("rotation around axis y");
}

void MainWindow::rotate_z(int z) {
  ui->widget->Widget::rotate(0, 0, z);
  ui->statusbar->showMessage("rotation around axis z");
}
