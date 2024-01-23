#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const std::string& name, int damage, int range)
        : name(name), damage(damage), range(range) {}

std::string Weapon::getName() const {
    return name;
}

int Weapon::getDamage() const {
    return damage;
}

int Weapon::getRange() const {
    return range;
}

void Weapon::getInfo() const {
    std::cout << "| Weapon ︻デ══一 |" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Range: " << range << std::endl;
}