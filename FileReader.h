#ifndef FILEREADER_H
#define FILEREADER_H

#include <QWidget>
#include <QFile>
#include <QDomElement>
#include <QAbstractItemModel>
#include "MyWidget.h"

class FileReader : public QWidget {

public:
    FileReader(QString, QAbstractItemModel*, MyWidget*);
    void read();

private:
    bool isReadable;

    MyWidget* parent;
    QFile file;
    QAbstractItemModel* model;

    void parseDocument(const QDomElement&);
    void readTitle(const QDomElement&);
    void readXLabel(const QDomElement&);
    void readYLabel(const QDomElement&);
};

#endif
