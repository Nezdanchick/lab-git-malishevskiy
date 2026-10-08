#pragma once

#include <memory>
#include "entity.hpp"

class Player
{
private:
    std::unique_ptr<Entity> character;

public:
    Player() = default;

    void Create(std::unique_ptr<Entity> ch);
    Entity *GetCharacter();
    void GetInfo();
    void LevelUp();
    void Damage(float dmg);
    bool IsAlive();
};
