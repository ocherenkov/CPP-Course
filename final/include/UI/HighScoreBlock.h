#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "AssetManager.h"
#include "Config.h"

class HighScoreBlock {
public:
    HighScoreBlock();

    void setHighScore(const Highscore& highscore);
    void draw(sf::RenderWindow& window);

private:
    sf::Sprite m_sprite;
    sf::Text m_text;
};