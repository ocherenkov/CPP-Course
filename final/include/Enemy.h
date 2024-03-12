#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Player.h"
#include "AnimationSprite.h"
#include "Item.h"

class Enemy {
public:
    Enemy(Player* player, sf::Vector2f spawnPosition);

    sf::Vector2f getPosition() const;
    sf::Sprite getSprite() const;
    int getPoints() const;
    Item* getDropItem() const;
    bool isDestroyed() const;
    void takeDamage(int damage);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

protected:
    sf::Vector2f m_position;
    sf::Texture m_textureRun;
    sf::Texture m_textureAttack;
    sf::Sprite m_sprite;
    Player* m_player;
    Item* m_dropItem;
    float m_speed;
    int m_health;
    int m_damage;
    sf::Clock m_attackCooldown;
    float m_attackInterval;
    float m_attackDistance;
    bool m_isAttacking;
    bool m_isDestroyed;
    int m_points;
    AnimationSprite* m_animationSprite;

    void moveTowardsPlayer(float deltaTime, float distance, sf::Vector2f& direction);
    bool checkAttackCooldown();
    void attackPlayer();
    void updateAnimation(float deltaTime, const sf::Vector2f& direction);
};

class Hyena: public Enemy {
public:
    Hyena(Player* player, sf::Vector2f spawnPosition);
};

class Snake: public Enemy {
public:
    Snake(Player* player, sf::Vector2f spawnPosition);
};

class Scorpio: public Enemy {
public:
    Scorpio(Player* player, sf::Vector2f spawnPosition);
};

class KingSlime: public Enemy {
public:
    KingSlime(Player* player, sf::Vector2f spawnPosition);
};