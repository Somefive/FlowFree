#ifndef GAMESOLVER
#define GAMESOLVER

#include "GameSetting.h"
#include <QPoint>

class GameController;

class GameSolver
{
private:
    const int dct[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    QPoint startPoints[20];
    QPoint endPoints[20];
    int size;
    int colorNumber;
    QPoint dad[20][20];
    int color[20][20];

    bool solvable;
    GameSetting* gameSetting;
    GameController* gameController;

    void Search(const QPoint& ori,int oriColor);
    void Initialize();
    bool Valid(int _x,int _y);
    bool CheckWin();
    void Analog();
public:
    GameSolver(GameController* _controller);
    void Calculate();
    ~GameSolver();
};

#endif // GAMESOLVER

