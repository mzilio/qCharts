#ifndef FILEREADER_H
#define FILEREADER_H

#include <QWidget>
#include <QFile>
#include <QXmlStreamReader>
#include "MyWidget.h"

class FileReader : public QWidget {

public:
    FileReader(QString, MyWidget*);
    bool read();

private:
    bool isReadable;

    MyWidget* parent;
    QFile file;
    QXmlStreamReader xin;

    void readTitle();
    void readXLabel();
    void readYLabel();
};

#endif
