#pragma once

#include <string>
#include "entity.hpp"

class Evil : public Entity
{
public:
    Evil();
    Evil(std::string name);
    Evil(std::string name, float damageMultiplyer);
    Evil(std::string name, float damageMultiplyer, float health);
    Evil(std::string name, float damageMultiplyer, float health, unsigned int armor);
    ~Evil() override;
};
