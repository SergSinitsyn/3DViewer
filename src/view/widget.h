#ifndef WIDGET_H
#define WIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QDebug>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "../other/structs.h"
#include "widgetsettings.h"

// typedef enum { LINE, VERTEX } Element;

// typedef enum { SOLID, DASHED } Line_type;

// typedef enum { PARALLEL, CENTRAL } Projection_type;

// typedef enum { NONE, CIRCLE, SQUARE } Display_method;

// typedef struct {
//   QColor vertexColor;
//   QColor edgeColor;
//   QColor backgroundColor;
//   int edgeThickness;
//   int vertexSize;
//   Display_method displayVertexes;
//   Projection_type projection;
//   Line_type line;
// } widgetSettings;

// namespace s21 {

class Widget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget();
  void SetModelData(const ModelData &model_data);

 private slots:
  void getSettings(WidgetSettings *sptr);

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
  WidgetSettings settings;
};

// };  // namespace s21

#endif  // WIDGET_H
