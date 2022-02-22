TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CPlusPlusUnits.cpp \
        CSharpUnits.cpp \
        JavaUnits.cpp \
        Units.cpp \
        main.cpp

HEADERS += \
    CPlusPlusCodeGenerator.h \
    CPlusPlusUnits.h \
    CSharpUnits.h \
    ICodeGenerator.h \
    JavaUnits.h \
    Units.h
