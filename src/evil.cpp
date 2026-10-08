#include "evil.hpp"
#include <iostream>

using namespace std;

Evil::Evil()
{
    type = "Злодей";
    name = "Злодей";
    health = 10;
    baseDamage = 2;
    damageMultiplyer = 1.0;
    armor = 3;
}

Evil::Evil(string name) : Evil()
{
    this->name = name;
}

Evil::Evil(string name, float damageMultiplyer) : Evil(name)
{
    this->damageMultiplyer = damageMultiplyer;
}

Evil::Evil(string name, float damageMultiplyer, float health) : Evil(name, damageMultiplyer)
{
    this->health = health;
}

Evil::Evil(string name, float damageMultiplyer, float health, unsigned int armor) : Evil(name, damageMultiplyer, health)
{
    this->armor = armor;
}

Evil::~Evil()
{
    cout << "Тьма рассеялась: злодей " << name << " превратился в горстку праха и оставил после себя лут!" << endl;
}
