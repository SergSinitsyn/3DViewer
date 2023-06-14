#include "widget.h"

#include <QColor>
#include <QElapsedTimer>
#include <QOpenGLFunctions>

// namespace s21 {

Widget::Widget(QWidget *parent) : QOpenGLWidget(parent) {}

Widget::~Widget() {}

void Widget::SetModelData(const ModelData &model_data) {
  model_data_ = model_data;
  model_is_load_ = true;
}

void Widget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void Widget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void Widget::paintGL() {
  double widget_width = static_cast<double>(Widget::width());
  double widget_height = static_cast<double>(Widget::height());
  double height = 1, width = 1;
  if (widget_width > widget_height) {
    width = widget_width / widget_height;
  } else {
    height = widget_height / widget_width;
  }

  setBgColor();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  if (settings.projection == CENTRAL)
    glFrustum(-width, width, -height, height, 3, 10);
  else
    glOrtho(-width, width, -height, height, 3, 10);

  glTranslatef(0.0, 0.0, -8.0);

  glEnableClientState(GL_VERTEX_ARRAY);
  QElapsedTimer time;  //!
  time.start();        //!
  PaintImage();
  qDebug() << time.elapsed() << "msec, " << time.nsecsElapsed()
           << "nanosec";  //!
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Widget::PaintImage() {
  if (!model_is_load_) {
    return;
  }

  glVertexPointer(3, GL_DOUBLE, 0, model_data_.vertices.data() - 3);
  if (settings.line == DASHED) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00F0);
  }
  setDrawColor(LINE);
  setDrawSize(LINE);

  glDrawElements(GL_LINES, model_data_.edges.size(), GL_UNSIGNED_INT,
                 model_data_.edges.data());
  glDisable(GL_LINE_STIPPLE);

  if (settings.displayVertexes != NONE) {
    if (settings.displayVertexes == CIRCLE) {
      glEnable(GL_POINT_SMOOTH);
      //  glEnable(GL_BLEND);
      //  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    setDrawColor(VERTEX);
    setDrawSize(VERTEX);
    glDrawArrays(GL_POINTS, 0, model_data_.vertices.size() / 3);  //!
    glDisable(GL_POINT_SMOOTH);
    // glDisable(GL_BLEND);
  }
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

// };  // namespace s21
