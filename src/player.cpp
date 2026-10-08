#include "player.hpp"

using namespace std;

void Player::Create(unique_ptr<Entity> ch)
{
    character = move(ch);
    if (character)
    {
        character->SetNameConsole();
    }
}

Entity *Player::GetCharacter()
{
    return character.get();
}

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
