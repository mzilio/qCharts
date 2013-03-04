#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QFrame>
#include <QGridLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QLineEdit>
#include <QLabel>
#include "mywidget.h"

MyWidget::MyWidget(QWidget* parent) : QWidget(parent) {
  QMenuBar* menubar = new QMenuBar();
  QMenu* file = new QMenu("&File");
  file->addAction("New");
  file->addAction("Open");
  file->addAction("Save");
  QMenu* about = new QMenu("&About");

  menubar->addMenu(file);
  menubar->addMenu(about);

  QLabel* titleLabel = new QLabel();
  titleLabel->setText("Title:");
  QLineEdit* titleEdit = new QLineEdit();

  QFrame* myFrame1 = new QFrame();
  myFrame1->setFrameShape(QFrame::HLine);

  QLabel* xLabel = new QLabel();
  xLabel->setText("Label x-axis:");
  QLineEdit* xEdit = new QLineEdit();
  QLabel* yLabel = new QLabel();
  yLabel->setText("Label y-axis:");
  QLineEdit* yEdit = new QLineEdit();

  QFrame* myFrame2 = new QFrame();
  myFrame2->setFrameShape(QFrame::HLine);

  QTableWidget* tableWidget = new QTableWidget(10, 2, this);
  QStringList axisLabel = (QStringList() << "X" << "Y");
  tableWidget->setHorizontalHeaderLabels(axisLabel);
  tableWidget->verticalHeader()->hide();
  tableWidget->setAlternatingRowColors(true);
  tableWidget->setFixedSize(217, 300);

  QPushButton* add = new QPushButton("+");
  QPushButton* remove = new QPushButton("-");

  QFrame* myFrame3 = new QFrame();
  myFrame3->setFrameShape(QFrame::HLine);

  QPushButton* draw = new QPushButton("Draw");

  QGridLayout* desk = new QGridLayout();
  desk->setColumnStretch(0,1);
  desk->addWidget(titleLabel,0,1,1,2);
  desk->addWidget(titleEdit,1,1,1,2);
  desk->addWidget(myFrame1,2,1,1,2);
  desk->addWidget(xLabel,3,1,1,2);
  desk->addWidget(xEdit,4,1,1,2);
  desk->addWidget(yLabel,5,1,1,2);
  desk->addWidget(yEdit,6,1,1,2);
  desk->addWidget(myFrame2,7,1,1,2);
  desk->addWidget(tableWidget,8,1,1,2);
  desk->addWidget(add,9,1);
  desk->addWidget(remove,9,2);
  desk->addWidget(myFrame3,10,1,1,2);
  desk->addWidget(draw,11,1,1,2);
  setLayout(desk);
}
