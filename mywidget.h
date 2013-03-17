#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QLineEdit>
#include <QFrame>
#include <QTableView>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QAbstractItemModel>
#include <QItemSelectionModel>
#include <QQueue>
#include <QPointF>
#include <QGraphicsScene>
#include <QGraphicsView>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget* parent=0);
    void setTitle(QString);
    void setXLabel(QString);
    void setYLabel(QString);
    QString getTitle();
    QString getXLabel();
    QString getYLabel();

private slots:
    void newChart();
    void open();
    bool save();
    bool saveAs();
    void about();
    void add();
    void remove();
    void changingModel();
    void beforeDraw();

private:
    QMenuBar* menuBar;
    QMenu* fileMenu;
    QMenu* helpMenu;
    QAction* newAct;
    QAction* openAct;
    QAction* saveAct;
    QAction* saveAsAct;
    QAction* exitAct;
    QAction* aboutAct;
    QAction* aboutQtAct;

    QGraphicsScene* scene;
    QGraphicsView* view;
    QLabel* titleLabel;
    QLabel* xLabel;
    QLabel* yLabel;
    QLineEdit* titleEdit;
    QLineEdit* xEdit;
    QLineEdit* yEdit;
    QFrame* separator1;
    QFrame* separator2;
    QFrame* separator3;
    QTableView* table;
    QPushButton* addRow;
    QPushButton* removeRow;
    QPushButton* draw;
    QGroupBox* chartBox;
    QRadioButton* line;
    QRadioButton* bar;
    QRadioButton* pie;
    QVBoxLayout* vBox;
    QGridLayout* desk;
    QAbstractItemModel* model;
    QItemSelectionModel* selectionModel;

    QQueue<QPointF> qPoint;
    QString fileName;
    bool modelIsChanged;
    int typeData;

    void createActions();
    void createMenus();
    void createModel();
    void createDataWidget();
    void createView();
    void createDxBar();
    void connectSignalSlot();
    bool maybeSave();
    void resetModified();
    void showRadioButton();
};

#endif
