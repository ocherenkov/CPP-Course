#include "Item.h"

sf::Sprite Item::getSprite() const {
    return m_sprite;
}

void Item::drop(sf::Vector2f position) {
    m_sprite.setPosition(position);
}

void Item::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}

ExperienceOrb::ExperienceOrb() {
    m_value = 10;
    m_sprite.setTexture(AssetManager::getInstance().getTexture("experienceOrb"));
}

bool ExperienceOrb::collect(Player* player) {
    player->gainExperience(m_value);
    return player->isLevelUp();
}

HealthPotion::HealthPotion() {
    m_value = 25;
    m_sprite.setTexture(AssetManager::getInstance().getTexture("healthPotion"));
}

void HealthPotion::drop(sf::Vector2f position) {
    int offsetPos = 12;
    m_sprite.setPosition(position + sf::Vector2f(offsetPos, offsetPos));
}

bool HealthPotion::collect(Player* player) {
    player->heal(m_value);
    return false;
}

Chest::Chest() {
    m_sprite.setTexture(AssetManager::getInstance().getTexture("chest"));
}

bool Chest::collect(Player* player) {
    return true;
}