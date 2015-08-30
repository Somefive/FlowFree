#include "Pipe.h"

Pipe::Pipe(const QColor& _color):Color(_color){}
Pipe::Pipe(const QColor& _color, const QPoint& _start):Color(_color)
{
    this->push_back(_start);
}

