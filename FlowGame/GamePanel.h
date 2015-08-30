#ifndef GAMEPANEL
#define GAMEPANEL

#include "GameSetting.h"
#include "MouseState.h"
#include "PipeManager.h"
#include "GameBlock.h"
#include "FlowSource.h"
#include "PipePainter.h"
#include "ViewComponent/gameinfoviewer.h"

#include <QWidget>
#include <QtGui>
#include <QSizePolicy>
#include <Qsize>
#include <vector>

class GameController;

class GamePanel: public QWidget
{
    Q_OBJECT

signals:

    void CoordinateSelected(const QPoint& _coordinate);
    void CoordinateChanged(const QPoint& _coordinate);
    void CoordinateReleased();
    void Retry();
    void BackToMenu();
    void NextGame();
    void PreviousGame();
    void AnswerGame();

public slots:

    void UpdatePipeDisplay();
    void UpdateBlockDisplay();
    void RetryActivated();
    void MenuActivated();
    void NextGameActivated();
    void PreviousGameActivated();
    void AnswerGameActivated();
    void CompleteGame();

private:

    const static int WhiteLineWidth = 4;

    GameController* gameController;
    PipePainter* pipePainter;

    GameBlock* blocks[20][20];
    FlowSource* flows[50];

    MouseState *mouseState;

    GameInfoViewer *gameInfoViewer;


protected:

    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);

public:

    void Initialize();

    int getBlockHeight();
    int getBlockWidth();

    QPoint Center(const QPoint& coordinate);
    QPoint Coordinate(const QPoint& pos);

    GamePanel(GameController* parent);
};

#endif // GAMEPANEL

