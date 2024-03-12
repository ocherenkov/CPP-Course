#include "UI/ProgressBar.h"

ProgressBar::ProgressBar(const std::string& frameTextureName, const std::string& barTextureName, int offsetPos): m_offsetPos(offsetPos) {
    m_frame.setTexture(AssetManager::getInstance().getTexture(frameTextureName));
    m_bar.setTexture(AssetManager::getInstance().getTexture(barTextureName));
    m_frameSize = m_frame.getTexture()->getSize();
    m_barSize = m_bar.getTexture()->getSize();
}

void ProgressBar::setPosition(float x, float y) {
    m_frame.setPosition(x, y);
    m_bar.setPosition(x + m_offsetPos, y + m_offsetPos);
}

void ProgressBar::setValue(float value, float maxValue) {
    float percentage = value / maxValue;
    int width = static_cast<int>((m_frameSize.x - 2 * m_offsetPos) * percentage);
    m_bar.setTextureRect(sf::IntRect(0, 0, width, m_barSize.y));
}

void ProgressBar::draw(sf::RenderWindow& window) {
    window.draw(m_frame);
    window.draw(m_bar);
}

HPBar::HPBar() : ProgressBar("frameHp", "barHp", 3) {}

ExpBar::ExpBar() : ProgressBar("frameExp", "barExp", 12) {}