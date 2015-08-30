#ifndef GAMEMESSAGEBOX
#define GAMEMESSAGEBOX

#include "gameviewpanel.h"
#include "gamebutton.h"

#include <QWidget>
#include <QString>
#include <QLabel>

class GameMessageBox: public GameViewPanel
{
    Q_OBJECT

private slots:
    void leftButtonClicked();
    void rightButtonClicked();

signals:
    void LeftButtonClicked();
    void RightButtonClicked();

private:

    QString Title;
    QString Content;

    QLabel* titleLabel;
    QLabel* contentLabel;

    GameButton* leftButton;
    GameButton* rightButton;

    void Initialize();

protected:

    virtual void paintEvent(QPaintEvent*);

public:

    GameMessageBox(QWidget*,const QString&,const QString&,const QString&,const QString&);

};

#endif // GAMEMESSAGEBOX

