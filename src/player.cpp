#include "player.hpp"

using namespace std;

void Player::GetInfo()
{
    if (character)
    {
        character->GetInfo();
    }
}

void Player::LevelUp()
{
    if (character)
    {
        character->LevelUp();
    }
}

void Player::Damage(float dmg)
{
    if (character)
    {
        character->TakeDamage(dmg);
    }
}

bool Player::IsAlive()
{
    return character ? character->IsAlive() : false;
}