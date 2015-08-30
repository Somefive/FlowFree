#ifndef PIPEMANAGER
#define PIPEMANAGER

#include "MouseState.h"
#include "pipe.h"

#include <vector>
#include <QtGui>
#include <QVector>


class GameController;
typedef int STATE;

class PipeManager: public QVector<Pipe*>
{

private:

    GameController* gameController;

    friend class PipePainter;

public:

    Pipe* currentPipe;

    PipeManager(GameController*);

    Pipe* getPipe(const QColor& _color);

};

#endif // PIPEMANAGER

