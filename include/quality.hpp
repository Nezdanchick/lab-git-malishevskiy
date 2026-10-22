#pragma once

#include <string>

enum class Quality
{
    Common,
    Uncommon,
    Rare,
    Epic,
    Legendary
};


std::string QualityToString(Quality quality);
std::string QualityToString(int quality);
