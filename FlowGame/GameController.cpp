#include "gamecontroller.h"
#include <QtGui>
#include <GamePanel.h>
#include <QWidget>
#include <stack>
#include "PipeManager.h"
#include <QMessageBox>
#include <QSound>
#include <queue>

void GameController::paintEvent(QPaintEvent *)
{

    this->setGeometry(this->parentWidget()->rect());
    this->gamePanel->setFocus();
}


bool GameController::Valid(const QPoint &_coordinate)
{
    if(_coordinate.x()<0 || _coordinate.x()>=gameSetting->level)
        return false;
    if(_coordinate.y()<0 || _coordinate.y()>=gameSetting->level)
        return false;
    return true;
}

GameController::GameController(GameSetting* _setting, QWidget* _parent):
    QWidget(_parent),gameSetting(_setting)
{
    GameSetting::GameCount++;

    gamePanel = new GamePanel(this);
    gameAudioPlayer = new GameAudioPlayer(this);

    //初始化格子背景颜色
    for(int i=0;i<this->getLevel();++i)
        for(int j=0;j<this->getLevel();++j)
        {
            blockcolor[i][j]=GameData::BgColor;
            blockstate[i][j]=EMPTY;
        }
    //初始化源颜色
    for(int i=0;i<this->getColorNumber()*2;++i)
    {
        const QPoint& p = this->getOriginPoint(i);
        blockcolor[p.x()][p.y()] = GameData::ColorSet[i/2];
        blockstate[p.x()][p.y()] = ORIGIN;
    }
    //初始化管道
    pipeManager = new PipeManager(this);
    for(int i=0;i<this->getColorNumber();++i)
    {
        Pipe* pipe = new Pipe(GameData::ColorSet[i]);
        pipeManager->push_back(pipe);
    }

    this->gamePanel->Initialize();

    QObject::connect(gamePanel,SIGNAL(CoordinateSelected(QPoint)),this,SLOT(CoordinateSelected(QPoint)));
    QObject::connect(gamePanel,SIGNAL(CoordinateChanged(QPoint)),this,SLOT(CoordinateChanged(QPoint)));
    QObject::connect(gamePanel,SIGNAL(CoordinateReleased()),this,SLOT(CoordinateReleased()));
    QObject::connect(gamePanel,SIGNAL(AnswerGame()),this,SLOT(AnswerGame()));

    QObject::connect(this,SIGNAL(UpdatePipeDisplay()),gamePanel,SLOT(UpdatePipeDisplay()));
    QObject::connect(this,SIGNAL(UpdateBlockDisplay()),gamePanel,SLOT(UpdateBlockDisplay()));
    QObject::connect(this,SIGNAL(UpdatePipeDisplay()),this,SLOT(GameStateRecalculate()));

}

QColor GameController::getBlockColor(const QPoint& _coordinate) //格子颜色
{return blockcolor[_coordinate.x()][_coordinate.y()];}

int GameController::getBlockWidth() //每个格子的宽度
{return gamePanel->width()/getLevel(); }
int GameController::getBlockHeight() //每个格子的高度
{return gamePanel->height()/getLevel();}

int GameController::getLevel() //游戏级别
{return gameSetting->level;}
int GameController::getColorNumber() //颜色数目
{return gameSetting->colorNumber;}
QPoint GameController::getOriginPoint(int _No)  //获得初始点
{return gameSetting->Points[_No];}
PipeManager* GameController::getPipeManager()
{return pipeManager;}

QPoint GameController::Coordinate(const QPoint& _pos)//屏幕坐标到游戏坐标
{return QPoint(_pos.x()/this->getBlockWidth(),_pos.y()/this->getBlockHeight());}
QPoint GameController::Center(const QPoint& _coordinate)//游戏坐标到屏幕格子中心坐标
{return QPoint((int)((_coordinate.x()+0.5)*getBlockWidth()),(int)((_coordinate.y()+0.5)*getBlockHeight()));}

void GameController::CoordinateReleased()
{
    for(int i=0;i<getLevel();++i)
        for(int j=0;j<getLevel();++j)
            setBlockColor(QPoint(i,j),GameData::BgColor);
    for(int i=0;i<getColorNumber()*2;++i)
        setBlockColor(gameSetting->Points[i],GameData::ColorSet[i/2]);
    for(int i=0;i<pipeManager->size();++i)
    {
        Pipe* pipe = pipeManager->at(i);
        if(pipeManager->currentPipe!=pipe)
        {
            while(!pipe->empty())
            {
                QPoint _coordinate(pipe->back());
                STATE _state = getBlockState(_coordinate);
                if((_state&WAY)==0||(_state&BREAK)!=0||(_state&CURRENT)!=0)
                    pipe->pop_back();
                else
                    break;
            }
        }
        for(int j=0;j<pipe->size();++j)
            setBlockColor(pipe->at(j),pipe->Color);
    }
    for(int i=0;i<this->getLevel();++i)
        for(int j=0;j<this->getLevel();++j)
            setBlockState(QPoint(i,j),~(CURRENT|BREAK));
    ++gameSetting->moves;
    emit UpdatePipeDisplay();
    emit UpdateBlockDisplay();
    if(CheckWin())
        emit CompleteGame();
}

void GameController::AutoSearchPath(const QPoint &_coordinate)
{
    QPoint start(pipeManager->currentPipe->back());
    static int dct[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    static QPoint dad[20][20];
    static int step[20][20];
    std::queue<QPoint> qpt;

    int dirno[2] = {-1,-1};
    if(_coordinate.x()>start.x())
        dirno[0] = 2;
    else if(_coordinate.x()<start.x())
        dirno[0] = 3;
    if(_coordinate.y()>start.y())
        dirno[1] = 0;
    else if(_coordinate.y()<start.y())
        dirno[1] = 1;

    for(int i=0;i<getLevel();++i)
        for(int j=0;j<getLevel();++j)
        {
            dad[i][j] = QPoint(-1,-1);
            step[i][j]=-1;
        }
    qpt.push(start);
    dad[start.x()][start.y()] = start;
    step[start.x()][start.y()]=0;
    bool success=false;
    while(!qpt.empty())
    {
        int ox = qpt.front().x(), oy = qpt.front().y();
        if(step[ox][oy]>5)
            return;
        for(int k=0;k<2;++k)
        {
            if(dirno[k]==-1)
                continue;
            QPoint tp(ox+dct[dirno[k]][0],oy+dct[dirno[k]][1]);
            if(Valid(tp)&&(getBlockState(tp)&ORIGIN)==0&&step[tp.x()][tp.y()]==-1)
            {
                qpt.push(tp);
                dad[tp.x()][tp.y()]=qpt.front();
                step[tp.x()][tp.y()]=step[ox][oy]+1;
                if(tp==_coordinate)
                    success=true;
                if(success)
                    break;
            }
        }
        if(success)
            break;
        qpt.pop();
    }
    if(!success)
        return;
    QPoint cur = _coordinate;
    std::stack<QPoint> route;
    while(dad[cur.x()][cur.y()]!=cur)
    {
        route.push(cur);
        cur = dad[cur.x()][cur.y()];
    }
    while(!route.empty())
    {
        CoordinateChanged(route.top());
        route.pop();
    }
}

void GameController::CoordinateChanged(const QPoint &_coordinate)
{

    if(this->pipeManager->currentPipe==0)
        return;
    QPoint lastcoordinate = this->pipeManager->currentPipe->back();
    QColor _coordinateColor = getBlockColor(_coordinate);
    STATE _coordinateState = getBlockState(_coordinate);
    int distance = Distance(lastcoordinate,_coordinate);
    if((_coordinateState&CURRENT)==0&&(getBlockState(lastcoordinate)&ORIGIN)!=0&&getBlockColor(lastcoordinate)==this->pipeManager->currentPipe->Color&&this->pipeManager->currentPipe->size()>1)
        return;
    if(distance!=1)
    {
        if(distance<=5&&(_coordinateState&ORIGIN)==0)
            AutoSearchPath(_coordinate);
        return;
    }
    if((_coordinateState&WAY)==0)
    {
        if((_coordinateState&ORIGIN)==0)
        {
            setBlockState(_coordinate,WAY|CURRENT);
            pipeManager->currentPipe->push_back(_coordinate);
            emit ForwardPipe();
            emit UpdatePipeDisplay();
        }
        else
        {
            if(_coordinateColor==pipeManager->currentPipe->Color)
            {
                setBlockState(_coordinate,WAY|CURRENT);
                pipeManager->currentPipe->push_back(_coordinate);
                emit CompletePipe(pipeManager->currentPipe);
                emit UpdatePipeDisplay();
            }
        }
    }
    else
    {
        if((_coordinateState&CURRENT)!=0)
        {
            while(pipeManager->currentPipe->back()!=_coordinate)
            {
                QPoint backpoint = pipeManager->currentPipe->back();
                QColor backpointColor = getBlockColor(backpoint);
                setBlockState(backpoint,~CURRENT);
                if(backpointColor==GameData::BgColor || backpointColor==pipeManager->currentPipe->Color)
                    setBlockState(backpoint,~WAY);
                else
                {
                    setBlockState(backpoint,~BREAK);
                    Pipe* pipe = pipeManager->getPipe(backpointColor);
                    bool unable = false;
                    for(int i=0;i<pipe->size();++i)
                    {
                        STATE _state = getBlockState(pipe->at(i));
                        if((_state&BREAK)!=0)
                            unable = true;
                        if(unable && (_state&BREAK)==0)
                            setBlockState(pipe->at(i),~WAY);
                        else
                            setBlockState(pipe->at(i),WAY);
                    }
                }
                pipeManager->currentPipe->pop_back();
            }
            emit BackwardPipe();
            emit UpdatePipeDisplay();
        }
        else
        {
            if((_coordinateState&ORIGIN)!=0)
                return;
            Pipe* pipe = pipeManager->getPipe(_coordinateColor);
            setBlockState(_coordinate,WAY|CURRENT|BREAK);
            pipeManager->currentPipe->push_back(_coordinate);
            bool unable = false;
            for(int i=0;i<pipe->size();++i)
            {
                STATE _state = getBlockState(pipe->at(i));
                if((_state&BREAK)!=0)
                    unable = true;
                if(unable && (_state&BREAK)==0)
                    setBlockState(pipe->at(i),~WAY);
                else
                    setBlockState(pipe->at(i),WAY);
            }
            emit BreakPipe(pipe);
            emit UpdatePipeDisplay();
        }
    }
}

void GameController::CoordinateSelected(const QPoint &_coordinate)
{
    this->pipeManager->currentPipe = this->pipeManager->getPipe(this->getBlockColor(_coordinate));
    Pipe* pipe = pipeManager->currentPipe;
    while(!pipe->empty() && (pipe->back()!=_coordinate||(getBlockState(_coordinate)&ORIGIN)!=0))
    {
        setBlockState(pipe->back(),~(WAY|CURRENT));
        pipe->pop_back();
    }
    if(pipe->empty())
    {
        setBlockState(_coordinate,WAY|CURRENT);
        pipe->push_back(_coordinate);
    }
    for(int i=0;i<pipe->size();++i)
        setBlockState(pipe->at(i),CURRENT);
    emit UpdatePipeDisplay();
}

bool GameController::Adjacent(const QPoint &p1, const QPoint &p2)
{
    if(abs(p1.x()-p2.x())+abs(p1.y()-p2.y())==1)
        return true;
    return false;
}

GameController::STATE GameController::getBlockState(const QPoint &_coordinate)
{
    return blockstate[_coordinate.x()][_coordinate.y()];
}

void GameController::setBlockColor(const QPoint &_coordinate, const QColor &_color)
{
    blockcolor[_coordinate.x()][_coordinate.y()] = _color;
}

void GameController::setBlockState(const QPoint &_coordinate, GameController::STATE _state)
{
    if(_state>0)
        blockstate[_coordinate.x()][_coordinate.y()] |= _state;
    else
        blockstate[_coordinate.x()][_coordinate.y()] &= _state;
}

bool GameController::CheckWin()
{
    for(int i=0;i<pipeManager->size();++i)
    {
        Pipe* pipe = pipeManager->at(i);
        if(pipe->size()<2)
            return false;
        if((getBlockState(pipe->back())&ORIGIN)==0)
            return false;
    }
    for(int i=0;i<getLevel();++i)
        for(int j=0;j<getLevel();++j)
            if((getBlockState(QPoint(i,j))&WAY)==0)
                return false;
    if(gameSetting->best<=0 || gameSetting->moves<gameSetting->best)
        gameSetting->setBest(gameSetting->moves);
    return true;
}

void GameController::GameStateRecalculate()
{
    int pipeCompleteCount = 0;
    for(int i=0;i<getLevel();++i)
        for(int j=0;j<getLevel();++j)
            if((blockstate[i][j]&WAY)!=0)
                ++pipeCompleteCount;
    gameSetting->pipeFilled = floor(pipeCompleteCount*100/getLevel()/getLevel());

    int pipeLinkCount = 0;
    for(int i=0;i<pipeManager->size();++i)
    {
        Pipe* pipe = pipeManager->at(i);
        if(pipe->size()<2)
            continue;
        if((getBlockState(pipe->back())&ORIGIN)==0)
            continue;
        ++pipeLinkCount;
    }
    gameSetting->currentflows = pipeLinkCount;
}

#include "gamesolver.h"
void GameController::AnswerGame()
{
    if(gameSetting->level>=8)
        return;
    GameSolver solver(this);
    solver.Calculate();
}

int GameController::Distance(const QPoint &p1, const QPoint &p2)
{
    return (abs(p1.x()-p2.x())+abs(p1.y()-p2.y()));
}
