#include "Projectile.h"

Projectile::Projectile(sf::Vector2f position, sf::Vector2f velocity, float speed, int damage)
        : m_velocity(velocity), m_speed(speed), m_damage(damage), m_isDestroyed(false) {
    int offsetPos = 20;
    m_sprite.setTexture(AssetManager::getInstance().getTexture("projectileMain"));
    m_sprite.setPosition(position + sf::Vector2f(offsetPos, offsetPos));
}

void Projectile::update(float deltaTime) {
    m_sprite.move(m_velocity * deltaTime * m_speed);
}

void Projectile::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}

sf::Sprite Projectile::getSprite() const {
    return m_sprite;
}

int Projectile::getDamage() const {
    return m_damage;
}

void Projectile::destroy() {
    m_isDestroyed = true;
}

bool Projectile::isDestroyed() const {
    return m_isDestroyed;
}