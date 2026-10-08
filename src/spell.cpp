#include "spell.hpp"
#include <iostream>

using namespace std;

Spell::Spell(string name) : Weapon(name) {}

void Spell::GetInfo()
{
    cout << "Заклинание " << name << " качества " << quality << " с уроном " << damage << endl;
}
