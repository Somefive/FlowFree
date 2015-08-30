
#include "GameMessageBox.h"
#include "mypainter.h"
#include "GameSetting.h"
#include "gameviewpanel.h"

#include <QDebug>

GameMessageBox::GameMessageBox(QWidget *_widget,const QString& _title,const QString& _content,const QString& _leftText,const QString& _rightText):
    GameViewPanel(_widget),Title(_title),Content(_content)
{
    QRect rect  = _widget->rect();
    this->setGeometry(rect.width()/4,rect.height()/4,rect.width()/2,rect.height()/3);

    titleLabel = new QLabel(Title,this);
    contentLabel = new QLabel(Content,this);

    leftButton = new GameButton(_leftText,this);
    rightButton = new GameButton(_rightText,this);

    Initialize();

    connect(leftButton,SIGNAL(Clicked()),this,SLOT(leftButtonClicked()));
    connect(rightButton,SIGNAL(Clicked()),this,SLOT(rightButtonClicked()));
}

void GameMessageBox::Initialize()
{
    titleLabel->setFont(QFont("Lucida Bright",20));
    contentLabel->setFont(QFont("Lucida Bright",16));
    titleLabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    contentLabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::white);
    contentLabel->setPalette(palette);
    palette.setColor(QPalette::WindowText,Qt::yellow);
    titleLabel->setPalette(palette);
}

void GameMessageBox::paintEvent(QPaintEvent *event)
{
    GameViewPanel::paintEvent(event);

    int _w = this->width(), _h=this->height();

    titleLabel->setGeometry(_w/10,_h/8,_w*4/5,_h*3/8);
    contentLabel->setGeometry(_w/6,_h*2/5,_w*2/3,_h/4);
    leftButton->setGeometry(_w/6,_h*3/4,_w/4,_h/8);
    rightButton->setGeometry(_w*7/12,_h*3/4,_w/4,_h/8);

}

void GameMessageBox::leftButtonClicked()
{
    emit LeftButtonClicked();
}

void GameMessageBox::rightButtonClicked()
{
    emit RightButtonClicked();
}
