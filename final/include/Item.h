#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class Item {
public:
    sf::Sprite getSprite() const;

    virtual void drop(sf::Vector2f position);

    virtual bool collect(Player* player) = 0;

    void draw(sf::RenderWindow& window);

protected:
    sf::Sprite m_sprite;
    int m_value = 0;
};

class ExperienceOrb : public Item {
public:
    ExperienceOrb();

    bool collect(Player* player) override;
};

class HealthPotion : public Item {
public:
    HealthPotion();

    void drop(sf::Vector2f position) override;

    bool collect(Player* player) override;
};

class Chest : public Item {
public:
    Chest();

    bool collect(Player* player) override;
};