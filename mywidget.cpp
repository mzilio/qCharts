#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QHeaderView>
#include <QStandardItemModel>
#include "MyWidget.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "CheckData.h"
#include "NormValue.h"

MyWidget::MyWidget(QWidget* parent) : QWidget(parent) {
    modelIsChanged=false;
    typeData=-1;
    createActions();
    createMenus();
    createModel();
    createDataWidget();
    createView();
    createDxBar();
    connectSignalSlot();
}

void MyWidget::newChart() {
    if(maybeSave()) {
        titleEdit->clear();
        xEdit->clear();
        yEdit->clear();
        createModel();
        createView();
        canvas->setVariable(0, "", typeData, 0);
        canvas->draw();
        resetModified();
        showRadioButton();
    }
}

void MyWidget::open() {
    if(maybeSave()) {
        fileName = QFileDialog::getOpenFileName(this, tr("Open qCharts File"), QDir::currentPath(), tr("qCharts Files (*.xml)"));
        if(!fileName.isEmpty()) {
            FileReader reader(fileName, model, this);
            reader.read();
        }
        changingModel();
        resetModified();
    }
}

bool MyWidget::save() {
    if(fileName.isEmpty())
        return saveAs();
    else {
        FileWriter writer(fileName, model, this);
        resetModified();
        return true;
    }
}

bool MyWidget::saveAs() {
    fileName = QFileDialog::getSaveFileName(this, tr("Save qCharts File"), QDir::currentPath(), tr("qCharts Files (*.xml)"));
    if(fileName.isEmpty())
        return false;
    FileWriter writer(fileName, model, this);
    resetModified();
    return true;
}

void MyWidget::about() { //TODO write something smart for about()
    QMessageBox::about(this, tr("About qCharts"), tr("That's all Folks!"));
}

void MyWidget::add() {
    model->insertRow(model->rowCount());
}

void MyWidget::remove() {
    model->removeRow((model->rowCount())-1);
}

void MyWidget::changingModel() {
    modelIsChanged=true;
    CheckData data(model, typeData);
    if(typeData==-1) {
        line->setVisible(false);
        bar->setVisible(false);
        pie->setVisible(false);
    }
    else if(typeData==0 || typeData==1) {
        line->setVisible(false);
        bar->setVisible(true);
        pie->setVisible(true);
    }
    else if(typeData==2) {
        line->setVisible(true);
        bar->setVisible(false);
        pie->setVisible(false);
    }
}

void MyWidget::beforeDraw() {
    QString radio="";
    if(line->isChecked())
        radio="line";
    else if(bar->isChecked())
        radio="bar";
    else if(pie->isChecked())
        radio="pie";
    model->sort(0);
    NormValue norm(&qPoint, model, typeData);
    canvas->setVariable(&qPoint, radio, typeData, model);
    canvas->draw();
}

void MyWidget::createActions() {
    newAct = new QAction(tr("&New"), this);
    openAct = new QAction(tr("&Open..."), this);
    saveAct = new QAction(tr("&Save"), this);
    saveAsAct = new QAction(tr("Save &as..."), this);
    exitAct = new QAction(tr("&Exit"), this);
    aboutAct = new QAction(tr("&About"), this);
    aboutQtAct = new QAction(tr("About &Qt"), this);
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

void MyWidget::createModel() {
    model = new QStandardItemModel(1, 2, this);
    model->setHeaderData(0, Qt::Horizontal, tr("X"));
    model->setHeaderData(1, Qt::Horizontal, tr("Y"));
    connect(model, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(changingModel()));
}

void MyWidget::createDataWidget() {
    canvas = new MyCanvas(this);
    titleLabel = new QLabel(tr("Title:"));
    xLabel = new QLabel(tr("Label x-axis:"));
    yLabel = new QLabel(tr("Label y-axis:"));
    titleEdit = new QLineEdit();
    xEdit = new QLineEdit();
    yEdit = new QLineEdit();
    table = new QTableView;
    addRow = new QPushButton("+");
    removeRow = new QPushButton("-");
    draw = new QPushButton(tr("Draw"));
    chartBox = new QGroupBox(tr("Chart selection"));
    line = new QRadioButton(tr("Line chart"));
    bar = new QRadioButton(tr("Bar chart"));
    pie = new QRadioButton(tr("Pie chart"));
}

void MyWidget::createView() {
    table->setModel(model);
    selectionModel = new QItemSelectionModel(model);
    table->setSelectionModel(selectionModel);
    QHeaderView* headerView = table->horizontalHeader();
    headerView->setStretchLastSection(true);
}

void MyWidget::createDxBar() {
    separator1 = new QFrame();
    separator2 = new QFrame();
    separator3 = new QFrame();
    separator1->setFrameShape(QFrame::HLine);
    separator2->setFrameShape(QFrame::HLine);
    separator3->setFrameShape(QFrame::HLine);
    vBox = new QVBoxLayout;
    vBox->addWidget(line);
    vBox->addWidget(bar);
    vBox->addWidget(pie);
    chartBox->setLayout(vBox);
    desk = new QGridLayout();
    desk->setColumnStretch(0,1);
    desk->addWidget(canvas,0,0,12,1);
    desk->addWidget(titleLabel,0,1,1,2);
    desk->addWidget(titleEdit,1,1,1,2);
    desk->addWidget(separator1,2,1,1,2);
    desk->addWidget(xLabel,3,1,1,2);
    desk->addWidget(xEdit,4,1,1,2);
    desk->addWidget(yLabel,5,1,1,2);
    desk->addWidget(yEdit,6,1,1,2);
    desk->addWidget(separator2,7,1,1,2);
    desk->addWidget(table,8,1,1,2);
    desk->addWidget(addRow,9,1);
    desk->addWidget(removeRow,9,2);
    desk->addWidget(separator3,10,1,1,2);
    desk->addWidget(chartBox,11,1,1,2);
    desk->addWidget(draw,12,1,1,2);
    setLayout(desk);
}

void MyWidget::connectSignalSlot() {
    connect(newAct, SIGNAL(triggered()), this, SLOT(newChart()));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(addRow, SIGNAL(clicked()), this, SLOT(add()));
    connect(removeRow, SIGNAL(clicked()), this, SLOT(remove()));
    connect(draw, SIGNAL(clicked()), this, SLOT(beforeDraw()));
}

bool MyWidget::maybeSave() {
    if(titleEdit->isModified() || xEdit->isModified() || yEdit->isModified() || modelIsChanged) {
        QMessageBox::StandardButton saveFirst;
        saveFirst = QMessageBox::warning(this, tr("qCharts"), tr("Data has been modified.\nDo you want to save changes?"), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if(saveFirst == QMessageBox::Save) {
            return save();
        }
        else if(saveFirst == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}

void MyWidget::resetModified() {
    titleEdit->setModified(false);
    xEdit->setModified(false);
    yEdit->setModified(false);
    modelIsChanged=false;
    typeData=-1;
}

void MyWidget::showRadioButton() {
    line->setVisible(true);
    bar->setVisible(true);
    pie->setVisible(true);
}

void MyWidget::setTitle(QString text) {
    titleEdit->setText(text);
}

void MyWidget::setXLabel(QString text) {
    xEdit->setText(text);
}

void MyWidget::setYLabel(QString text) {
    yEdit->setText(text);
}

QString MyWidget::getTitle() {
    return titleEdit->text();
}

QString MyWidget::getXLabel() {
    return xEdit->text();
}

QString MyWidget::getYLabel() {
    return yEdit->text();
}
