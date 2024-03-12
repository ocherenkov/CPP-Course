#pragma once

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Projectile {
public:
    Projectile(sf::Vector2f position, sf::Vector2f velocity, float speed, int damage);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::Sprite getSprite() const;
    int getDamage() const;
    void destroy();
    bool isDestroyed() const;

private:
    sf::Sprite m_sprite;
    sf::Vector2f m_velocity;
    float m_speed;
    int m_damage;
    bool m_isDestroyed;
};