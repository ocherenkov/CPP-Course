#pragma once
#include "Tribe.h"
#include <string>

class Item
{
public:
	virtual int getPower(Tribe monsterTribeModifier) const { return getBasePower(); }
	virtual int getBasePower() const { return 0; }

	void setName(const std::string& name) { m_name = name; }
	const std::string getName() const { return m_name; }
	virtual std::string getFullInfo() const = 0;

protected:
	std::string m_name;
	//other fields like description, image, category

private:
};

class Weapon : public Item
{
public:
	Weapon(const std::string& name, int power)
	{
		setName(name);
		m_power = power;
	}

	int getBasePower() const override
	{
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: None\n";
	}

protected:
	int m_power = 0;
};

class UndeadWeapon : public Weapon
{
public:
	UndeadWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)	
		{
		case Tribe::Undead:
			return getBasePower() * 2;
		case Tribe::Human:
		case Tribe::Zombie:
		default:
			return getBasePower();
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs UNDEADS!\n";
	}
};

class HolySword : public Weapon
{
public:
    HolySword(const std::string& name, int power) : Weapon(name, power) {}

    virtual int getPower(Tribe monsterTribeModifier) const override
    {
        switch (monsterTribeModifier)
        {
            case Tribe::Zombie:
                return getBasePower() * 5;
            case Tribe::Human:
            case Tribe::Undead:
            default:
                return getBasePower();
        }
    }

    virtual std::string getFullInfo() const override
    {
        return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: quick kill vs ZOMBIES!\n";
    }
};

class HugeRock: public Weapon
{
public:
    HugeRock(const std::string& name, int power) : Weapon(name, power) {}

    virtual int getPower(Tribe monsterTribeModifier) const override
    {
        switch (monsterTribeModifier)
        {
            case Tribe::Human:
                return getBasePower() * 4;
            case Tribe::Undead:
            case Tribe::Zombie:
            default:
                return getBasePower();
        }
    }

    virtual std::string getFullInfo() const override
    {
        return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x4 vs HUMANS!\n";
    }
};