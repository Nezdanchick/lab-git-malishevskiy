#include "paladin.hpp"
#include <iostream>

using namespace std;

Paladin::Paladin()
{
    type = "Паладин";
    name = "Паладин";
    baseDamage = 8;
    health = 180;
    armor = 18;
}

void Paladin::LevelRecalulate()
{
    damageMultiplyer += 0.1 + (strength * 0.01) + (intellect * 0.01);
    health += (1 + level * 0.1) + strength * 0.6;
    armor += (1 + level * 0.1) + strength * 0.4 + intellect * 0.05;
}

void Paladin::GetInfo()
{
    Entity::GetInfo();
    cout << "Сила: " << strength << endl;
    cout << "Интеллект: " << intellect << endl;
    weapon.GetInfo();
    spell.GetInfo();
}

void Paladin::LevelUp()
{
    Entity::LevelUp();
    health += 8;
    spell.Upgrade();
}

Paladin::~Paladin()
{
    cout << name << " завершил свой священный поход и вознесся к Свету" << endl;
}
