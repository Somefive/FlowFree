#include "GameLogicModel.h"
#include "GameSetting.h"

bool GameLogicModel::Valid(const QPoint& _coordinate)
{
    if(_coordinate.x()<0 || _coordinate.x()>=gameSetting->level)
        return false;
    if(_coordinate.y()<0 || _coordinate.y()>=gameSetting->level)
        return false;
    return true;
}

GameLogicModel::GameLogicModel(int _No):QObject()
{
    this->gameSetting = &GameData::GameSettings[_No];


}
