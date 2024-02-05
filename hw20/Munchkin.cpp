#include "Munchkin.h"
#include "Item.h"
#include "Modifier.h"
#include <algorithm>

void Munchkin::updateLevelBy(int levels)
{
    if (m_level + levels <= 0)
    {
        m_level = 1;
    }
    else
    {
	    m_level += levels; 
    }

}

void Munchkin::addItem(Item* item)
{
    m_items.push_back(item);
}

void Munchkin::setItems(const std::vector<Item*>& items)
{
    m_items = items;
}

const std::vector<Item*>& Munchkin::getItems() const
{
    return m_items;
}

Modifier* Munchkin::popModifier(int idx)
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return nullptr;
    }

    Modifier* modifier = m_modifiers[idx];

    //Erase-remove idiom can be used as we don't really care about
    //internal order of the elements
    m_modifiers.erase(m_modifiers.begin() + idx);
    return modifier;

}

void Munchkin::removeModifierFromHand(int cardNumber)
{
    if (m_modifiers.size() >= cardNumber) {
        const int randNumber = std::rand() % m_modifiers.size();
        m_modifiers.erase(m_modifiers.begin() + randNumber);
    }
}

void Munchkin::removeItemEquipped()
{
    if (m_items.size() >= 1) {
        int maxBasePower = m_items[0]->getBasePower();

        for (int i = 1; i < m_items.size(); i++) {
            if (m_items[i]->getBasePower() > maxBasePower) {
                maxBasePower = m_items[i]->getBasePower();
            }
        }

        m_items.erase(m_items.begin() + maxBasePower);
    }
}
