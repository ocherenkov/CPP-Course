#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const std::string& name, int damage, int range)
        : name(name), damage(damage), range(range) {}

void Weapon::printInfo() const {
    std::cout << "| Weapon ︻デ══一 |" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Range: " << range << std::endl;
}