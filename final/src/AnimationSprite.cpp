#include "AnimationSprite.h"

AnimationSprite::AnimationSprite(sf::Vector2u imageCount, sf::Vector2u imageSize, float switchTime)
        : m_imageCount(imageCount), m_totalTime(0.0f), m_switchTime(switchTime), m_imageSize(imageSize), m_currentImage(0, 0) {
}

sf::IntRect AnimationSprite::getRect(float deltaTime, int direction) {
    m_currentImage.y = direction;

    m_totalTime += deltaTime;
    if (m_totalTime >= m_switchTime) {
        m_totalTime -= m_switchTime;
        m_currentImage.x++;
        if (m_currentImage.x >= m_imageCount.x) {
            m_currentImage.x = 0;
        }
    }
    return sf::IntRect(m_currentImage.x * m_imageSize.x, m_currentImage.y * m_imageSize.y, m_imageSize.x, m_imageSize.y);
}