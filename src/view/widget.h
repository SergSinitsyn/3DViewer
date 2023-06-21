#ifndef WIDGET_H
#define WIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QDebug>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "../other/structs.h"
#include "widgetsettings.h"

namespace s21 {

class Widget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget();
  void SetModelData(const ModelData &model_data);

 private slots:
  void GetSettings(WidgetSettings *sptr);

 protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
  void setBgColor();
  void PaintImage();
  void setDrawColor(Element e);
  void setDrawSize(Element e);

 private:
  ModelData model_data_;
  bool model_is_load_ = false;
  WidgetSettings settings_;
};

};  // namespace s21

#endif  // WIDGET_H
