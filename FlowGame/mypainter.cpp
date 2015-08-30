#include "MyPainter.h"
#include "GameSetting.h"

MyPainter::MyPainter(QPaintDevice *_device):
    QPainter(_device)
{
    this->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
    this->setPen(Qt::NoPen);
    this->setBrush(GameData::BgBrush);
}
