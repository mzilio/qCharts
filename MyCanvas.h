#ifndef MYCANVAS_H
#define MYCANVAS_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QQueue>
#include <QPointF>

class MyCanvas : public QWidget {
    Q_OBJECT

public:
    MyCanvas(QWidget* parent=0);
    void setVariable(QQueue<QPointF>*, QString, int, QAbstractItemModel*);

public slots:
    void draw();

protected:
    void paintEvent(QPaintEvent*);

private:
    QQueue<QPointF>* qPoint;
    QAbstractItemModel* model;
    QString radio;
    int typeData;
};

#endif
