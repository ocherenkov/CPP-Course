#include <string>

enum PlayerClass {
    ASSAULT,
    SUPPORT,
    SNIPER,
    MEDIC
};

class Weapon;
class Team;

class Player {
public:
    Player(const std::string& name, int health, PlayerClass playerClass);
    void setWeapon(Weapon* newWeapon);
    void setTeam(Team* team);
    Weapon* getWeapon() const;
    void printPlayerInfo() const;
    std::string getPlayerClassName() const;

private:
    std::string m_name;
    int m_health;
    PlayerClass m_playerClass;
    Weapon* m_weapon;
    Team* m_team;
};