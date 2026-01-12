#include "soundmanager.h"

#include <QUrl>

SoundManager::SoundManager(QObject* parent): QObject(parent)
{
    buttonClick.setSource(QUrl("qrc:/sounds/assets/sounds/button_click.wav"));
    buttonClick.setVolume(100);
    cardDeal.setSource(QUrl("qrc:/sounds/assets/sounds/card_deal.wav"));
    cardDeal.setVolume(100);

    musicPlayer.setAudioOutput(&audioOutput);
    musicPlayer.setSource(QUrl("qrc:/sounds/assets/sounds/background_music.wav"));
    audioOutput.setVolume(50);
}

void SoundManager::playButtonClick()
{
    buttonClick.play();
}

void SoundManager::playCardDeal()
{
    cardDeal.play();
}

void SoundManager::startBackgroundMusic()
{
    musicPlayer.setLoops(QMediaPlayer::Infinite);
    musicPlayer.play();
}

void SoundManager::stopBackgroundMusic()
{
    musicPlayer.stop();
}


