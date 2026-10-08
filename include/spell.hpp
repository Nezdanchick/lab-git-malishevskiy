#pragma once

#include <string>
#include "weapon.hpp"

class Spell : public Weapon
{
public:
    Spell(std::string name = "spell");
    void GetInfo() override;
};
