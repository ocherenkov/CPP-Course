#include <string>

class Weapon {
public:
    Weapon(const std::string& name, int damage, int range);
    std::string getName() const { return name; };
    int getDamage() const { return damage; };
    int getRange() const { return range; };
    void printInfo() const;

private:
    std::string name;
    int damage;
    int range;
};