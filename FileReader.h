#ifndef FILEREADER_H
#define FILEREADER_H

#include <QWidget>
#include <QFile>
#include <QDomElement>
#include "MyWidget.h"

class FileReader : public QWidget {

public:
    FileReader(QString, MyWidget*);
    bool read();

private:
    bool isReadable;

    MyWidget* parent;
    QFile file;

    void parseDocument(const QDomElement& element);
    void readTitle(const QDomElement& element);
    void readXLabel(const QDomElement& element);
    void readYLabel(const QDomElement& element);
};

#endif
