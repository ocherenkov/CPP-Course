#pragma once

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Config.h"

class DisplayText {
public:
    DisplayText(const std::string& textureName);

    void setText(const std::string& text);
    void setPosition(float x, float y);
    virtual std::string formatTime(float time);
    void draw(sf::RenderWindow& window);

protected:
    sf::Sprite m_sprite;
    sf::Text m_text;
    sf::Vector2i m_offsetPos;
};

class ScoreText: public DisplayText {
public:
    ScoreText();
    void setScore(int score);
};

class TimeText: public DisplayText {
public:
    TimeText();
    void setTime(float time);
    std::string formatTime(float time) override;
};

class BossTimerText: public DisplayText {
public:
    BossTimerText(int countdownTime);

    void setTime(float time);
    std::string formatTime(float time) override;

private:
    int m_countdownTime;
};

class PlayerLevelText: public DisplayText {
public:
    PlayerLevelText();
    void setLevel(int level);
};