#pragma once
#include <iostream>

class Weapon
{
public:
    virtual ~Weapon() {};
    virtual std::string getName() const = 0;
    virtual int getDamageRate(int distance) const = 0;
    virtual int getDamage(int distance) const = 0;

protected:
    virtual int getEffectiveRange(int distance) const = 0;
    virtual int getDamageLevel() const { return 1; };
};

class RangedWeapon : public Weapon
{
public:
    std::string getName() const override { return "ranged weapon"; };
    virtual int getDamage(int distance) const override { return getDamageRate(distance) * getEffectiveRange(distance) * getDamageLevel(); };
    int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }

protected:
    virtual float getPrecision(int distance) const { return 1.0f; };
    virtual int getDamageLevel() const override { return 2; };
    virtual int getEffectiveRange(int distance) const override { return distance >= 0 && distance <= 1000; };
};

class SniperRifle : public RangedWeapon
{
public:
    std::string getName() const override { return "AWP"; };
    virtual int getDamage(int distance) const override { return getDamageRate(distance) * getEffectiveRange(distance) * getDamageLevel(); };
    int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }

protected:
    virtual float getPrecision(int distance) const override;
    virtual int getDamageLevel() const override { return 3; };
    virtual int getEffectiveRange(int distance) const override { return distance >= 0 && distance <= 2500; };
};

class Pistol : public RangedWeapon
{
public:
    std::string getName() const override { return "Eagle"; };
    virtual int getDamage(int distance) const override { return getDamageRate(distance) * getEffectiveRange(distance) * getDamageLevel(); };
    int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }

protected:
    virtual float getPrecision(int distance) const override { return 2.0f; };
    virtual int getDamageLevel() const override { return 1; };
    virtual int getEffectiveRange(int distance) const override { return distance >= 0 && distance <= 100; };
};

class AssaultRifle : public RangedWeapon
{
public:
    std::string getName() const override { return "M4A1"; };
    virtual int getDamage(int distance) const override { return getDamageRate(distance) * getEffectiveRange(distance) * getDamageLevel(); };
    int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }

protected:
    virtual float getPrecision(int distance) const override { return 4.0f; };
    virtual int getDamageLevel() const override { return 1; };
    virtual int getEffectiveRange(int distance) const override { return distance >= 0 && distance <= 1000; };
};

class MeleeWeapon : public Weapon
{
public:
    std::string getName() const override { return "malee weapon"; };
    virtual int getDamage(int distance) const override { return getDamageRate(distance) * getEffectiveRange(distance) * getDamageLevel(); };
    virtual int getDamageRate(int distance) const override { return 5; }

protected:
    virtual int getDamageLevel() const override { return 1; };
    virtual int getEffectiveRange(int distance) const override { return distance >= 0 && distance <= 100; };
};

class BareHand : public MeleeWeapon
{
public:
    std::string getName() const override { return "Bare hand"; };
    virtual int getDamage(int distance) const override { return getDamageRate(distance) * getEffectiveRange(distance) * getDamageLevel(); };
    virtual int getDamageRate(int distance) const override { return 2; }

protected:
    virtual int getDamageLevel() const override { return 1; };
    virtual int getEffectiveRange(int distance) const override { return distance >= 0 && distance <= 1; };
};

class Axe : public MeleeWeapon
{
public:
    std::string getName() const override { return "Axe"; };
    virtual int getDamage(int distance) const override { return getDamageRate(distance) * getEffectiveRange(distance) * getDamageLevel(); };
    virtual int getDamageRate(int distance) const override { return 8; }

protected:
    virtual int getDamageLevel() const override { return 2; };
    virtual int getEffectiveRange(int distance) const override { return distance >= 0 && distance <= 50; };
};