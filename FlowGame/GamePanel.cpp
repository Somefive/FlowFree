#include "GamePanel.h"
#include "gamecontroller.h"
#include "GameBlock.h"
#include "mypainter.h"
#include "ViewComponent/gamemessagebox.h"

#include <QtGui>
//#include <QTest>

void GamePanel::paintEvent(QPaintEvent *)
{
    this->setFixedSize(this->parentWidget()->width(),this->parentWidget()->height());

    MyPainter painter(this);
    painter.setBrush(QBrush(GameData::BgColor));
    painter.drawRect(this->rect());

}

void GamePanel::Initialize()
{
    this->setGeometry(gameController->rect());
    mouseState = new MouseState(this);
    gameInfoViewer = new GameInfoViewer(this,gameController->gameSetting);
    pipePainter = new PipePainter(this,gameController->getPipeManager());

    this->setFixedSize(this->parentWidget()->width(),this->parentWidget()->height());

    gameInfoViewer->hide();
    this->setFocusPolicy(Qt::StrongFocus);

    //加载背景方块
    for(int i=0;i<gameController->getLevel();++i)
        for(int j=0;j<gameController->getLevel();++j)
        {
            blocks[i][j] = new GameBlock(QPoint(i,j),this);
            blocks[i][j]->show();
        }
    //加载源头
    for(int i=0;i<gameController->getColorNumber();++i)
    {
        flows[2*i] = new FlowSource(gameController->getOriginPoint(2*i),GameData::ColorSet[i],this);
        flows[2*i+1] = new FlowSource(gameController->getOriginPoint(2*i+1),GameData::ColorSet[i],this);
        flows[2*i]->show();
        flows[2*i+1]->show();
    }
    pipePainter->raise();
    mouseState->raise();
    pipePainter->show();

    connect(gameInfoViewer,SIGNAL(Retry()),this,SLOT(RetryActivated()));
    connect(gameInfoViewer,SIGNAL(BackToMenu()),this,SLOT(MenuActivated()));
    connect(gameInfoViewer,SIGNAL(AnswerGame()),this,SLOT(AnswerGameActivated()));
    connect(gameInfoViewer,SIGNAL(NextGame()),this,SLOT(NextGameActivated()));
    connect(gameInfoViewer,SIGNAL(PreviousGame()),this,SLOT(PreviousGameActivated()));

    connect(gameController,SIGNAL(CompleteGame()),this,SLOT(CompleteGame()));

    this->setFocus();
}

void GamePanel::mousePressEvent(QMouseEvent *event)
{
    QPoint coordinate = gameController->Coordinate(event->pos());
    if(!gameController->Valid(coordinate))
        return;
    QColor touchColor = gameController->getBlockColor(coordinate);
    if(touchColor==GameData::BgColor)
        return;
    mouseState->Pressed = true;
    mouseState->StartPaintCircle(touchColor,event->pos());
    mouseState->Coordinate = gameController->Coordinate(event->pos());
    mouseState->update();
    emit CoordinateSelected(coordinate);
}

void GamePanel::mouseReleaseEvent(QMouseEvent *)
{
    mouseState->Pressed = false;
    mouseState->EndPaintCircle();
    mouseState->update();
    emit CoordinateReleased();
}

void GamePanel::mouseMoveEvent(QMouseEvent *event)
{
    if(!mouseState->Pressed)
        return;
    /*
    QPoint cursorPos = event->pos();
    if(cursorPos.x()<0)
        cursorPos.setX(3);
    else if(cursorPos.x()>this->width())
        cursorPos.setX(width()-3);
    if(cursorPos.y()<0)
        cursorPos.setY(3);
    else if(cursorPos.y()>this->height())
        cursorPos.setY(height()-3);
    QTest::mouseMove(this,cursorPos);*/
    QPoint newCoordinate = gameController->Coordinate(event->pos());
    if(!gameController->Valid(newCoordinate))
    {
        mouseReleaseEvent(event);
        return;
    }
    mouseState->Position = event->pos();
    mouseState->update();
    if(mouseState->Coordinate==newCoordinate)
        return;
    mouseState->Coordinate = newCoordinate;
    emit CoordinateChanged(newCoordinate);
}

GamePanel::GamePanel(GameController* parent):
    QWidget(parent),gameController(parent)
{}

int GamePanel::getBlockHeight()
{
    return gameController->getBlockHeight();
}
int GamePanel::getBlockWidth()
{
    return gameController->getBlockWidth();
}

QPoint GamePanel::Center(const QPoint& coordinate)
{
    return this->gameController->Center(coordinate);
}
QPoint GamePanel::Coordinate(const QPoint &pos)
{
    return this->gameController->Coordinate(pos);
}

void GamePanel::UpdatePipeDisplay()
{
    pipePainter->update();
}

void GamePanel::UpdateBlockDisplay()
{
    for(int i=0;i<gameController->getLevel();++i)
    {
        for(int j=0;j<gameController->getLevel();++j)
        {
            GameController::STATE _state = gameController->getBlockState(QPoint(i,j));
            if((_state&GameController::CURRENT)==0&&(_state&GameController::WAY)!=0)
            {
                blocks[i][j]->Show=true;
                blocks[i][j]->Color = gameController->getBlockColor(QPoint(i,j));
            }
            else
                blocks[i][j]->Show=false;
            blocks[i][j]->update();
        }
    }
}

void GamePanel::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Control)
    {
        gameInfoViewer->show();
        gameInfoViewer->raise();
    }
}

void GamePanel::keyReleaseEvent(QKeyEvent *)
{
    gameInfoViewer->hide();
}

void GamePanel::RetryActivated()
{
    emit Retry();
}

void GamePanel::MenuActivated()
{
    emit BackToMenu();
}

void GamePanel::NextGameActivated()
{
    emit NextGame();
}

void GamePanel::PreviousGameActivated()
{
    emit PreviousGame();
}

void GamePanel::AnswerGameActivated()
{
    emit AnswerGame();
}

void GamePanel::CompleteGame()
{
    GameMessageBox* myMsgBox = new GameMessageBox(this,"Congratulations!","You win the game~","Retry","Next");
    connect(myMsgBox,SIGNAL(LeftButtonClicked()),this,SLOT(RetryActivated()));
    connect(myMsgBox,SIGNAL(RightButtonClicked()),this,SLOT(NextGameActivated()));
    myMsgBox->show();
}
