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
#include <QTableWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QGridLayout>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget* parent=0);
    void setTitle(QString);
    void setXLabel(QString);
    void setYLabel(QString);

private slots:
    void newChart();
    void open();
    bool save();
    bool saveAs();
    void about();
    void add();
    void remove();
    void tableIsModified();

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

    QLabel* titleLabel;
    QLabel* xLabel;
    QLabel* yLabel;
    QLineEdit* titleEdit;
    QLineEdit* xEdit;
    QLineEdit* yEdit;
    QFrame* separator1;
    QFrame* separator2;
    QFrame* separator3;
    QTableWidget* tableWidget;
    QPushButton* addRow;
    QPushButton* removeRow;
    QPushButton* draw;
    QGroupBox* chartBox;
    QRadioButton* line;
    QRadioButton* bar;
    QRadioButton* pie;
    QVBoxLayout* vBox;
    QGridLayout* desk;

    bool tableChanged;

    void createActions();
    void createMenus();
    void createDataWidget();
    void createDxBar();
    void connectSignalSlot();
    bool maybeSave();
    void resetModified();
};

#endif
