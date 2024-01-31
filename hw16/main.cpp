#include <iostream>
#include "Rectangle.h"
#include "Player.h"
#include "Weapon.h"
#include "Team.h"

void task1() {
    Rectangle rectangle1;
    Rectangle rectangle2(2.0f, 5.0f);

    std::cout << std::endl << "[TASK 1]" << std::endl;
    std::cout << "Rectangle 1: S = " << rectangle1.getArea() << ", P = " << rectangle1.getPerimeter() << std::endl;
    std::cout << "Rectangle 2: S = " << rectangle2.getArea() << ", P = " << rectangle2.getPerimeter() << std::endl;
    std::cout << std::endl;
}

void task2() {
    Weapon rifle("Arctic Warfare Police", 115, 250);
    Player player("Bob", 100, SNIPER);

    player.setWeapon(&rifle);
    std::cout << std::endl << "[TASK 2]" << std::endl;
    player.printPlayerInfo();
    std::cout << std::endl;
}

void task3() {
    Weapon rifle("Arctic Warfare Police", 115, 250);
    Player player("Bob", 100, SNIPER);
    Team team("CT");

    player.setWeapon(&rifle);
    team.addPlayer(&player);
    std::cout << std::endl << "[TASK 3]" << std::endl;
    player.printPlayerInfo(); // with team
    std::cout << std::endl;
    team.printTeamFullInfo();
    std::cout << std::endl;
    team.removePlayer(&player);
    player.printPlayerInfo(); // without team

    std::cout << std::endl;
}

int main() {
    // task1
    task1();

    // task2
    task2();

    // task3
    task3();
}