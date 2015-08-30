#ifndef PIPEPAINTER
#define PIPEPAINTER

#include "PipeManager.h"
#include <QWidget>

class GamePanel;

class PipePainter: public QWidget
{
    Q_OBJECT

private:

    GamePanel* parentPanel;
    PipeManager* pipeManager;

protected:

    virtual void paintEvent(QPaintEvent*);

public:

    PipePainter(GamePanel*,PipeManager*);

};

#endif // PIPEPAINTER

