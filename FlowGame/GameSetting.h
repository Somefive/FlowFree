#ifndef GAMESETTING
#define GAMESETTING

#include <QPoint>
#include <QBrush>
#include <QColor>

class GameSetting
{

private:
    void LoadFile();
    void SaveFile();
    QString gameDataPath;
    QString userDataPath;

public:

    static int GameCount;

    int gameNo;
    int currentflows;
    int pipeFilled;
    int moves;
    int best;
    int level;
    int colorNumber;

    QPoint Points[50];

    void setBest(int _best);

    GameSetting(int _level,int _gameNo);
    ~GameSetting();

    static GameSetting getNextGame(const GameSetting& currentSetting);
    static GameSetting getPreviousGame(const GameSetting& currentSetting);
};

namespace GameData
{
    const int GameMinLevel = 5;
    const int GameMaxLevel = 14;
    const int GameMaxNo[] = {30,30,30,30,30,30,30,30,30,30};

    const QColor ColorSet[] = {QColor(255,80,80),
                               QColor(80,255,80),
                               QColor(80,80,255),
                               QColor(255,255,80),
                               QColor(255,80,255),
                               QColor(80,255,255),
                               QColor(160,40,40),
                               QColor(40,160,40),
                               QColor(40,40,160),
                               QColor(128,0,0),
                               QColor(0,128,0),
                               QColor(0,0,128),
                               QColor(255,128,0),
                               QColor(0,255,128),
                               QColor(128,0,255)};

    const QColor BgColor(80,80,80);
    const QBrush BgBrush(BgColor);
}


#endif // GAMESETTING

