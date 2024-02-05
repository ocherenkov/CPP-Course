#include "MonsterDeck.h"

#include "Monster.h"
#include "Runaway.h"

MonsterDeck::MonsterDeck()
{
	m_monstersDatabase =
	{
		//#TODO: Think of new monsters, feel free to use official Munchkin games as a reference
		new Monster{"Crazy Joe", 4},
		new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5}},
		new Monster{"Vampire", 3, Tribe::Undead, new Runaway_LevelDowngrade{1}}
	};
}

MonsterDeck::~MonsterDeck()
{
    for (Monster* monster : m_monstersDatabase) {
        delete monster;
    }
    m_monstersDatabase.clear();
}

Monster* MonsterDeck::generateMonster()
{
	//#TODO: this call should return new monster every time
	//either for as long as the same game is being played
	//or unless ALL cards were generated from database to the game - in this case 
	//make ALL cards available again
    if (m_availableMonsters.empty()) {
        m_availableMonsters = m_monstersDatabase;
    }

    const int choice = std::rand() % m_availableMonsters.size();

    Monster* randomMonster = m_availableMonsters[choice];
    m_availableMonsters.erase(m_availableMonsters.begin() + choice);

    return randomMonster;
}