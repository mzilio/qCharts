#include <QApplication>
#include <QTranslator>
#include <QString>
#include <QLocale>
#include "MyWidget.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QTranslator translator;
  QString locale = QLocale::system().name();
  translator.load(QString("qCharts_") + locale, "/");
  app.installTranslator(&translator);
  MyWidget widget;
  widget.showMaximized();
  return app.exec();
}
