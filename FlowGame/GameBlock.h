#ifndef GAMEBLOCKS
#define GAMEBLOCKS

#include <QtGui>
#include <QColor>
#include <QWidget>

class GamePanel;

class GameBlock: public QWidget
{
    Q_OBJECT

private:

    QPoint coordinate;

    GamePanel* parentPanel;

protected:

    virtual void paintEvent(QPaintEvent*);

public:

    static int LineWidth;

    int Height();
    int Width();

    QColor Color;
    bool Show;

    GameBlock(QPoint _coordinate,GamePanel* _parentPanel=0);

};


#endif // GAMEBLOCKS

