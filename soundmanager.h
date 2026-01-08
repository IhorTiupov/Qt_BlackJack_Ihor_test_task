#pragma once

#include <QObject>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QAudioOutput>



class SoundManager: public QObject
{
    Q_OBJECT
public:
    explicit SoundManager(QObject* parent = nullptr);

    void playButtonClick();
    void playCardDeal();
    void startBackgroundMusic();
    void stopBackgroundMusic();

private:
    QSoundEffect buttonClick;
    QSoundEffect cardDeal;
    QMediaPlayer musicPlayer;
    QAudioOutput audioOutput;
};

