#-------------------------------------------------
#
# Project created by QtCreator 2015-08-24T15:21:26
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlowGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    FlowSource.cpp \
    GameAudioPlayer.cpp \
    GameBlock.cpp \
    GameSetting.cpp \
    MouseState.cpp \
    Pipe.cpp \
    PipeManager.cpp \
    PipePainter.cpp \
    GameController.cpp \
    GamePanel.cpp \
    MyPainter.cpp \
    ViewComponent/gameinfoviewer.cpp \
    ViewComponent/gamebutton.cpp \
    ViewComponent/gameviewpanel.cpp \
    ViewComponent/gamemessagebox.cpp \
    gamesolver.cpp \
    ViewComponent/gamesizechangebutton.cpp \
    ViewComponent/gamemenuinterface.cpp \
    ViewComponent/gamechoosebox.cpp \
    ViewComponent/gamelevelchooser.cpp

HEADERS  += mainwindow.h \
    GamePanel.h \
    Pipe.h \
    GameSetting.h \
    MouseState.h \
    GameController.h \
    FlowSource.h \
    GameAudioPlayer.h \
    GameBlock.h \
    PipeManager.h \
    PipePainter.h \
    MyPainter.h \
    ViewComponent/gameinfoviewer.h \
    ViewComponent/gamebutton.h \
    ViewComponent/gamemessagebox.h \
    ViewComponent/gameviewpanel.h \
    gamesolver.h \
    ViewComponent/gamesizechangebutton.h \
    ViewComponent/gamemenuinterface.h \
    ViewComponent/gamechoosebox.h \
    ViewComponent/gamelevelchooser.h

FORMS    += mainwindow.ui
