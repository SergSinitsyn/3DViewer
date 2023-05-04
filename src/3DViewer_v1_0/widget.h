#ifndef WIDGET_H
#define WIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QMatrix4x4>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

typedef enum { LINE, VERTEX } element;

typedef enum { SOLID, DASHED } Line_type;

typedef enum { PARALLEL, CENTRAL } Projection_type;

typedef enum { NONE, CIRCLE, SQUARE } Display_method;

extern "C" {
#include "functions/affine_transformations.h"
#include "functions/reading_obj_file.h"
#include "functions/structs.h"
}

struct VertexData {
  VertexData() {}
  VertexData(QVector3D p) : position(p) {}
  QVector3D position;
};

typedef struct {
  QColor vertexColor;
  QColor edgeColor;
  QColor backgroundColor;
  int edgeThickness;
  int vertexSize;
  Display_method displayVertexes;
  Projection_type projection;
  Line_type line;
} widgetSettings;

class Widget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
 public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget();
  int loadFile(QString *);
  void rotate(int x_angle, int y_angle, int z_angle);
  void move(double x_shift, double y_shift, double z_shift);
  void scale(double scaling);
  double norm();
  const obj_data *getObjData() { return &A; };
  const QString *getObjFileName() { return &objFileName; };

 private slots:
  void getSettings(widgetSettings *sptr);

 signals:

 protected:
  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();
  void setBgColor();
  void paintImage();
  void setDrawColor(element e);
  void setDrawSize(element e);

 private:
  QString *setFileName(QString fn) { return &(objFileName = fn); };
  QMatrix4x4 m_projectionMatrix;
  widgetSettings settings;
  int ModelIsLoad = 0;  // by default file is not loaded ModelIsLoad == 0
  obj_data A;
  QString objFileName = "";
};

#endif  // WIDGET_H
