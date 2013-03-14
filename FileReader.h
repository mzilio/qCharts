#ifndef FILEREADER_H
#define FILEREADER_H

#include <QWidget>
#include <QFile>
#include <QAbstractItemModel>
#include <QDomElement>
#include "MyWidget.h"

class FileReader : public QWidget {

public:
    FileReader(QString, QAbstractItemModel*, MyWidget*);
    void read();

private:
    bool isReadable;
    QFile file;
    QAbstractItemModel* model;
    MyWidget* parent;

    void parseDocument(const QDomElement&);
    void readTitle(const QDomElement&);
    void readXLabel(const QDomElement&);
    void readYLabel(const QDomElement&);
};

#endif
