#include "ModifierDeck.h"

#include "Modifier.h"

ModifierDeck::ModifierDeck()
{
	m_modifiersDatabase =
	{
		{new SimpleModifier{3}},
		{new SimpleModifier{3}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{4}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new DoubleMunchkinLevel{}},
		{new DoubleMunchkinLevel{}},
		{new HalvesMonsterLevel{Tribe::Undead}},
		{new HalvesMonsterLevel{Tribe::God}}
	};
}

ModifierDeck::~ModifierDeck()
{
    for (Modifier* modifier : m_modifiersDatabase) {
        delete modifier;
    }
    m_modifiersDatabase.clear();
}

//#TODO: This code is similar to the one used in MonsterDeck
//Combine it under one hierarchy using inheritance
//Or move duplicated code into its own Helper Class and use composition of it
//In ModifierDeck and MonsterDeck
Modifier* ModifierDeck::generateModifier()
{
	//#TODO: this call should return new monster every time
	//either for as long as the same game is being played
	//or unless ALL cards were generated from database to the game - in this case 
	//make ALL cards available again

    if (m_availableModifiers.empty()) {
        m_availableModifiers = m_modifiersDatabase;
    }

    unsigned int idx = std::rand() % m_availableModifiers.size();
    Modifier* randomModifier = m_availableModifiers[idx];
    m_availableModifiers.erase(m_availableModifiers.begin() + idx);

    return randomModifier;
}
