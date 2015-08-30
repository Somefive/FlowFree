#include "GameAudioPlayer.h"
#include "GameController.h"

#include <QSound>

GameAudioPlayer::GameAudioPlayer(GameController *_controller):
    QWidget(_controller),gameController(_controller),flowCount(0)
{
    QObject::connect(gameController,SIGNAL(CompleteGame()),this,SLOT(CompleteGame()));
    QObject::connect(gameController,SIGNAL(BreakPipe(Pipe*)),this,SLOT(BreakPipe(Pipe*)));
    QObject::connect(gameController,SIGNAL(CompletePipe(Pipe*)),this,SLOT(CompletePipe(Pipe*)));
    QObject::connect(gameController,SIGNAL(BackwardPipe()),this,SLOT(BackwardPipe()));
    QObject::connect(gameController,SIGNAL(ForwardPipe()),this,SLOT(ForwardPipe()));

    rootPath = QCoreApplication::applicationDirPath()+"\\Resources\\Audio\\";
}

void GameAudioPlayer::CompleteGame()
{
    QSound::play(rootPath+"Completed.wav");
}

void GameAudioPlayer::CompletePipe(Pipe *)
{
    QSound::play(rootPath+"flow.wav");
}

void GameAudioPlayer::BreakPipe(Pipe *)
{
    QSound::play(rootPath+"leak.wav");
}

void GameAudioPlayer::ForwardPipe()
{
    ++flowCount;
    if(flowCount%3==0)
        QSound::play(rootPath+"forward.wav");
}

void GameAudioPlayer::BackwardPipe()
{
    ++flowCount;
    if(flowCount%2==0)
        QSound::play(rootPath+"back.wav");
}
