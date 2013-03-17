TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

HEADERS += MyWidget.h \
    FileReader.h \
    FileWriter.h \
    CheckData.h \
    NormValue.h \
    LineChart.h

SOURCES += main.cpp MyWidget.cpp \
    FileReader.cpp \
    FileWriter.cpp \
    CheckData.cpp \
    NormValue.cpp \
    LineChart.cpp

TRANSLATIONS = lang/qCharts_it.ts

QT += xml xmlpatterns
