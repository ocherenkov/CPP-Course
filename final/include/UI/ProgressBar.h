#pragma once
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class ProgressBar {
public:
    ProgressBar(const std::string& frameTextureName, const std::string& barTextureName, int offsetPos);

    void setPosition(float x, float y);
    void setValue(float value, float maxValue);
    void draw(sf::RenderWindow& window);

protected:
    sf::Sprite m_frame;
    sf::Sprite m_bar;
    sf::Vector2u m_frameSize;
    sf::Vector2u m_barSize;
    int m_offsetPos;
};

class HPBar : public ProgressBar {
public:
    HPBar();
};

class ExpBar : public ProgressBar {
public:
    ExpBar();
};