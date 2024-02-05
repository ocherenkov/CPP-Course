#pragma once
#include <vector>

class Item;

class ItemDeck
{
public:
	ItemDeck();
	~ItemDeck();

	std::vector<Item*> generateItems();

private:
	std::vector<Item*> m_itemsDataBase;
    std::vector<Item*> m_heldItems;
};