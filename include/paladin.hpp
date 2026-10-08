#pragma once

#include "entity.hpp"
#include "weapon.hpp"
#include "spell.hpp"

class Paladin : public Entity
{
private:
    Weapon weapon = Weapon("Освященный меч");
    Spell spell = Spell("Священный огонь");
    short strength{18};
    short intellect{18};

public:
    Paladin();
    void LevelRecalulate() override;
    void GetInfo() override;
    void LevelUp() override;
    ~Paladin() override;
};
