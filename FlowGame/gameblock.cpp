#include "GameBlock.h"
#include "GamePanel.h"
#include "mypainter.h"

int GameBlock::LineWidth = 2;

int GameBlock::Height()
{
    return parentPanel->getBlockHeight();
}

int GameBlock::Width()
{
    return parentPanel->getBlockWidth();
}

GameBlock::GameBlock(QPoint _coordinate, GamePanel* _parentPanel)
    :QWidget(_parentPanel),coordinate(_coordinate),parentPanel(_parentPanel),Show(false)
{
}

void GameBlock::paintEvent(QPaintEvent *)
{
    Color.setAlpha(75);
    QPoint blockpos = parentPanel->Center(this->coordinate);
    int _w = this->Width(), _h = this->Height();
    this->setGeometry(blockpos.x()-_w/2,blockpos.y()-_h/2,_w,_h);

    MyPainter painter(this);
    painter.setPen(QPen(QBrush(Qt::white),LineWidth));
    if(Show)
        painter.setBrush(QBrush(Color));
    else
        painter.setBrush(QBrush(GameData::BgColor));
    painter.drawRect(this->rect());
}
