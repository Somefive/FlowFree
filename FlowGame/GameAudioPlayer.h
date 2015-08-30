#ifndef GAMEAUDIOPLAYER
#define GAMEAUDIOPLAYER

#include <QWidget>

class Pipe;
class GameController;

class GameAudioPlayer: public QWidget
{
    Q_OBJECT

public slots:

    void CompletePipe(Pipe*);
    void BreakPipe(Pipe*);
    void CompleteGame();
    void ForwardPipe();
    void BackwardPipe();

private:

    int flowCount;

    QString rootPath;

    GameController* gameController;

public:

    GameAudioPlayer(GameController*);

};

#endif // GAMEAUDIOPLAYER

