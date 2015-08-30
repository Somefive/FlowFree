#ifndef FLOWSOURCE
#define FLOWSOURCE

#include <QtGui>
#include <QWidget>

class GamePanel;

class FlowSource: public QWidget
{
    Q_OBJECT

private:

    QPoint coordinate;

    GamePanel* parentPanel;

protected:

    virtual void paintEvent(QPaintEvent*);

public:

    QColor Color;

    int Height();
    int Width();

    FlowSource(const QPoint&,const QColor&,GamePanel*);

};

#endif // FLOWSOURCE

