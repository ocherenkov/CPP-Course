#include "UI/UpgradeModal.h"

UpgradeModal::UpgradeModal(const std::vector<Upgrade>& upgrades) : m_upgrades(upgrades) {
    m_modalBackground = sf::RectangleShape(sf::Vector2f(415, 190));
    m_modalBackground.setFillColor(sf::Color(0, 0, 0, 150));
    m_modalBackground.setPosition((Config::getInstance().getWindowWidth() - m_modalBackground.getSize().x) / 2,
                                  (Config::getInstance().getWindowHeight() - m_modalBackground.getSize().y) / 2);

    m_text.setFont(AssetManager::getInstance().getFont("main"));
    m_text.setCharacterSize(16);
    m_text.setString("Choose one upgrade");
    m_text.setFillColor(sf::Color::White);

    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_text.setPosition(
            m_modalBackground.getPosition().x + m_modalBackground.getSize().x / 2.0f,
            m_modalBackground.getPosition().y + m_modalBackground.getSize().y - textRect.height - 10
    );

    float startX = m_modalBackground.getPosition().x + 10;
    float startY = m_modalBackground.getPosition().y + 20;
    float padding = 5;
    for (size_t i = 0; i < upgrades.size(); i++) {
        sf::Sprite icon(upgrades[i].getTexture());
        float iconX = startX + (icon.getGlobalBounds().width + padding) * i;
        icon.setPosition(iconX, startY);
        m_upgradeSprites.push_back(icon);
    }
}

void UpgradeModal::show() {
    m_visible = true;
}

void UpgradeModal::hide() {
    m_visible = false;
}

bool UpgradeModal::isVisible() const {
    return m_visible;
}

void UpgradeModal::handleClick(const sf::Vector2i& mousePosition) {
    if (!m_visible) return;
    for (size_t i = 0; i < m_upgrades.size(); i++) {
        sf::FloatRect bounds = m_upgradeSprites[i].getGlobalBounds();
        if (bounds.contains(static_cast<sf::Vector2f>(mousePosition))) {
            m_upgrades[i].applyUpgrade();
            hide();
            break;
        }
    }
}

void UpgradeModal::draw(sf::RenderWindow& window) {
    if (!m_visible) return;
    window.draw(m_modalBackground);
    window.draw(m_text);
    for (size_t i = 0; i < m_upgrades.size(); i++) {
        window.draw(m_upgradeSprites[i]);
    }
}