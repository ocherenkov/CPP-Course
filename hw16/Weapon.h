#include <string>

class Weapon {
public:
    Weapon(const std::string& name, int damage, int range);
    std::string getName() const;
    int getDamage() const;
    int getRange() const;
    void getInfo() const;

private:
    std::string name;
    int damage;
    int range;
};