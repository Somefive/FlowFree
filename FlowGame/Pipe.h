#ifndef PIPE
#define PIPE

#include <QColor>
#include <QPoint>
#include <QVector>


class Pipe: public QVector<QPoint>
{

public:

    QColor Color;

    static int MAXX, MAXY;

    Pipe(const QColor& _color);
    Pipe(const QColor& _color, const QPoint& _start);

};

#endif // PIPE

