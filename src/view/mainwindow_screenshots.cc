#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QSettings>
#include <QTimerEvent>

#include "info/info.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace s21 {

int MainWindow::FileNameErrorDialog(const char *msg) {
  QMessageBox msg_box(this);
  msg_box.setText(msg);
  msg_box.setInformativeText("OK - try again \nCancel - return to viewer");
  msg_box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  msg_box.setIcon(QMessageBox::Critical);
  msg_box.setDefaultButton(QMessageBox::Ok);
  return msg_box.exec();
}

void MainWindow::SaveImageAs() {
  QString file_name = QFileDialog::getSaveFileName(this, tr("Save File"), "./",
                                                   tr("Images ( *.bmp *.jpg)"));
  if (!file_name.isEmpty()) {
    if (file_name.right(4) == ".bmp" || file_name.right(4) == ".jpg" ||
        file_name.right(5) == ".jpeg") {
      QImage img = ui_->widget->grabFramebuffer();
      img.save(file_name);
    } else {
      int res = FileNameErrorDialog(
          "To save screenshot use filename with .bmp or .jpg extension");
      if (res == QMessageBox::Ok) SaveImageAs();
    }
  }
}

void MainWindow::on_actionSave_OBJ_to_Image_triggered() { SaveImageAs(); }

void MainWindow::on_pushButton_image_clicked() { SaveImageAs(); }

void MainWindow::on_pushButton_record_clicked() {
  record_ = !record_;
  if (record_) {
    ui_->pushButton_record->setText("Recording...");
    ui_->pushButton_record->setEnabled(false);
    frames_ = 0;
    do {
      gif_file_name_ = QFileDialog::getSaveFileName(
          this, "Record GIF animation file", "./", ".gif (*.gif)");
      if (!gif_file_name_.isEmpty()) {
        if (gif_file_name_.right(4) == ".gif") {
          frames_ = kMaxFrames;
        } else {
          // Warning wrong file name selected
          int res = FileNameErrorDialog(
              "To record video use filename with .gif extension");
          if (res == QMessageBox::Ok)
            frames_ = kRetryScreenCast;
          else
            frames_ = kCancelScreenCast;
        }
      } else {
        frames_ = kCancelScreenCast;
      }
    } while (frames_ != kMaxFrames && frames_ != kCancelScreenCast);
    connect(&record_timer_, SIGNAL(timeout()), this, SLOT(RecordTimerAlarm()));
    record_timer_.start(100);
  } else {
    ui_->pushButton_record->setText("Record");
    ui_->pushButton_record->setEnabled(true);
    record_timer_.stop();
    disconnect(&record_timer_, nullptr, this, nullptr);
  }
}

void MainWindow::RecordTimerAlarm() {
  const int width = 640;
  const int height = 480;
  const int delay = 10;

  if (frames_ == kMaxFrames) {
    ganim_.GifBegin(&gwriter_, gif_file_name_.toLocal8Bit().data(), width,
                    height, delay);
  }
  if (frames_ > 0) {
    QImage frame_scaled =
        ui_->widget->grabFramebuffer()
            .scaled(width, height, Qt::KeepAspectRatioByExpanding)
            .convertToFormat(QImage::Format_RGBA8888);
    QRect gif_size(0, 0, width, height);
    gif_size.moveCenter(frame_scaled.rect().center());
    QImage frame = frame_scaled.copy(gif_size);

    ganim_.GifWriteFrame(&gwriter_, frame.constBits(), width, height, delay);
    --frames_;
    QString frame_number;
    ui_->pushButton_record->setText(
        QString("Frame ").append(frame_number.setNum(kMaxFrames - frames_)));
  } else {
    if (frames_ == kEndScreenCast) ganim_.GifEnd(&gwriter_);
    on_pushButton_record_clicked();
  }
}

};  // namespace s21
