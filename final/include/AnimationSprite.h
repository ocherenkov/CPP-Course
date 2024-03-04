#pragma once
#include <SFML/Graphics.hpp>

class AnimationSprite {
public:
    AnimationSprite(sf::Vector2u imageCount, sf::Vector2u imageSize, float switchTime);

    sf::IntRect getRect(float deltaTime, int direction);

private:
    sf::Vector2u m_imageSize;
    sf::Vector2u m_imageCount;
    sf::Vector2u m_currentImage;

    float m_totalTime;
    float m_switchTime;
};