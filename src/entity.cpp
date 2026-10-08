#include "entity.hpp"
#include <iostream>

using namespace std;

Entity *Entity::SetName(string name)
{
    this->name = name;
    return this;
}

Entity *Entity::SetNameConsole()
{
    cout << "Введите имя: ";
    cin >> this->name;
    return this;
}

Entity *Entity::SetLevel(unsigned int level)
{
    this->level = level;
    LevelRecalulate();
    return this;
}

void Entity::GetInfo()
{
    cout << "Тип: " << type << endl;
    cout << "Имя: " << name << endl;
    cout << "Уровень: " << level << endl;
    cout << "Здоровье: " << health << endl;
    cout << "Броня: " << armor << endl;
    cout << "Множитель урона: x" << damageMultiplyer << endl;
}

void Entity::LevelUp()
{
    cout << "Уровень " << name << " увеличен! " << level << " -> " << level + 1 << endl;
    level++;
    LevelRecalulate();
}

void Entity::LevelRecalulate()
{
    damageMultiplyer += 0.1;
    health += (1 + level * 0.1);
    armor += (1 + level * 0.1);
}

bool Entity::IsAlive()
{
    return health > 0;
}

string Entity::GetName()
{
    return name;
}

float Entity::GetBaseDamage()
{
    return baseDamage;
}

float Entity::GetDamageMultiplyer()
{
    return damageMultiplyer;
}

float Entity::GetArmor()
{
    return armor;
}

float Entity::GetHealth()
{
    return health;
}

void Entity::TakeDamage(float damage)
{
    float damageTaken = damage - armor;
    if (damageTaken < 0)
    {
        damageTaken = 0;
    }
    cout << name << " получил " << damageTaken << " урона" << endl;
    health -= damageTaken;
}
