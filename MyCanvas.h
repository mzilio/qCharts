#ifndef MYCANVAS_H
#define MYCANVAS_H

#include <QWidget>
#include <QAbstractItemModel>

class MyCanvas : public QWidget {
    Q_OBJECT

public:
    MyCanvas(QWidget* parent=0);
    void setVariable(QString, int, QAbstractItemModel*);

public slots:
    void draw();

protected:
    void paintEvent(QPaintEvent*);

private:
    QAbstractItemModel* model;
    QString radio;
    int typeData;
};

#endif
