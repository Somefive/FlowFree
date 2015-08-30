#include "PipeManager.h"
#include "GameController.h"

PipeManager::PipeManager(GameController *_controller):
    gameController(_controller)
{}

Pipe* PipeManager::getPipe(const QColor& _color)
{
    Pipe* ans = 0;
    for(int i=0;i<size();++i)
        if(this->at(i)!=0 && this->at(i)->Color==_color)
            ans = this->at(i);
    return ans;
}
