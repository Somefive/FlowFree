#include "MyMessagebox.h"
#include "mypainter.h"
#include "GameSetting.h"
#include "mymessagepanel.h"

#include <QDebug>

MyMessageBox::MyMessageBox(QWidget *_widget,QString _title, QString _content):
    MyMessagePanel(_widget),Title(_title),Content(_content)
{
    QRect rect  = _widget->rect();
    this->setGeometry(rect.width()/4,rect.height()/4,rect.width()/2,rect.height()/3);

    titleLabel = new QLabel(Title,this);
    contentLabel = new QLabel(Content,this);

    leftButton = new QPushButton("Retry",this);
    rightButton = new QPushButton("Next",this);

    Initialize();

    connect(leftButton,SIGNAL(clicked(bool)),this,SLOT(leftButtonClicked()));
    connect(rightButton,SIGNAL(clicked(bool)),this,SLOT(rightButtonClicked()));
    connect(leftButton,SIGNAL(pressed()),this,SLOT(leftButtonPressed()));
    connect(rightButton,SIGNAL(pressed()),this,SLOT(rightButtonPressed()));
    connect(leftButton,SIGNAL(released()),this,SLOT(leftButtonReleased()));
    connect(rightButton,SIGNAL(released()),this,SLOT(rightButtonReleased()));

}

void MyMessageBox::Initialize()
{
    titleLabel->setFont(QFont("Lucida Bright",16));
    contentLabel->setFont(QFont("Lucida Bright",12));
    titleLabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    contentLabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    QPalette _palette;
    _palette.setColor(QPalette::WindowText,Qt::yellow);
    titleLabel->setPalette(_palette);
    _palette.setColor(QPalette::WindowText,Qt::white);
    contentLabel->setPalette(_palette);
    _palette.setColor(QPalette::ButtonText,Qt::white);
    leftButton->setStyleSheet("background-color:black;");
    rightButton->setStyleSheet("background-color:black;");
    leftButton->setPalette(_palette);
    rightButton->setPalette(_palette);
    leftButton->setFont(QFont("Century Gothic",10));
    rightButton->setFont(QFont("Century Gothic",10));
}

void MyMessageBox::paintEvent(QPaintEvent *event)
{
    MyMessagePanel::paintEvent(event);


    int _w = this->width(), _h=this->height();

    titleLabel->setGeometry(_w/6,_h/6,_w*2/3,_h/3);
    contentLabel->setGeometry(_w/6,_h*2/5,_w*2/3,_h/4);
    leftButton->setGeometry(_w/6,_h*3/4,_w/4,_h/8);
    rightButton->setGeometry(_w*7/12,_h*3/4,_w/4,_h/8);

}

void MyMessageBox::leftButtonClicked()
{
    emit Confirm(false);
}

void MyMessageBox::rightButtonClicked()
{
    emit Confirm(true);
}

void MyMessageBox::ButtonPressed(QPushButton *button)
{
    QPalette _palette;
    _palette.setColor(QPalette::ButtonText,Qt::black);
    button->setStyleSheet("background-color:gray;");
    button->setPalette(_palette);
    button->update();
}

void MyMessageBox::ButtonReleased(QPushButton *button)
{
    QPalette _palette;
    _palette.setColor(QPalette::ButtonText,Qt::white);
    button->setStyleSheet("background-color:black;");
    button->setPalette(_palette);
    button->update();
}

void MyMessageBox::leftButtonPressed()
{
    ButtonPressed(leftButton);
}

void MyMessageBox::rightButtonPressed()
{
    ButtonPressed(rightButton);
}

void MyMessageBox::leftButtonReleased()
{
    ButtonReleased(leftButton);
}

void MyMessageBox::rightButtonReleased()
{
    ButtonReleased(rightButton);
}
