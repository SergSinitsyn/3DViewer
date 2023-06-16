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
  QMessageBox msgBox(this);
  msgBox.setText(msg);
  msgBox.setInformativeText("OK - try again \nCancel - return to viewer");
  msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  msgBox.setIcon(QMessageBox::Critical);
  msgBox.setDefaultButton(QMessageBox::Ok);
  return msgBox.exec();
}

void MainWindow::SaveImageAs() {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "./",
                                                  tr("Images ( *.bmp *.jpg)"));
  if (!fileName.isEmpty()) {
    if (fileName.right(4) == ".bmp" || fileName.right(4) == ".jpg" ||
        fileName.right(5) == ".jpeg") {
      QImage img = ui_->widget->grabFramebuffer();
      img.save(fileName);
    } else {
      int res = FileNameErrorDialog(
          "To save screenshot use filename with .bmp or .jpg extension");
      if (res == QMessageBox::Ok) SaveImageAs();
    }
  }
}

void MainWindow::on_actionSave_OBJ_to_Image_triggered() { SaveImageAs(); }

void MainWindow::on_pushButton_image_clicked() { SaveImageAs(); }

#define CANCEL_SCREENCAST -1
#define RETRY_SCREENCAST 0
#define MAX_FRAMES 50
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
          frames_ = MAX_FRAMES;
        } else {
          // Warning wrong file name selected
          int res = FileNameErrorDialog(
              "To record video use filename with .gif extension");
          if (res == QMessageBox::Ok)
            frames_ = RETRY_SCREENCAST;
          else
            frames_ = CANCEL_SCREENCAST;
        }
      } else {
        frames_ = CANCEL_SCREENCAST;
      }
    } while (frames_ != MAX_FRAMES && frames_ != CANCEL_SCREENCAST);
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
  int width = 640;
  int height = 480;
  int delay = 10;

  if (frames_ == 50) {
    ganim_.GifBegin(&gwriter_, gif_file_name_.toLocal8Bit().data(), width,
                    height, delay);
  }
  if (frames_ > 0) {
    QImage frame_scaled =
        ui_->widget->grabFramebuffer()
            .scaled(width, height, Qt::KeepAspectRatioByExpanding)
            .convertToFormat(QImage::Format_RGBA8888);
    QRect gifSize(0, 0, width, height);
    gifSize.moveCenter(frame_scaled.rect().center());
    QImage frame = frame_scaled.copy(gifSize);

    ganim_.GifWriteFrame(&gwriter_, frame.constBits(), width, height, delay);
    --frames_;
    QString frNum;
    ui_->pushButton_record->setText(
        QString("Frame ").append(frNum.setNum(50 - frames_)));
  } else {
    if (frames_ == 0) ganim_.GifEnd(&gwriter_);
    on_pushButton_record_clicked();
  }
}

};  // namespace s21
