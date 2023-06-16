#ifndef WIDGETSETTINGS_H
#define WIDGETSETTINGS_H

#include <QColor>
#include <QObject>

typedef enum { kLine, kVertex } Element;

typedef enum { kSolid, kDashed } LineType;

typedef enum { kParallel, kCentral } ProjectionType;

typedef enum { kNone, kCircle, kSquare } DisplayMethod;

class WidgetSettings {
 public:
  static const int kMaxRecentFiles = 5;

  // Getters&setters
  QColor& vertexColor() { return vertex_color_; };
  QColor& edgeColor() { return edge_color_; };
  QColor& backgroundColor() { return background_color_; };
  int& edgeThickness() { return edge_thickness_; };
  int& vertexSize() { return vertex_size_; };
  DisplayMethod& displayVertexes() { return display_vertexes_; };
  ProjectionType& projection() { return projection_; };
  LineType& lineType() { return line_type_; };

  // Other methods
  void LoadSettingsFromFile();
  void SaveSettingsToFile();
  void RememberRecentFile(QString);
  const QVector<QString>* const GetRecentFiles() const {
    return &recent_files_;
  };

 signals:

 protected:
  QColor vertex_color_{Qt::black};
  QColor edge_color_{Qt::red};
  QColor background_color_{Qt::yellow};
  int edge_thickness_{1};
  int vertex_size_{1};
  DisplayMethod display_vertexes_{kCircle};
  ProjectionType projection_{kParallel};
  LineType line_type_{kSolid};
  QVector<QString> recent_files_;
};

// Pattern Xranitel
template <class T>
class Memento {
 public:
  Memento(const T& s) { state_ = s; };
  Memento(const T* s) { state_ = *s; };
  T const* GetState() const { return &state_; };
  void SetState(T* new_state) {
    if (new_state != nullptr && &state_ != new_state) state_ = *new_state;
  };

 protected:
  T state_;
};

#endif  // WIDGETSETTINGS_H
