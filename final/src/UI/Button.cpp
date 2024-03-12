#include "UI/Button.h"

Button::Button(const std::string& buttonText, const sf::Vector2f& position) {
    m_normalTexture = AssetManager::getInstance().getTexture("button");
    m_hoverTexture = AssetManager::getInstance().getTexture("buttonHover");

    m_sprite.setTexture(m_normalTexture);
    m_sprite.setPosition(position);

    m_text.setFont(AssetManager::getInstance().getFont("main"));
    m_text.setString(buttonText);
    m_text.setCharacterSize(20);
    m_text.setFillColor(sf::Color(53, 57, 69));

    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_text.setPosition(sf::Vector2f(position.x + m_sprite.getGlobalBounds().width / 2.0f, position.y + m_sprite.getGlobalBounds().height / 2.0f - 6));
}

void Button::update(sf::RenderWindow& window) {
    if (isMouseOver(window)) {
        m_sprite.setTexture(m_hoverTexture);
    } else {
        m_sprite.setTexture(m_normalTexture);
    }
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
    window.draw(m_text);
}

bool Button::isMouseOver(sf::RenderWindow& window) {
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    sf::FloatRect bounds = m_sprite.getGlobalBounds();

    return bounds.contains(static_cast<float>(mouseX), static_cast<float>(mouseY));
}