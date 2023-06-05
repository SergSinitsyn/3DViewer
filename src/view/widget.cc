#include "widget.h"

#include <QColor>
#include <QElapsedTimer>
#include <QOpenGLFunctions>

Widget::Widget(QWidget *parent) : QOpenGLWidget(parent) {}

Widget::~Widget() {
  if (ModelIsLoad) remove_data(&A);  // TODO удаление данных?
}

void Widget::setBgColor() {
#ifdef Q_OS_LINUX
  qreal r, g, b, f;
#else
  float r, g, b, f;
#endif
  settings.backgroundColor.getRgbF(&r, &g, &b, &f);
  glClearColor(r, g, b, f);
}

void Widget::setDrawColor(element e) {
#ifdef Q_OS_LINUX
  qreal r, g, b, f;
#else
  float r, g, b, f;
#endif
  switch (e) {
    case LINE:
      settings.edgeColor.getRgbF(&r, &g, &b, &f);
      break;
    case VERTEX:
      settings.vertexColor.getRgbF(&r, &g, &b, &f);
      break;
  }
  glColor3d(r, g, b);
}

void Widget::setDrawSize(element e) {
  switch (e) {
    case LINE:
      glLineWidth(settings.edgeThickness);
      break;
    case VERTEX:
      glPointSize(settings.vertexSize);
      break;
  }
}

void Widget::getSettings(widgetSettings *sptr) {
  settings = *sptr;
  update();
}

int Widget::loadFile(QString *fileName) {
  if (ModelIsLoad || objFileName != "") remove_data(&A);
  ModelIsLoad = obj_in_data(&A, (char *)(*fileName).toLocal8Bit().data());
  setFileName(*fileName);
  update();
  return ModelIsLoad;
}

void Widget::initializeGL() {
  initializeOpenGLFunctions();
  //  glViewport(0, 0, width(), height());
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void Widget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  //  float aspect = w / (float)h;
  //  m_projectionMatrix.setToIdentity();  // единичная
  //  m_projectionMatrix.perspective(45, aspect, 0.1f,
  //                                 10.0f);  // матрица задания перспективы
}

void Widget::paintGL() {
  double width = static_cast<double>(Widget::width());
  double height = static_cast<double>(Widget::height());
  double h = 1, w = 1;
  if (width > height) {
    w = width / height;
  } else {
    h = height / width;
  }

  setBgColor();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  if (settings.projection == CENTRAL)
    glFrustum(-w, w, -h, h, 3, 10);
  else
    glOrtho(-w, w, -h, h, 3, 10);

  glTranslatef(0.0, 0.0, -8.0);

  glEnableClientState(GL_VERTEX_ARRAY);

  QElapsedTimer time;
  time.start();
  paintImage();
  qDebug() << time.elapsed() << "msec, " << time.nsecsElapsed() << "nanosec";

  glDisableClientState(GL_VERTEX_ARRAY);
}

void Widget::paintImage() {
  if (ModelIsLoad) {
    glVertexPointer(3, GL_DOUBLE, 0, &A.matrix_3d.matrix[1][0]);
    if (settings.line == DASHED) {
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x00F0);
    }
    setDrawColor(LINE);
    setDrawSize(LINE);
    glDrawElements(GL_LINES, 2 * A.number_of_edges, GL_UNSIGNED_INT, A.edges);
    glDisable(GL_LINE_STIPPLE);

    if (settings.displayVertexes != NONE) {
      if (settings.displayVertexes == CIRCLE) {
        glEnable(GL_POINT_SMOOTH);
        //          glEnable(GL_BLEND);
        //          glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      }
      setDrawColor(VERTEX);
      setDrawSize(VERTEX);
      glDrawArrays(GL_POINTS, 0, A.number_of_vertex);
      glDisable(GL_POINT_SMOOTH);
      //        glDisable(GL_BLEND);
    }
  }
}

// этих функций тут не должно быть

void Widget::rotate(int x_angle, int y_angle, int z_angle) {
  if (ModelIsLoad) {
    rotation_model(&A, x_angle, y_angle, z_angle);
    update();
  }
}

void Widget::move(double x_shift, double y_shift, double z_shift) {
  if (ModelIsLoad) {
    model_shift(&A, x_shift, y_shift, z_shift);
    update();
  }
}

void Widget::scale(double scaling) {
  if (ModelIsLoad) {
    model_scaling(&A, scaling);
    update();
  }
}

double Widget::norm() {
  double a = 1;
  if (ModelIsLoad) {
    a = inscribe(&A);
    a = a * 1.5;
  }
  return a;
}
