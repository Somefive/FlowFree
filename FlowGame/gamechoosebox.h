#ifndef GAMECHOOSEBOX_H
#define GAMECHOOSEBOX_H

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QList>

#include

class GameChooseBox : public QWidget
{
    Q_OBJECT

protected:


    QStringList Choices;
    int Current;

    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void wheelEvent(QWheelEvent *);

public:

    QString Value();
    explicit GameChooseBox(QWidget *parent = 0);

signals:

public slots:

};

#endif // GAMECHOOSEBOX_H
