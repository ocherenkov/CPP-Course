#pragma once
#include <string>

//forwad declaration
class Munchkin;

class Runaway
{
public:
	virtual void apply(Munchkin* munchkin) = 0;
	virtual std::string getFullInfo() { return ""; }
};

class Runaway_LevelDowngrade : public Runaway
{
public:
	Runaway_LevelDowngrade(int level = 1) : m_levelToDowngrade(level) {}
	void apply(Munchkin* munchkin) override;
    virtual std::string getFullInfo() override {
        return "----- Downgrade your level by " + std::to_string(m_levelToDowngrade) + " -------\n";
    }

protected:
	int m_levelToDowngrade;
};

class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
	Runaway_LevelDowngradeIf(int level, int minimalMunchkinLevel) 
		: Runaway_LevelDowngrade(level), m_minimalMunchkinLevelToApply(minimalMunchkinLevel) {}

	void apply(Munchkin* munchkin) override;
    virtual std::string getFullInfo() override {
        return "----- Downgrade your level by " + std::to_string(m_levelToDowngrade) + " -------\n";
    }

private:
	int m_minimalMunchkinLevelToApply;
};

//Remove a card from hand(modifier) at random
class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
    Runaway_ModifierFromHandRemoval(int cardNumber) : m_cardNumber(cardNumber) {}

	void apply(Munchkin* munchkin) override;
    virtual std::string getFullInfo() override {
        std::string pluralSuffix = m_cardNumber > 1 ? "s" : "";
        return "----- You lost " + std::to_string(m_cardNumber) + " card" + pluralSuffix + " from hand! -------\n";
    }

private:
    int m_cardNumber;
};

//Remove equiped item from Outfit with the biggest base power
class Runaway_ItemEquipedRemoval : public Runaway
{
public:
    Runaway_ItemEquipedRemoval(int item) : m_item(item) {}

	void apply(Munchkin* munchkin) override;
    virtual std::string getFullInfo() override {
        return "----- You lost " + std::to_string(m_item) + " item! -------\n";
    }

private:
    int m_item;
};