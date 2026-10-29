#pragma once

#include <memory>
#include "entity.hpp"

class Player
{
private:
    std::unique_ptr<Entity> character;

public:
    Player() = default;

    template <typename T>
    void Create()
    {
        character = std::make_unique<T>();
        if (character)
        {
            character->SetNameConsole();
        }
    }

    template <typename T>
    T* GetCharacter()
    {
        return dynamic_cast<T*>(character.get());
    }

    void GetInfo();
    void LevelUp();
    void Damage(float dmg);
    bool IsAlive();
};