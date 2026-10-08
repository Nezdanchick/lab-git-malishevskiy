#pragma once

#include <string>

class Entity
{
protected:
    std::string type{"Entity"};
    std::string name{"Entity"};
    float health{100};
    float baseDamage{1};
    float damageMultiplyer{1};
    unsigned int level{1};
    unsigned int armor{2};

    Entity() = default;

public:
    Entity *SetName(std::string name);
    Entity *SetNameConsole();
    Entity *SetLevel(unsigned int level);

    bool IsAlive();
    std::string GetName();
    float GetBaseDamage();
    float GetDamageMultiplyer();
    float GetArmor();
    float GetHealth();
    virtual void TakeDamage(float damage);

    virtual void GetInfo();
    virtual void LevelUp();
    virtual void LevelRecalulate();
    virtual ~Entity() = default;
};
