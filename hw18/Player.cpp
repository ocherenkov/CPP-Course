#include <iostream>
#include "Player.h"

Player::~Player()
{
    delete m_class;
    delete m_weapon;
}

void Player::setWeapon(Weapon* weapon)
{
    delete m_weapon;
    m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass* playerClass)
{
    delete m_class;
    m_class = playerClass;
}

void Player::setDamage(int damage) {
    m_health -= damage;
    if (m_health <= 0) {
        m_health = 0;
    }
}

int getRandomNumber() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomNumber = std::rand() % 101;
    return randomNumber;
}

void Player::attack(Player& other, int distance) {
    if (&other == this)
    {
        std::cout << "\n-------FRIENDLY FIRE!-------\n";
    }

    if (isEliminated()) {
        std::cout << "Player " << getName() << " already eliminated x_x" << std::endl;
        return;
    }

    if (other.isEliminated())
    {
        std::cout << "Player " << other.getName() << " has been already eliminated!\n";
        return;
    }

    std::srand(std::time(nullptr));
    int damage = 0;
    int hitChance = std::rand() % 101;
    int missChance = other.m_class->getMissChance() * 100;
    if (hitChance > missChance) {
        damage = static_cast<int>(m_weapon->getDamage(distance) * m_class->getDamageMultiplier() / other.m_class->getArmorMultiplier());
    }
    other.setDamage(damage);

    std::cout << "Player " << getName() << " attacked Player " << other.getName() <<
              " with damage " << damage << ", health left: " << other.getHealth() << std::endl;
}
