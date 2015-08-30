#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GamePanel.h"
#include "GameController.h"
#include "ViewComponent/gamemessagebox.h"
#include "GameSetting.h"

#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gameController(NULL)
{
    ui->setupUi(this);

    gameSetting = new GameSetting(5,1);

    menuInterface = new GameMenuInterface(this);

    menuInterface->show();

    //menuInterface->hide();

    gameLevelChooser = new GameLevelChooser(this);

    gameLevelChooser->hide();

    connect(menuInterface,SIGNAL(StartGame(int,int)), this, SLOT(ChooseLevel(int,int)));
    connect(menuInterface,SIGNAL(ChooseLevelMenu()),this,SLOT(ChooseLevelMenu()));
    connect(gameLevelChooser,SIGNAL(BackToMenu()),this,SLOT(BackToMenu()));
    connect(gameLevelChooser,SIGNAL(StartGame(int,int)),this,SLOT(ChooseLevel(int,int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ChooseLevel(int _level, int _gameNo)
{
    gameSetting = new GameSetting(_level,_gameNo);
    StartGame();
}

void MainWindow::StartGame()
{
    menuInterface->hide();
    gameLevelChooser->hide();
    if(gameController!=NULL)
        gameController->hide();
    useless.push(gameController);
    gameController = new GameController(gameSetting,this);
    gameController->show();
    QObject::connect(gameController->gamePanel,SIGNAL(Retry()),this,SLOT(RetryGame()));
    QObject::connect(gameController->gamePanel,SIGNAL(BackToMenu()),this,SLOT(BackToMenu()));
    QObject::connect(gameController->gamePanel,SIGNAL(NextGame()),this,SLOT(NextGame()));
    QObject::connect(gameController->gamePanel,SIGNAL(PreviousGame()),this,SLOT(PreviousGame()));
    if(useless.size()>5)
    {
        while(useless.size()>2)
        {
            QWidget* widget = useless.front();
            useless.pop();
            if(widget!=NULL)
                delete widget;
        }
    }
    if(uselessSetting.size()>5)
    {
        while(uselessSetting.size()>2)
        {
            GameSetting* setting = uselessSetting.front();
            uselessSetting.pop();
            if(setting!=NULL)
                delete setting;
        }
    }
}

void MainWindow::RetryGame()
{
    uselessSetting.push(gameSetting);
    gameSetting = new GameSetting(gameSetting->level,gameSetting->gameNo);
    StartGame();
}

void MainWindow::NextGame()
{
    uselessSetting.push(gameSetting);
    gameSetting = new GameSetting(GameSetting::getNextGame(*gameSetting));
    StartGame();
}

void MainWindow::PreviousGame()
{
    uselessSetting.push(gameSetting);
    gameSetting = new GameSetting(GameSetting::getPreviousGame(*gameSetting));
    StartGame();
}

void MainWindow::BackToMenu()
{
    menuInterface->show();
    gameLevelChooser->hide();
    if(gameController!=NULL)
        gameController->hide();
}

void MainWindow::Test()
{
}

#include "ViewComponent/gamelevelchooser.h"
void MainWindow::ChooseLevelMenu()
{
    gameLevelChooser->show();
    menuInterface->hide();
}

