#ifndef MOUSESTATE
#define MOUSESTATE

#include <QtGui>
#include <QColor>
#include <QWidget>

#include "pipe.h"

class GamePanel;

class MouseState: public QWidget
{

    Q_OBJECT

private:

    GamePanel* parentPanel;

protected:

    virtual void paintEvent(QPaintEvent *);
    virtual void wheelEvent(QWheelEvent *);
    double sizeRatio;

public:

    bool Pressed;
    bool PaintCircleFlag;
    QColor Color;
    QPoint Position;
    QPoint Coordinate;

    MouseState(GamePanel*);

    int Width();
    int Height();

    void StartPaintCircle(const QColor& _color,const QPoint& _pos);
    void EndPaintCircle();

};

#endif // MOUSESTATE

