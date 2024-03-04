#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>

class Upgrade {
public:
    Upgrade(sf::Texture texture, std::function<void()> applyFunction): m_texture(texture), m_apply(applyFunction) {}

    const sf::Texture& getTexture() const {
        return m_texture;
    }

    void applyUpgrade() const {
        m_apply();
    }

private:
    sf::Texture m_texture;
    std::function<void()> m_apply;
};