#pragma once

#include "entity.hpp"
#include "spell.hpp"

class Mage : public Entity
{
private:
    Spell spell = Spell("Вспышка");
    short intellect{29};

public:
    Mage();
    void LevelRecalulate() override;
    void GetInfo() override;
    void LevelUp() override;
    ~Mage() override;
};
