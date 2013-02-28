#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
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

  QTableWidget* tableWidget = new QTableWidget(10, 2, this);
  QStringList axisLabel = (QStringList() << "X" << "Y");
  tableWidget->setHorizontalHeaderLabels(axisLabel);
  tableWidget->verticalHeader()->hide();
  tableWidget->setAlternatingRowColors(true);
  tableWidget->setFixedSize(217, 300);

  QHBoxLayout* desk = new QHBoxLayout();
  desk->addWidget(tableWidget);
  setLayout(desk);
}
