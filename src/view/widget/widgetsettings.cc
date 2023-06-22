#include "widgetsettings.h"

#include <QCoreApplication>
#include <QSettings>

using namespace s21;

Q_DECLARE_METATYPE(Element);
Q_DECLARE_METATYPE(LineType);
Q_DECLARE_METATYPE(ProjectionType);
Q_DECLARE_METATYPE(DisplayMethod);

namespace s21 {

void WidgetSettings::LoadSettingsFromFile() {
  QString settings_path = QCoreApplication::applicationDirPath() + "/" +
                          QCoreApplication::applicationName() + ".conf";
  QSettings settings_file(settings_path, QSettings::IniFormat);
  settings_file.beginGroup("WidgetParameters");
  setEdgeThickness(settings_file.value("edgeThickness", 1).toInt());
  setVertexSize(settings_file.value("vertexSize", 1).toInt());
#ifdef Q_OS_LINUX
  setDisplayVertexes(
      settings_file.value("displayMethod", kCircle).value<DisplayMethod>());
  setProjection(
      settings_file.value("projectionType", kCentral).value<ProjectionType>());
  setLineType(settings_file.value("lineType", kSolid).value<LineType>());
#else
  setDisplayVertexes(static_cast<DisplayMethod>(
      settings_file.value("displayMethod", kCircle).toInt()));
  setProjection(static_cast<ProjectionType>(
      settings_file.value("projectionType", kCentral).toInt()));
  setLineType(
      static_cast<LineType>(settings_file.value("lineType", kSolid).toInt()));
#endif

  setBackgroundColor(settings_file.value("backgroundColor", QColor(Qt::yellow))
                         .value<QColor>());
  setVertexColor(
      settings_file.value("vertexColor", QColor(Qt::black)).value<QColor>());
  setEdgeColor(
      settings_file.value("edgeColor", QColor(Qt::red)).value<QColor>());
  int size = settings_file.beginReadArray("Recent");
  for (int i = 0; i < size; i++) {
    settings_file.setArrayIndex(i);
    recent_files_.append(settings_file.value("Name").toString());
  }
  settings_file.endArray();
  settings_file.endGroup();
}

void WidgetSettings::SaveSettingsToFile() {
  const auto settings_path = QCoreApplication::applicationDirPath() + "/" +
                             QCoreApplication::applicationName() + ".conf";
  QSettings settings_file(settings_path, QSettings::IniFormat);

  settings_file.beginGroup("WidgetParameters");
  settings_file.setValue("edgeThickness", edgeThickness());
  settings_file.setValue("vertexSize", vertexSize());
  settings_file.setValue("displayMethod", displayVertexes());
  settings_file.setValue("projectionType", projection());
  settings_file.setValue("lineType", lineType());
  settings_file.setValue("backgroundColor", backgroundColor());
  settings_file.setValue("vertexColor", vertexColor());
  settings_file.setValue("edgeColor", edgeColor());

  settings_file.beginWriteArray("Recent");
  for (int i = 0; i < recent_files_.size(); ++i) {
    settings_file.setArrayIndex(i);
    settings_file.setValue("Name", recent_files_.at(i));
  }
  settings_file.endArray();

  settings_file.endGroup();
}

void WidgetSettings::RememberRecentFile(QString name) {
  recent_files_.insert(0, name);
  if (recent_files_.size() > kMaxRecentFiles) recent_files_.removeLast();
}

}  // namespace s21
