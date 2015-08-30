#ifndef GAMELOGICMODEL
#define GAMELOGICMODEL

#include <QColor>
#include <QPoint>
#include "gamesetting.h"
#include <QObject>
/*
class GameLogicModel: QObject
{
    Q_OBJECT
private:

    //const GameSetting* gameSetting;

public:

    //QColor blockcolor[10][10];

    GameLogicModel(int _No=0);

    int getLevel() //游戏级别
    {return gameSetting->level;}
    int getColorNumber() //颜色数目
    {return gameSetting->colorNumber;}
    QPoint getOriginPoint(int _No)  //获得初始点
    {
        if(_No>=0 && _No<gameSetting->colorNumber*2)
            return gameSetting->Points[_No];
        return QPoint(-1,-1);
    }

    bool Valid(const QPoint&); //判断坐标是否合法

};*/

#endif // GAMELOGICMODEL

