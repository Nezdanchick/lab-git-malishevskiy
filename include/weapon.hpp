#pragma once

#include <string>
#include "quality.hpp"

class Entity;

class Weapon
{
protected:
    std::string name;
    unsigned int damage{1};
    Quality quality{Common};

public:
    Weapon(std::string name = "weapon");
    virtual void GetInfo();
    unsigned int GetDamage();
    void SetDamage(unsigned int damage);
    void Damage(Entity *from, Entity *target);
    void Upgrade();
    virtual ~Weapon() = default;
};
