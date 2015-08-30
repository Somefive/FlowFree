#include "GameSetting.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QStringList>
#include <QCoreApplication>

GameSetting::GameSetting(int _level, int _gameNo):
    level(_level),gameNo(_gameNo),moves(0),pipeFilled(0),currentflows(0)
{
    gameDataPath = QCoreApplication::applicationDirPath() + "/GameData/Level" + QString::number(_level) + "/" + QString::number(_gameNo) + ".ffdat";
    userDataPath = QCoreApplication::applicationDirPath() + "/GameData/User.ffdat";
    LoadFile();
}

void GameSetting::LoadFile()
{
    QFile file(gameDataPath);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream stream(&file);
    colorNumber = stream.readLine().toInt();
    for(int i=0;i<colorNumber*2;++i)
    {
        QStringList strlist = stream.readLine().split(" ");
        int x = strlist.at(0).toInt(), y = strlist.at(1).toInt();
        Points[i].setX(x);
        Points[i].setY(y);
    }
    file.close();
    QFile ufile(userDataPath);
    best = -1;
    if(ufile.exists()==true)
    {
        ufile.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream uStream(&ufile);
        while(!uStream.atEnd())
        {
            QStringList strlist = uStream.readLine().split(" ");
            if(strlist.size()<2)
                continue;
            if(strlist.at(0)!=gameDataPath)
                continue;
            best = strlist.at(1).toInt();
            break;
        }
    }
    ufile.close();
}

void GameSetting::SaveFile()
{
    QFile ufile(userDataPath);
    ufile.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream uStream(&ufile);
    QStringList strlist;
    while(!ufile.atEnd())
        strlist.append(ufile.readLine());
    ufile.close();
    QFile file(userDataPath);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream stream(&file);
    bool needtoappend = true;
    for(int i=0;i<strlist.size();++i)
    {
        QString str = strlist.at(i);
        QStringList tmpList = str.split(" ");
        if(tmpList.size()<2)
            continue;
        stream<<tmpList.at(0)<<" ";
        if(tmpList.at(0)!=gameDataPath)
            stream<<tmpList.at(1)<<"\r\n";
        else
        {
            stream<<QString::number(best)<<"\r\n";
            needtoappend = false;
        }
    }
    if(needtoappend)
        stream<<gameDataPath<<" "<<QString::number(best)<<"\r\n";
    file.close();
}

void GameSetting::setBest(int _best)
{
    best = _best;
    SaveFile();
}

GameSetting GameSetting::getNextGame(const GameSetting &currentSetting)
{
    int currentLevel = currentSetting.level;
    int currentGameNo = currentSetting.gameNo;
    int ansLevel = currentLevel, ansGameNo = currentGameNo + 1;
    if(GameData::GameMaxNo[ansLevel-GameData::GameMinLevel]<ansGameNo)
    {
        if(ansLevel>7 && ansLevel<GameData::GameMaxLevel)
            ++ansLevel;
        ansGameNo = 1;
        if(ansLevel==GameData::GameMaxLevel || ansLevel<=7)
            ansGameNo = GameData::GameMaxNo[ansLevel-GameData::GameMinLevel];
    }
    return GameSetting(ansLevel,ansGameNo);
}

GameSetting GameSetting::getPreviousGame(const GameSetting &currentSetting)
{
    int currentLevel = currentSetting.level;
    int currentGameNo = currentSetting.gameNo;
    int ansLevel = currentLevel, ansGameNo = currentGameNo - 1;
    if(ansGameNo<1)
    {
        if(ansLevel>8)
        {
            --ansLevel;
            ansGameNo = GameData::GameMaxNo[ansLevel-GameData::GameMinLevel];
        }
        else
            ansGameNo = 1;
    }
    return GameSetting(ansLevel,ansGameNo);
}

GameSetting::~GameSetting()
{
}

int GameSetting::GameCount = 0;
