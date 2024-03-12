#include "UI/DisplayText.h"

DisplayText::DisplayText(const std::string& textureName) {
    m_offsetPos = sf::Vector2i(10, 5);
    m_sprite.setTexture(AssetManager::getInstance().getTexture(textureName));

    m_text.setFont(AssetManager::getInstance().getFont("main"));
    m_text.setCharacterSize(20);
    m_text.setFillColor(sf::Color::White);
}

void DisplayText::setText(const std::string& text) {
    m_text.setString(text);
}

void DisplayText::setPosition(float x, float y) {
    m_sprite.setPosition(x, y);
    m_text.setPosition(x + m_sprite.getGlobalBounds().width + m_offsetPos.x, y + m_offsetPos.y);
}

std::string DisplayText::formatTime(float time) {
    int minutes = static_cast<int>(time) / 60;
    int seconds = static_cast<int>(time) % 60;

    std::string minutesStr = minutes < 10 ? "0" + std::to_string(minutes) : std::to_string(minutes);
    std::string secondsStr = seconds < 10 ? "0" + std::to_string(seconds) : std::to_string(seconds);

    return minutesStr + ":" + secondsStr;
}

void DisplayText::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
    window.draw(m_text);
}

ScoreText::ScoreText(): DisplayText("m_score") {
    DisplayText::setPosition(75, 10);
    DisplayText::setText("0");
}

void ScoreText::setScore(int score) {
    DisplayText::setText(std::to_string(score));
}

TimeText::TimeText(): DisplayText("time") {
    DisplayText::setPosition(Config::getInstance().getWindowWidth() - 110, 10);
}

void TimeText::setTime(float time) {
    DisplayText::setText(formatTime(time));
}

std::string TimeText::formatTime(float time) {
    return DisplayText::formatTime(time);
}

BossTimerText::BossTimerText(int countdownTime): DisplayText("m_bossTimer"), m_countdownTime(countdownTime) {
    DisplayText::setPosition(Config::getInstance().getWindowWidth() - 230, 10);
}

void BossTimerText::setTime(float time) {
    DisplayText::setText(formatTime(time));
}

std::string BossTimerText::formatTime(float time) {
    float timeUntilBoss = m_countdownTime - time;
    if (timeUntilBoss < 0) {
        timeUntilBoss = 0;
    }
    return DisplayText::formatTime(timeUntilBoss);
}

PlayerLevelText::PlayerLevelText(): DisplayText("playerLevel") {
    DisplayText::setPosition(10, 10);
    DisplayText::setText("0");
}

void PlayerLevelText::setLevel(int level) {
    setText(std::to_string(level));
}

