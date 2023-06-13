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

int MainWindow::fileNameErrorDialog(const char *msg) {
  QMessageBox msgBox(this);
  msgBox.setText(msg);
  msgBox.setInformativeText("OK - try again \nCancel - return to viewer");
  msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  msgBox.setIcon(QMessageBox::Critical);
  msgBox.setDefaultButton(QMessageBox::Ok);
  return msgBox.exec();
}

void MainWindow::saveImageAs() {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "./",
                                                  tr("Images ( *.bmp *.jpg)"));
  if (!fileName.isEmpty()) {
    if (fileName.right(4) == ".bmp" || fileName.right(4) == ".jpg" ||
        fileName.right(5) == ".jpeg") {
      QImage img = ui_->widget->grabFramebuffer();
      img.save(fileName);
    } else {
      int res = fileNameErrorDialog(
          "To save screenshot use filename with .bmp or .jpg extension");
      if (res == QMessageBox::Ok) saveImageAs();
    }
  }
}

void MainWindow::on_actionSave_OBJ_to_Image_triggered() { saveImageAs(); }

void MainWindow::on_pushButton_image_clicked() { saveImageAs(); }

#define CANCEL_SCREENCAST -1
#define RETRY_SCREENCAST 0
#define MAX_FRAMES 50
void MainWindow::on_pushButton_record_clicked() {
  record = !record;
  if (record) {
    ui_->pushButton_record->setText("Recording...");
    ui_->pushButton_record->setEnabled(false);
    frames = 0;
    do {
      gifFileName = QFileDialog::getSaveFileName(
          this, "Record GIF animation file", "./", ".gif (*.gif)");
      if (!gifFileName.isEmpty()) {
        if (gifFileName.right(4) == ".gif") {
          frames = MAX_FRAMES;
        } else {
          // Warning wrong file name selected
          int res = fileNameErrorDialog(
              "To record video use filename with .gif extension");
          if (res == QMessageBox::Ok)
            frames = RETRY_SCREENCAST;
          else
            frames = CANCEL_SCREENCAST;
        }
      } else {
        frames = CANCEL_SCREENCAST;
      }
    } while (frames != MAX_FRAMES && frames != CANCEL_SCREENCAST);
    connect(&recordTimer, SIGNAL(timeout()), this, SLOT(recordTimerAlarm()));
    recordTimer.start(100);
  } else {
    ui_->pushButton_record->setText("Record");
    ui_->pushButton_record->setEnabled(true);
    recordTimer.stop();
    disconnect(&recordTimer, nullptr, this, nullptr);
  }
}

void MainWindow::recordTimerAlarm() {
  int width = 640;
  int height = 480;
  int delay = 10;

  if (frames == 50) {
    ganim.GifBegin(&gwriter, gifFileName.toLocal8Bit().data(), width, height,
                   delay);
  }
  if (frames > 0) {
    QImage frame_scaled =
        ui_->widget->grabFramebuffer()
            .scaled(width, height, Qt::KeepAspectRatioByExpanding)
            .convertToFormat(QImage::Format_RGBA8888);
    QRect gifSize(0, 0, width, height);
    gifSize.moveCenter(frame_scaled.rect().center());
    QImage frame = frame_scaled.copy(gifSize);

    ganim.GifWriteFrame(&gwriter, frame.constBits(), width, height, delay);
    --frames;
    QString frNum;
    ui_->pushButton_record->setText(
        QString("Frame ").append(frNum.setNum(50 - frames)));
  } else {
    if (frames == 0) ganim.GifEnd(&gwriter);
    on_pushButton_record_clicked();
  }
}

};  // namespace s21
