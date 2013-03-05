#include <QApplication>
#include "mywidget.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MyWidget widget;
  widget.showMaximized();
  return app.exec();
}
