#-------------------------------------------------
#
# Project created by QtCreator 2013-05-18T22:24:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WoWdbcViewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbc/DBCFileLoader.cpp \
    dbc/Utilities/EventProcessor.cpp \
    Spells.cpp \
    Spell.cpp \
    SpellEffect.cpp \
    SpellAttribute.cpp

HEADERS  += mainwindow.h \
    dbc/SharedDefines.h \
    dbc/DBCStore.h \
    dbc/DBCfmt.h \
    dbc/DBCFileLoader.h \
    dbc/DBCEnums.h \
    dbc/Platform/Define.h \
    dbc/Platform/CompilerDefs.h \
    dbc/Utilities/UnorderedMapSet.h \
    dbc/Utilities/TypeList.h \
    dbc/Utilities/LinkedList.h \
    dbc/Utilities/EventProcessor.h \
    dbc/Utilities/Callback.h \
    dbc/Utilities/ByteConverter.h \
    dbc/Utilities/LinkedReference/RefManager.h \
    dbc/Utilities/LinkedReference/Reference.h \
    Spells.h \
    Spell.h \
    dbc/DBCStructures.h \
    SpellEffect.h \
    SpellAttribute.h

FORMS    += mainwindow.ui
