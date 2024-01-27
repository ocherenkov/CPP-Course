#pragma once
class PlayerClass {
public:
    virtual float getDamageMultiplier() const = 0;
    virtual float getArmorMultiplier() const = 0;
    virtual float getMissChance() const = 0;

    virtual ~PlayerClass() {}
};

class DefaultClass : public PlayerClass {
public:
    virtual float getDamageMultiplier() const override { return 1.0f; }
    virtual float getArmorMultiplier() const override { return 1.0f; }
    virtual float getMissChance() const override { return 0.0f; }
};

class DefenderClass : public DefaultClass
{
public:
    virtual float getArmorMultiplier() const override { return 1.1f; }
    virtual float getMissChance() const override { return 0.1f; }
};

class AttackerClass : virtual public DefaultClass
{
public:
    virtual float getDamageMultiplier() const override { return 1.1f; }
};

class LuckyManClass : virtual public DefaultClass
{
public:
    virtual float getMissChance() const override { return 0.66f; }
};

class BerserkClass : public AttackerClass, LuckyManClass
{
public:
    virtual float getArmorMultiplier() const override { return 0.1f; }
};