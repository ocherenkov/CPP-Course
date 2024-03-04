#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <memory>
#include "Config.h"
#include "UI/ProgressBar.h"
#include "UI/DisplayText.h"
#include "Projectile.h"
#include "Upgrade.h"
#include "AnimationSprite.h"

enum class DirectionMovement {
    IDLE,
    DOWN,
    LEFT,
    RIGHT,
    UP
};

class Player {
public:
    Player();

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    int getLevel() const;
    bool isMoving() const;
    bool isLevelUp() const;
    void clearLevelUpFlag();
    sf::Sprite getSprite();
    std::vector<Upgrade>& getUpgrades();
    std::vector<Projectile>& getProjectiles();
    void takeDamage(int damage);
    void shoot(sf::Vector2f direction);
    bool isAlive() const;
    void gainExperience(int value);
    void heal(int value);
    void addUpgrade(const Upgrade& upgrade);

private:
    sf::Vector2f m_position;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    float m_speed = 100.f;
    int m_health = 100;
    int m_maxHealth = 100;
    int m_level = 1;
    int m_experience = 0;
    int m_experienceToNextLevel = 100;
    HPBar m_hpBar;
    ExpBar m_expBar;
    PlayerLevelText m_playerLevelText;
    std::vector<Projectile> m_projectiles;
    sf::Clock m_shootCooldown;
    float m_attackInterval = 0.3f;
    float m_attackSpeed = 5.f;
    float m_attackDamage = 1;
    bool m_isMoving = false;
    bool m_isLevelUp = false;
    AnimationSprite* m_animationSprite;
    sf::Vector2u m_textureSize;
    std::vector<Upgrade> m_upgrades;

    void determineMovement(sf::Vector2f& movement, float deltaTime);
    void limitPosition();
    void updateProjectiles(float deltaTime);
    void levelUp();
    void generateUpgrades();
    void upgradeHp(float percent);
    void upgradeDamage(float percent);
    void upgradeAttackSpeed(float percent);
};