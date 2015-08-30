#include "MouseState.h"
#include "GamePanel.h"
#include "mypainter.h"

MouseState::MouseState(GamePanel *_panel):
    QWidget(_panel),parentPanel(_panel),Pressed(false),Color(Qt::black),
    Position(QPoint(0,0)),PaintCircleFlag(false),sizeRatio(1.1)
{
}

void MouseState::paintEvent(QPaintEvent *)
{
    if(!PaintCircleFlag)
        return;
    this->setGeometry(0,0,parentPanel->width(),parentPanel->height());
    this->raise();
    int _w = parentPanel->getBlockWidth()*sizeRatio, _h = parentPanel->getBlockHeight()*sizeRatio;

    MyPainter painter(this);
    Color.setAlpha(127);
    painter.setBrush(QBrush(Color));
    painter.drawEllipse(Position.x()-_w/2,Position.y()-_h/2,_w,_h);
}

int MouseState::Width()
{
    return parentPanel->getBlockWidth()*0.9;
}

int MouseState::Height()
{
    return parentPanel->getBlockHeight()*0.9;
}

void MouseState::StartPaintCircle(const QColor& _color,const QPoint& _pos)
{
    PaintCircleFlag = true;
    Color = _color;
    Position = _pos;
}

void MouseState::EndPaintCircle()
{
    PaintCircleFlag = false;
}

void MouseState::wheelEvent(QWheelEvent *event)
{
    double range = event->delta()/120;
    sizeRatio += range/10;
    if(sizeRatio<0.8)
        sizeRatio = 0.8;
    if(sizeRatio>2.4)
        sizeRatio = 2.4;
    update();
}
