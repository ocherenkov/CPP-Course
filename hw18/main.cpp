#include <string>

#include "Weapon.h"
#include "PlayerClass.h"
#include "Player.h"

int main()
{
    //Game cycle
    Player player1("OnePunchMan", new SniperRifle);
    Player player2("John Cena", new Axe, new DefenderClass);

    Player player3("The Rock", new SniperRifle, new AttackerClass);
    Player player4("Undertacker", new SniperRifle, new BerserkClass);
    Player player5("The Show", new Pistol, new DefenderClass);
    Player player6("Daniel Bryan", new Pistol, new LuckyManClass);
    Player player7("Randy Orton", new AssaultRifle, new AttackerClass);
    Player player8("CM Punk", new BareHand, new LuckyManClass);
    Player player9("Edge", new Axe, new DefenderClass);


    player1.attack(player2, 500);
    player1.attack(player2, 2000);
    player1.attack(player1, 300);
    player2.attack(player1, 100);
    player1.attack(player2, 500);

    player3.attack(player4, 1000);
    player3.attack(player5, 1500);

    player4.attack(player5, 500);
    player4.attack(player6, 2500);

    player5.attack(player7, 50);
    player5.attack(player8, 200);

    player6.attack(player9, 100);
    player6.attack(player1, 30);

    player7.attack(player2, 300);
    player7.attack(player3, 600);

    player8.attack(player4, 1);
    player8.attack(player5, 2);

    player9.attack(player6, 10);
    player9.attack(player7, 100);

    return 0;
}