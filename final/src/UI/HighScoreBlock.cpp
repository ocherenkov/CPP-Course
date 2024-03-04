#include "UI/HighScoreBlock.h"

HighScoreBlock::HighScoreBlock() {
    m_sprite.setTexture(AssetManager::getInstance().getTexture("block"));

    m_text.setFont(AssetManager::getInstance().getFont("main"));
    m_text.setCharacterSize(18);
    m_text.setFillColor(sf::Color(53, 57, 69));
}

void HighScoreBlock::setHighScore(const Highscore& highscore) {
    std::ostringstream info;
    info << "Player level: " << highscore.playerLevel << std::endl << std::endl;
    info << "Score: " << highscore.score << std::endl << std::endl;
    info << "Time: " << highscore.time << " sec";

    m_text.setString(info.str());

    float spritePosX = (Config::getInstance().getWindowWidth() - m_sprite.getLocalBounds().width) / 2;
    float spritePosY = (Config::getInstance().getWindowHeight() - m_sprite.getLocalBounds().height) / 2;
    m_sprite.setPosition(spritePosX, spritePosY);

    sf::FloatRect textBounds = m_text.getLocalBounds();
    float textPosX = spritePosX + (m_sprite.getLocalBounds().width - textBounds.width) / 2;
    float textPosY = spritePosY + (m_sprite.getLocalBounds().height - textBounds.height) / 2;
    m_text.setPosition(textPosX, textPosY);
}

void HighScoreBlock::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
    window.draw(m_text);
}