#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QPushButton>
#include <QWidget>

class MyWidget : public QWidget {
 private:
  QPushButton* buttonOpen;
  QPushButton* buttonSave;
 public:
  MyWidget(QWidget* parent=0);
};

#endif
