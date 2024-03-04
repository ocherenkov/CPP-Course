#include "Player.h"

Player::Player(): m_texture(AssetManager::getInstance().getTexture("m_player")), m_position({Config::getInstance().getWindowWidth() / 2.f, Config::getInstance().getWindowHeight() / 2.f}) {
    m_expBar.setPosition((Config::getInstance().getWindowWidth() - AssetManager::getInstance().getTexture("frameExp").getSize().x) / 2.f, 10);
    m_playerLevelText.setLevel(m_level);

    m_textureSize = sf::Vector2u(48, 48);
    m_animationSprite = new AnimationSprite(sf::Vector2u(3, 5), m_textureSize, 0.5f);
    m_sprite.setTexture(m_texture);

    Player::generateUpgrades();
}

void Player::update(float deltaTime) {
    m_hpBar.setPosition(m_position.x, m_position.y - 10);
    m_hpBar.setValue(m_health, m_maxHealth);

    m_expBar.setValue(m_experience, m_experienceToNextLevel);

    sf::Vector2f movement(0.f, 0.f);
    Player::determineMovement(movement, deltaTime);

    m_position += movement * deltaTime * m_speed;
    Player::limitPosition();

    m_sprite.setPosition(m_position);

    Player::updateProjectiles(deltaTime);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
    m_hpBar.draw(window);
    m_expBar.draw(window);
    m_playerLevelText.draw(window);
    for(auto& projectile : m_projectiles) {
        projectile.draw(window);
    }
}

sf::Vector2f Player::getPosition() const {
    return m_position;
}

sf::Sprite Player::getSprite() {
    return m_sprite;
}

int Player::getLevel() const {
    return m_level;
}

bool Player::isMoving() const {
    return m_isMoving;
}

bool Player::isLevelUp() const {
    return m_isLevelUp;
}

void Player::clearLevelUpFlag() {
    m_isLevelUp = false;
}

std::vector<Upgrade>& Player::getUpgrades() {
    return m_upgrades;
}

std::vector<Projectile>& Player::getProjectiles() {
    return m_projectiles;
}

void Player::takeDamage(int damage) {
    m_health -= damage;
    if (m_health <= 0) {
        m_health = 0;
    }
}

void Player::shoot(sf::Vector2f direction) {
    if (m_shootCooldown.getElapsedTime().asSeconds() > m_attackInterval) {
        m_projectiles.push_back(Projectile(m_sprite.getPosition(), direction, m_attackSpeed, m_attackDamage));
        m_shootCooldown.restart();
    }
}

bool Player::isAlive() const {
    return m_health > 0;
}

void Player::gainExperience(int value) {
    m_experience += value;
    if (m_experience >= m_experienceToNextLevel) {
        Player::levelUp();
    }
}

void Player::heal(int value) {
    m_health += value;
    if (m_health > m_maxHealth) {
        m_health = m_maxHealth;
    }
}

void Player::addUpgrade(const Upgrade& upgrade) {
    m_upgrades.push_back(upgrade);
}

void Player::determineMovement(sf::Vector2f& movement, float deltaTime) {
    m_isMoving = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x -= m_speed * deltaTime;
        m_sprite.setTextureRect(m_animationSprite->getRect(deltaTime, static_cast<int>(DirectionMovement::LEFT)));
        m_isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x += m_speed * deltaTime;
        m_sprite.setTextureRect(m_animationSprite->getRect(deltaTime, static_cast<int>(DirectionMovement::RIGHT)));
        m_isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        movement.y -= m_speed * deltaTime;
        m_sprite.setTextureRect(m_animationSprite->getRect(deltaTime, static_cast<int>(DirectionMovement::UP)));
        m_isMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        movement.y += m_speed * deltaTime;
        m_sprite.setTextureRect(m_animationSprite->getRect(deltaTime, static_cast<int>(DirectionMovement::DOWN)));
        m_isMoving = true;
    }

    if (!m_isMoving) {
        sf::IntRect rect = m_animationSprite->getRect(deltaTime, static_cast<int>(DirectionMovement::IDLE));
        m_sprite.setTextureRect(rect);
    }
}

void Player::limitPosition() {
    m_position.x = std::max(0.f, std::min(m_position.x, Config::getInstance().getWindowWidth() - m_textureSize.x));
    m_position.y = std::max(55.f, std::min(m_position.y, Config::getInstance().getWindowHeight() - m_textureSize.y));
}

void Player::updateProjectiles(float deltaTime) {
    for (auto projectile = m_projectiles.begin(); projectile != m_projectiles.end();) {
        projectile->update(deltaTime);
        if (projectile->isDestroyed()) {
            projectile = m_projectiles.erase(projectile);
        } else {
            projectile++;
        }
    }
}

void Player::levelUp() {
    m_isLevelUp = true;
    m_level++;
    m_experience -= m_experienceToNextLevel;
    m_experienceToNextLevel *= 1.5;
    m_health = m_maxHealth;
    m_playerLevelText.setLevel(m_level);
}

void Player::generateUpgrades() {
    addUpgrade(Upgrade(AssetManager::getInstance().getTexture("upgradeHp"), [&]() {
        upgradeHp(20);
    }));
    addUpgrade(Upgrade(AssetManager::getInstance().getTexture("upgradeDamage"), [&]() {
        upgradeDamage(20);
    }));
    addUpgrade(Upgrade(AssetManager::getInstance().getTexture("upgradeAttackSpeed"), [&]() {
        upgradeAttackSpeed(20);
    }));
}

void Player::upgradeHp(float percent) {
    m_maxHealth += m_maxHealth * (percent / 100);
}

void Player::upgradeDamage(float percent) {
    m_attackDamage += m_attackDamage * (percent / 100);
}

void Player::upgradeAttackSpeed(float percent) {
    m_attackSpeed += m_attackSpeed * (percent / 100);
}