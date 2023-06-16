#include "widgetsettings.h"

#include <QCoreApplication>
#include <QSettings>

Q_DECLARE_METATYPE(Element);
Q_DECLARE_METATYPE(LineType);
Q_DECLARE_METATYPE(ProjectionType);
Q_DECLARE_METATYPE(DisplayMethod);

void WidgetSettings::loadSettingsFromFile() {
  QSettings settingsFile(QCoreApplication::applicationDirPath() + "/" +
                             QCoreApplication::applicationName() + ".conf",
                         QSettings::IniFormat);
  settingsFile.beginGroup("WidgetParameters");
  edgeThickness() = settingsFile.value("edgeThickness", 1).toInt();
  vertexSize() = settingsFile.value("vertexSize", 1).toInt();
  displayVertexes() =
      settingsFile.value("displayMethod", kCircle).value<DisplayMethod>();
  projection() =
      settingsFile.value("projectionType", kCentral).value<ProjectionType>();
  lineType() = settingsFile.value("lineType", kSolid).value<LineType>();
  backgroundColor() =
      settingsFile.value("backgroundColor", QColor(Qt::yellow)).value<QColor>();
  vertexColor() =
      settingsFile.value("vertexColor", QColor(Qt::black)).value<QColor>();
  edgeColor() =
      settingsFile.value("edgeColor", QColor(Qt::red)).value<QColor>();
  int size = settingsFile.beginReadArray("Recent");
  for (int i = 0; i < size; i++) {
    settingsFile.setArrayIndex(i);
    recent_files_.append(settingsFile.value("Name").toString());
  }
  settingsFile.endArray();
  settingsFile.endGroup();
}

void WidgetSettings::saveSettingsToFile() {
  const auto settings_path = QCoreApplication::applicationDirPath() + "/" +
                             QCoreApplication::applicationName() + ".conf";
  QSettings settingsFile(settings_path, QSettings::IniFormat);

  settingsFile.beginGroup("WidgetParameters");
  settingsFile.setValue("edgeThickness", edgeThickness());
  settingsFile.setValue("vertexSize", vertexSize());
  settingsFile.setValue("displayMethod", displayVertexes());
  settingsFile.setValue("projectionType", projection());
  settingsFile.setValue("lineType", lineType());
  settingsFile.setValue("backgroundColor", backgroundColor());
  settingsFile.setValue("vertexColor", vertexColor());
  settingsFile.setValue("edgeColor", edgeColor());

  settingsFile.beginWriteArray("Recent");
  for (int i = 0; i < recent_files_.size(); ++i) {
    settingsFile.setArrayIndex(i);
    settingsFile.setValue("Name", recent_files_.at(i));
  }
  settingsFile.endArray();

  settingsFile.endGroup();
}

void WidgetSettings::rememberRecentFile(QString name) {
  recent_files_.insert(0, name);
  if (recent_files_.size() > kMaxRecentFiles) recent_files_.removeLast();
}