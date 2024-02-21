#include <fstream>
#include <string>
#include <vector>
#include "ItemDeck.h"
#include "Item.h"


ItemDeck::ItemDeck()
{
	//TODO: Move item's database to file in format:
	// type;name; additional if needed params for the type
	//For example:
	//UndeadWeapon;"Holy Grenade";4		//should call UndeadWeapon("Holy Grenade", 4);

    const std::string filename = "items.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        m_itemsDataBase =
        {
            new Weapon{"The Sword of DOOM", 5},
            new UndeadWeapon{"Stinky knife", 2},
            new UndeadWeapon{"Holy grenade", 4},
            new HolySword{"Platinum sword", 3},
            new HolySword{"Diamond sword", 4},
            new HugeRock{"Huge Rock", 5},
            new HugeRock{"Mountain", 6},
        };
    }
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> info;
        size_t pos = 0;
        while ((pos = line.find(';')) != std::string::npos) {
            info.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        info.push_back(line);

        if (info.size() >= 3) {
            const std::string type = info[0];
            const std::string name = info[1];
            const int power = std::stoi(info[2]);

            if (type == "Weapon") {
                m_itemsDataBase.push_back(new Weapon(name, power));
            } else if (type == "UndeadWeapon") {
                m_itemsDataBase.push_back(new UndeadWeapon(name, power));
            } else if (type == "HolySword") {
                m_itemsDataBase.push_back(new HolySword(name, power));
            } else if (type == "HugeRock") {
                m_itemsDataBase.push_back(new HugeRock(name, power));
            }
        }
    }

    file.close();
}

ItemDeck::~ItemDeck()
{
    for (Item* item : m_itemsDataBase) {
        delete item;
    }
    m_itemsDataBase.clear();
}

std::vector<Item*> ItemDeck::generateItems()
{
    int randItem = 0;
    const int maxItems = 2;
    for (int i = 0; i < maxItems; i++) {
        randItem = std::rand() % m_itemsDataBase.size();
        m_heldItems.push_back(m_itemsDataBase[randItem]);
        m_itemsDataBase.erase(m_itemsDataBase.begin() + randItem);
    }
	return m_heldItems;
}
