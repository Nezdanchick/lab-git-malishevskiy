#include "warrior.hpp"
#include <iostream>

using namespace std;

Warrior::Warrior()
{
    type = "Воин";
    name = "Воин";
    baseDamage = 10;
    health = 150;
    armor = 15;
}

void Warrior::LevelRecalulate()
{
    damageMultiplyer += 0.1 + strength * 0.01;
    health += (1 + level * 0.1) + strength * 0.8;
    armor += (1 + level * 0.1) + strength * 0.3;
}

void Warrior::GetInfo()
{
    Entity::GetInfo();
    cout << "Сила: " << strength << endl;
    weapon.GetInfo();
}

void Warrior::LevelUp()
{
    Entity::LevelUp();
    health += 10;
}

Warrior::~Warrior()
{
    cout << name << " пал смертью храбрых" << endl;
}
