#include "mage.hpp"
#include <iostream>

using namespace std;

Mage::Mage()
{
    type = "Маг";
    name = "Маг";
    baseDamage = 0;
    health = 150;
    armor = 10;
}

void Mage::LevelRecalulate()
{
    damageMultiplyer += 0.1 + intellect * 0.02;
    health += (1 + level * 0.1) + intellect * 0.2;
    armor += (1 + level * 0.1) + intellect * 0.1;
}

void Mage::GetInfo()
{
    Entity::GetInfo();
    cout << "Интеллект: " << intellect << endl;
    spell.GetInfo();
}

void Mage::LevelUp()
{
    Entity::LevelUp();
    spell.Upgrade();
}

Mage::~Mage()
{
    cout << name << " испускает дух" << endl;
}
