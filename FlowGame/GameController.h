#ifndef GAMECONTROLLER
#define GAMECONTROLLER

#include "GameLogicModel.h"
#include "GamePanel.h"
#include "GameAudioPlayer.h"
#include "ViewComponent/gameinfoviewer.h"

class GameController: public QWidget
{
    Q_OBJECT

    friend class GamePanel;
    friend class GameSolver;

public:

    typedef int STATE;
    enum{EMPTY=0x0,
        ORIGIN=0x1,
        WAY=0x2,
        CURRENT=0x4,
        BREAK=0x8};

signals:

    void CompletePipe(Pipe*);
    void BreakPipe(Pipe*);
    void ForwardPipe();
    void BackwardPipe();
    void UpdatePipeDisplay();
    void UpdateBlockDisplay();
    void CompleteGame();

public slots:

    void CoordinateSelected(const QPoint&);
    void CoordinateChanged(const QPoint&);
    void CoordinateReleased();
    void GameStateRecalculate();
    void AnswerGame();

private:

    GameSetting* gameSetting;
    QColor blockcolor[15][15];
    STATE blockstate[15][15];

    PipeManager *pipeManager;
    GameAudioPlayer* gameAudioPlayer;

    void AutoSearchPath(const QPoint& _coordinate);

protected:
    virtual void paintEvent(QPaintEvent*);

public:

    GamePanel* gamePanel;

    GameController(GameSetting* _setting,QWidget* _parent);

    QColor getBlockColor(const QPoint& _coordinate); //格子颜色
    void setBlockColor(const QPoint& _coordinate, const QColor& _color); //设置格子颜色
    STATE getBlockState(const QPoint& _coordinate); //格子状态
    void setBlockState(const QPoint& _coordinate, STATE _state); //设置格子状态
    QPoint getOriginPoint(int _No);  //获得初始点
    int getBlockWidth(); //每个格子的宽度
    int getBlockHeight(); //每个格子的高度
    int getLevel(); //游戏级别
    int getColorNumber(); //颜色数目
    PipeManager* getPipeManager();

    QPoint Coordinate(const QPoint& _pos);//屏幕坐标到游戏坐标
    QPoint Center(const QPoint& _coordinate);//游戏坐标到屏幕格子中心坐标

    bool Valid(const QPoint& _coordinate);
    bool Adjacent(const QPoint& p1, const QPoint& p2);
    int Distance(const QPoint& p1, const QPoint& p2);
    bool CheckWin();

};

#endif // GAMECONTROLLER

