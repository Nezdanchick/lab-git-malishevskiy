#pragma once

#include "entity.hpp"
#include "weapon.hpp"

class Warrior : public Entity
{
private:
    Weapon weapon = Weapon("Кулаки");
    short strength{21};

public:
    Warrior();
    void LevelRecalulate() override;
    void GetInfo() override;
    void LevelUp() override;
    ~Warrior() override;
};
