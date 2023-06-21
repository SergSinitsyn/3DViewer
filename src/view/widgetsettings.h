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
  static const int kMaxRecentFiles = 10;

  // Getters
  const QColor& vertexColor() const { return vertex_color_; };
  const QColor& edgeColor() const { return edge_color_; };
  const QColor& backgroundColor() const { return background_color_; };
  const int& edgeThickness() const { return edge_thickness_; };
  const int& vertexSize() const { return vertex_size_; };
  const DisplayMethod& displayVertexes() const { return display_vertexes_; };
  const ProjectionType& projection() const { return projection_; };
  const LineType& lineType() const { return line_type_; };
  // Setters
  void setVertexColor(const QColor& new_value) { vertex_color_ = new_value; };
  void setEdgeColor(const QColor& new_value) { edge_color_ = new_value; };
  void setBackgroundColor(const QColor& new_value) {
    background_color_ = new_value;
  };
  void setEdgeThickness(const int& new_value) { edge_thickness_ = new_value; };
  void setVertexSize(const int& new_value) { vertex_size_ = new_value; };
  void setDisplayVertexes(const DisplayMethod& new_value) {
    display_vertexes_ = new_value;
  };
  void setProjection(const ProjectionType& new_value) {
    projection_ = new_value;
  };
  void setLineType(const LineType& new_value) { line_type_ = new_value; };

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

#endif  // WIDGETSETTINGS_H