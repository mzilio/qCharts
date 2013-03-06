#include <QMessageBox>
#include "MyWidget.h"

MyWidget::MyWidget(QWidget* parent) : QWidget(parent) {
    createActions();
    createMenus();



  QLabel* titleLabel = new QLabel();
  titleLabel->setText(tr("Title:"));
  QLineEdit* titleEdit = new QLineEdit();

  QFrame* myFrame1 = new QFrame();
  myFrame1->setFrameShape(QFrame::HLine);

  QLabel* xLabel = new QLabel();
  xLabel->setText(tr("Label x-axis:"));
  QLineEdit* xEdit = new QLineEdit();
  QLabel* yLabel = new QLabel();
  yLabel->setText(tr("Label y-axis:"));
  QLineEdit* yEdit = new QLineEdit();

  QFrame* myFrame2 = new QFrame();
  myFrame2->setFrameShape(QFrame::HLine);

  QTableWidget* tableWidget = new QTableWidget(10, 2, this);
  QStringList axisLabel = (QStringList() << "X" << "Y");
  tableWidget->setHorizontalHeaderLabels(axisLabel);

  //tableWidget->verticalHeader()->hide();
  //Richiede QHeaderViews

  tableWidget->setAlternatingRowColors(true);
  tableWidget->setFixedSize(217, 250);

  QPushButton* add = new QPushButton("+");
  QPushButton* remove = new QPushButton("-");

  QFrame* myFrame3 = new QFrame();
  myFrame3->setFrameShape(QFrame::HLine);

  QGroupBox *chartBox = new QGroupBox(tr("Chart selection"));
  QRadioButton *line = new QRadioButton(tr("Line chart"));
  QRadioButton *bar = new QRadioButton(tr("Bar chart"));
  QRadioButton *pie = new QRadioButton(tr("Pie chart"));
  line->setChecked(true);
  QVBoxLayout *vbox = new QVBoxLayout;
  vbox->addWidget(line);
  vbox->addWidget(bar);
  vbox->addWidget(pie);
  chartBox->setLayout(vbox);

  QPushButton* draw = new QPushButton(tr("Draw"));

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
  desk->addWidget(chartBox,11,1,1,2);
  desk->addWidget(draw,12,1,1,2);
  setLayout(desk);
}

void MyWidget::newChart() {

}

void MyWidget::open() {

}

void MyWidget::save() {

}

void MyWidget::saveAs() {

}

void MyWidget::about() {
    QMessageBox::about(this, tr("About qCharts"), tr("!!Bye Bye!!"));
}

void MyWidget::add() {

}

void MyWidget::remove() {

}

void MyWidget::createActions() {
    newAct = new QAction(tr("&New"), this);
    connect(newAct, SIGNAL(triggered()), this, SLOT(newChart()));
    openAct = new QAction(tr("&Open..."), this);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    saveAct = new QAction(tr("&Save"), this);
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));
    saveAsAct = new QAction(tr("Save &as..."), this);
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));
    exitAct = new QAction(tr("&Exit"), this);
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MyWidget::createMenus() {
    fileMenu = new QMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    helpMenu = new QMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    menuBar = new QMenuBar();
    menuBar->addMenu(fileMenu);
    menuBar->addSeparator();
    menuBar->addMenu(helpMenu);
}
