#include "weapon.hpp"
#include "entity.hpp"
#include <iostream>

using namespace std;

Weapon::Weapon(string name)
{
    this->name = name;
}

void Weapon::GetInfo()
{
    cout << "Оружие " << name << " качества " << quality << " с уроном " << damage << endl;
}

unsigned int Weapon::GetDamage()
{
    return damage;
}

void Weapon::SetDamage(unsigned int damage)
{
    this->damage = damage;
}

void Weapon::Damage(Entity *from, Entity *target)
{
    float damage = (this->damage + from->GetBaseDamage()) * target->GetDamageMultiplyer();
    cout << "Оружие " << name << " наносит " << damage << " урона " << target->GetName() << endl;
    target->TakeDamage(damage);
}

void Weapon::Upgrade()
{
    cout << "Снаряжение " << name << " улучшено! " << quality << " -> " << quality + 1 << endl;
    if (quality < Legendary)
    {
        quality = static_cast<Quality>(quality + 1);
    }
}
