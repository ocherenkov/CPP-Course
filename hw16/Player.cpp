#include "Player.h"
#include "Weapon.h"
#include "Team.h"
#include <iostream>

Player::Player(const std::string& name, int health, PlayerClass playerClass)
        : m_name(name), m_health(health), m_playerClass(playerClass), m_weapon(nullptr), m_team(nullptr) {}

void Player::setWeapon(Weapon* weapon) {
    m_weapon = weapon;
}

void Player::setTeam(Team* team) {
    m_team = team;
}

Weapon* Player::getWeapon() const {
    return m_weapon;
}

std::string Player::getPlayerClassName() const {
    switch (m_playerClass) {
        case ASSAULT:
            return "Assault";
        case SUPPORT:
            return "Support";
        case SNIPER:
            return "Sniper";
        case MEDIC:
            return "Medic";
        default:
            return "Unknown";
    }
}

void Player::printPlayerInfo() const {
    std::cout << "| Player q._.p |" << std::endl
              << "Name: " << m_name << std::endl
              << "Health: " << m_health << std::endl
              << "Class: " << getPlayerClassName() << std::endl;

    if (m_weapon != nullptr) {
        m_weapon->printInfo();
    }

    if (m_team != nullptr) {
        m_team->printTeamName();
    }

    std::cout << std::endl;
}