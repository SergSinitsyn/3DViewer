#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_toolButton_xNeg_clicked() {
  ui->widget->move(-(ui->doubleSpinBox_move_x->value()), 0, 0);
  ui->statusbar->showMessage("negative movement on axis x");
}

void MainWindow::on_toolButton_xPos_clicked() {
  ui->widget->move((ui->doubleSpinBox_move_x->value()), 0, 0);
  ui->statusbar->showMessage("positive movement on axis x");
}

void MainWindow::on_toolButton_yNeg_clicked() {
  ui->widget->move(0, -(ui->doubleSpinBox_move_y->value()), 0);
  ui->statusbar->showMessage("negative movement on axis y");
}

void MainWindow::on_toolButton_yPos_clicked() {
  ui->widget->move(0, (ui->doubleSpinBox_move_y->value()), 0);
  ui->statusbar->showMessage("positive movement on axis y");
}

void MainWindow::on_toolButton_zNeg_clicked() {
  ui->widget->move(0, 0, -(ui->doubleSpinBox_move_z->value()));
  ui->statusbar->showMessage("negative movement on axis z");
}

void MainWindow::on_toolButton_zPos_clicked() {
  ui->widget->move(0, 0, (ui->doubleSpinBox_move_z->value()));
  ui->statusbar->showMessage("positive movement on axis z");
}
