#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GamePanel.h"
#include "GameController.h"
#include "GameSetting.h"
#include "ViewComponent/gamemenuinterface.h"
#include "ViewComponent/gamelevelchooser.h"
#include <QQueue>
#include <queue>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    GameMenuInterface* menuInterface;
    GameController* gameController;
    GameSetting* gameSetting;
    GameLevelChooser* gameLevelChooser;
    std::queue<QWidget*> useless;
    std::queue<GameSetting*> uselessSetting;

public slots:
    void NextGame();
    void PreviousGame();
    void RetryGame();
    void StartGame();
    void ChooseLevel(int _level,int _gameNo=1);
    void BackToMenu();
    void Test();
    void ChooseLevelMenu();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
