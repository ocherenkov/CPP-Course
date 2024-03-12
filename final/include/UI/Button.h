#pragma once

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Button {
public:
    Button(const std::string& buttonText, const sf::Vector2f& position);

    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    bool isMouseOver(sf::RenderWindow& window);

private:
    sf::Texture m_normalTexture;
    sf::Texture m_hoverTexture;
    sf::Sprite m_sprite;
    sf::Text m_text;
};