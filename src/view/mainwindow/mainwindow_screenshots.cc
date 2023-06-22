#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QSettings>
#include <QTimerEvent>

#include "../info/info.h"
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
    QString extension = QFileInfo(file_name).suffix();
    if (extension == "") {
      extension = "jpg";
      file_name += "." + extension;
    }
    if (extension == "bmp" || extension == "jpg" || extension == "jpeg") {
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

int MainWindow::ValidateGifFilename() {
  int result = kRetryScreenCast;
  QString extension = QFileInfo(gif_file_name_).suffix();
  if (gif_file_name_.isEmpty()) {
    // User canceled the dialog
    result = kCancelScreenCast;
  } else if (extension == "gif") {
    result = kMaxFrames;
  } else if (extension == "") {
    gif_file_name_ += ".gif";
    result = kMaxFrames;
  }
  return result;
}
void MainWindow::on_pushButton_record_clicked() {
  static QString button_text = ui_->pushButton_record->text();
  start_recording_ = !start_recording_;
  if (start_recording_) {
    ui_->pushButton_record->setText("Recording...");
    ui_->pushButton_record->setEnabled(false);
    frames_ = kRetryScreenCast;
    do {
      gif_file_name_ = QFileDialog::getSaveFileName(
          this, "Record GIF animation file", "./", ".gif (*.gif)");
      frames_ = ValidateGifFilename();
      if (frames_ == kRetryScreenCast)
        frames_ = FileNameErrorDialog(
                      "To record video use filename with .gif extension") ==
                          QMessageBox::Ok
                      ? kRetryScreenCast
                      : kCancelScreenCast;
    } while (frames_ == kRetryScreenCast);
    connect(&record_timer_, SIGNAL(timeout()), this, SLOT(RecordTimerAlarm()));
    record_timer_.start(100);
  } else {  // End Recording
    ui_->pushButton_record->setText(button_text);
    ui_->pushButton_record->setEnabled(true);
    record_timer_.stop();
    disconnect(&record_timer_, nullptr, this, nullptr);
  }
}

void MainWindow::RecordTimerAlarm() {
  const int kWidth = 640;
  const int kHeight = 480;
  const int kDelay = 10;
  if (frames_ == kMaxFrames) {
    ganim_.GifBegin(&gwriter_, gif_file_name_.toLocal8Bit().data(), kWidth,
                    kHeight, kDelay);
  }
  if (frames_ > 0) {
    // Capture the current frame from the widget and scale it to the desired
    // width and height while keeping the aspect ratio.
    QImage frame_scaled =
        ui_->widget->grabFramebuffer()
            .scaled(kWidth, kHeight, Qt::KeepAspectRatioByExpanding)
            .convertToFormat(QImage::Format_RGBA8888);
    // Center the scaled frame in a rectangle of the desired size and cut edges
    QRect gif_size(0, 0, kWidth, kHeight);
    gif_size.moveCenter(frame_scaled.rect().center());
    QImage frame = frame_scaled.copy(gif_size);
    ganim_.GifWriteFrame(&gwriter_, frame.constBits(), kWidth, kHeight, kDelay);
    --frames_;
    ui_->pushButton_record->setText(
        QString("Frame %1").arg(kMaxFrames - frames_));
  } else {
    if (frames_ == kEndScreenCast) {
      ganim_.GifEnd(&gwriter_);
    }
    on_pushButton_record_clicked();
  }
}
};  // namespace s21
