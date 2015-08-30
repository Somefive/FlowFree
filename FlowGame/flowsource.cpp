#include "FlowSource.h"
#include "GamePanel.h"
#include "mypainter.h"

FlowSource::FlowSource(const QPoint &_coordinate, const QColor &_color, GamePanel* _panel):
    coordinate(_coordinate),Color(_color),QWidget(_panel),parentPanel(_panel)
{
}

int FlowSource::Height()
{
    return parentPanel->getBlockHeight()*0.75;
}

int FlowSource::Width()
{
    return parentPanel->getBlockWidth()*0.75;
}

void FlowSource::paintEvent(QPaintEvent *)
{
    QPoint blockpos = parentPanel->Center(this->coordinate);
    int _w = this->Width(), _h = this->Height();
    this->setGeometry(blockpos.x()-_w/2,blockpos.y()-_h/2,_w,_h);
    MyPainter painter(this);
    painter.setBrush(QBrush(Color));
    painter.drawEllipse(0,0,_w,_h);
}
