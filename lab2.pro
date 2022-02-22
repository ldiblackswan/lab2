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
    CSharpCodeGenerator.h \
    CSharpUnits.h \
    ICodeGenerator.h \
    JavaCodeGenerator.h \
    JavaUnits.h \
    Units.h
