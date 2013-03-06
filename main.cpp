#include <QApplication>
#include <QString>
#include <QLocale>
#include <QTranslator>
#include "MyWidget.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QTranslator translator;
  //QString locale = QLocale::system().name();
  //cout << translator.load(QString("qCharts_") + locale, "/");
  translator.load("qCharts_it", app.applicationDirPath());
  app.installTranslator(&translator);
  MyWidget widget;
  widget.showMaximized();
  return app.exec();
}
