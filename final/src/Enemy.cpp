#include "Enemy.h"

Enemy::Enemy(Player* player, sf::Vector2f spawnPosition)
        : m_player(player), m_position(spawnPosition), m_isAttacking(false), m_isDestroyed(false), m_points(5) {}

sf::Vector2f Enemy::getPosition() const {
    return m_position;
}

sf::Sprite Enemy::getSprite() const {
    return m_sprite;
}

int Enemy::getPoints() const {
    return m_points;
}

Item* Enemy::getDropItem() const {
    return m_dropItem;
};

bool Enemy::isDestroyed() const {
    return m_isDestroyed;
};

void Enemy::takeDamage(int damage) {
    m_health -= damage;
    if (m_health <= 0) {
        m_isDestroyed = true;
    }
}

void Enemy::moveTowardsPlayer(float deltaTime, float distance, sf::Vector2f& direction) {
    direction.x /= distance;
    direction.y /= distance;

    m_position += direction * deltaTime * m_speed;
    m_sprite.setPosition(m_position);
    m_sprite.setTexture(m_textureRun);
}

bool Enemy::checkAttackCooldown() {
    if (m_attackCooldown.getElapsedTime().asSeconds() >= m_attackInterval) {
        m_isAttacking = true;
        m_attackCooldown.restart();
        return true;
    }
    return false;
}

void Enemy::attackPlayer() {
    if (m_isAttacking) {
        m_player->takeDamage(m_damage);
        m_isAttacking = false;
        m_sprite.setTexture(m_textureAttack);
    }
}

void Enemy::updateAnimation(float deltaTime, const sf::Vector2f& direction) {
    bool isMovingRight = direction.x < 0;
    m_sprite.setTextureRect(m_animationSprite->getRect(deltaTime, isMovingRight));
}

void Enemy::update(float deltaTime) {
    sf::Vector2f direction = m_player->getPosition() - m_position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > m_attackDistance) {
        moveTowardsPlayer(deltaTime, distance, direction);
    } else {
        if (checkAttackCooldown()) {
            attackPlayer();
        }
    }

    updateAnimation(deltaTime, direction);
}



void Enemy::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}

Hyena::Hyena(Player* player, sf::Vector2f spawnPosition)
        : Enemy(player, spawnPosition) {
    m_speed = 20.f;
    m_health = 10;
    m_damage = 10;
    m_attackInterval = 1.f;
    m_attackDistance = 40.f;
    m_textureRun = AssetManager::getInstance().getTexture("hyenaRun");
    m_textureAttack = AssetManager::getInstance().getTexture("hyenaAttack");
    m_animationSprite = new AnimationSprite(sf::Vector2u(6, 2), sf::Vector2u(48, 48), 0.1f);
    m_dropItem = new ExperienceOrb();
}

Snake::Snake(Player* player, sf::Vector2f spawnPosition)
        : Enemy(player, spawnPosition) {
    m_speed = 40.f;
    m_health = 2;
    m_damage = 5;
    m_attackInterval = 2.f;
    m_attackDistance = 40.f;
    m_textureRun = AssetManager::getInstance().getTexture("snakeRun");
    m_textureAttack = AssetManager::getInstance().getTexture("snakeAttack");
    m_animationSprite = new AnimationSprite(sf::Vector2u(4, 2), sf::Vector2u(48, 48), 0.2f);
    m_dropItem = new ExperienceOrb();
}

Scorpio::Scorpio(Player* player, sf::Vector2f spawnPosition)
        : Enemy(player, spawnPosition) {
    m_speed = 10.f;
    m_health = 5;
    m_damage = 2;
    m_attackInterval = 3.f;
    m_attackDistance = 150.f;
    m_textureRun = AssetManager::getInstance().getTexture("scorpioRun");
    m_textureAttack = AssetManager::getInstance().getTexture("scorpioAttack");
    m_animationSprite = new AnimationSprite(sf::Vector2u(4, 2), sf::Vector2u(48, 48), 0.2f);
    m_dropItem = new ExperienceOrb();
}

KingSlime::KingSlime(Player* player, sf::Vector2f spawnPosition)
        : Enemy(player, spawnPosition) {
    m_speed = 25.f;
    m_health = 30;
    m_damage = 15;
    m_attackInterval = 4.f;
    m_attackDistance = 100.f;
    m_textureRun = AssetManager::getInstance().getTexture("kingSlimeRun");
    m_textureAttack = AssetManager::getInstance().getTexture("kingSlimeAttack");
    m_animationSprite = new AnimationSprite(sf::Vector2u(8, 2), sf::Vector2u(100, 120), 0.3f);
    m_dropItem = new Chest();
}