#include "PipePainter.h"
#include <QtGui>
#include "GamePanel.h"
#include "PipeManager.h"
#include "GameController.h"
#include "mypainter.h"

PipePainter::PipePainter(GamePanel* _panel, PipeManager *_pipeManager):
    QWidget(_panel),parentPanel(_panel),pipeManager(_pipeManager)
{}

void PipePainter::paintEvent(QPaintEvent *)
{
    this->setGeometry(0,0,parentPanel->width(),parentPanel->height());
    MyPainter painter(this);
    int _penWidth = (parentPanel->getBlockHeight()+parentPanel->getBlockWidth())/5;
    for(int i=0;i<pipeManager->size();++i)
    {
        Pipe* pipe = pipeManager->at(i);
        if(pipe->size()<2)
            continue;
        QColor _color = pipe->Color;
        painter.setPen(QPen(QBrush(_color),_penWidth,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
        for(int j=0;j<pipe->size()-1;++j)
        {
            QPoint raw1 = pipe->at(j);
            QPoint raw2 = pipe->at(j+1);
            if(pipe!=pipeManager->currentPipe)
            {
                if((pipeManager->gameController->getBlockState(raw1)&GameController::BREAK)!=0)
                    break;
                if((pipeManager->gameController->getBlockState(raw2)&GameController::BREAK)!=0)
                    break;
            }
            QPoint p1 = parentPanel->Center(raw1);
            QPoint p2 = parentPanel->Center(raw2);
            painter.drawLine(p1,p2);
        }
    }
}

