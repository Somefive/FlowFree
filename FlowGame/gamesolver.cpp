#include "gamesolver.h"
#include "GameController.h"

GameSolver::GameSolver(GameController* _controller):
    gameController(_controller),solvable(false)
{
    Initialize();
}

GameSolver::~GameSolver()
{
}

void GameSolver::Initialize()
{
    gameSetting = gameController->gameSetting;
    size = gameSetting->level;
    colorNumber = gameSetting->colorNumber;
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
        {
            dad[i][j] = QPoint(i,j);
            color[i][j] = -1;
        }
    for(int i=0;i<colorNumber;++i)
    {
        startPoints[i] = gameSetting->Points[i*2];
        endPoints[i] = gameSetting->Points[i*2+1];
        color[startPoints[i].x()][startPoints[i].y()]=i;
        color[endPoints[i].x()][endPoints[i].y()]=i;
    }
}

void GameSolver::Calculate()
{
    Search(startPoints[0],0);
    if(solvable)
        Analog();
}

void GameSolver::Search(const QPoint& ori, int oriColor)
{
    if(solvable)
        return;
    if(ori==endPoints[oriColor])
    {
        int newColor = oriColor+1;
        if(newColor==colorNumber)
        {
            if(CheckWin())
            {
                solvable = true;
                return;
            }
        }
        else
        {
            Search(startPoints[newColor],newColor);
            if(solvable)
                return;
        }
    }
    else
    {
        for(int k=0;k<4;++k)
        {
            int newx = ori.x()+dct[k][0], newy = ori.y()+dct[k][1];
            QPoint newPoint(newx,newy);
            if(!Valid(newx,newy))
                continue;
            if(color[newx][newy]!=-1&&newPoint!=endPoints[oriColor])
                continue;
            color[newx][newy]=oriColor;
            dad[newx][newy]=ori;
            Search(newPoint,oriColor);
            if(solvable)
                return;
            dad[newx][newy]=newPoint;
            if(newPoint!=endPoints[oriColor])
                color[newx][newy]=-1;
        }
    }
}

bool GameSolver::CheckWin()
{
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            if(color[i][j]==-1)
                return false;
    return true;
}

bool GameSolver::Valid(int _x, int _y)
{
    if(_x<0||_x>=size)
        return false;
    if(_y<0||_y>=size)
        return false;
    return true;
}

void GameSolver::Analog()
{
    for(int i=0;i<colorNumber;++i)
    {
        QPoint currentCoordinate = endPoints[i];
        gameController->CoordinateSelected(currentCoordinate);
        while(dad[currentCoordinate.x()][currentCoordinate.y()]!=currentCoordinate)
        {
            currentCoordinate = dad[currentCoordinate.x()][currentCoordinate.y()];
            gameController->CoordinateChanged(currentCoordinate);
        }
        gameController->CoordinateReleased();
    }
}
