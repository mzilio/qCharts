#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QWidget>
#include <QFile>
#include <QAbstractItemModel>
#include "MyWidget.h"

class FileWriter : public QWidget {

public:
    FileWriter(QString, QAbstractItemModel*, MyWidget*);

private:
    QFile file;
    QAbstractItemModel* model;
    MyWidget* parent;
};

#endif
