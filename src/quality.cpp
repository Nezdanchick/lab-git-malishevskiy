#include "quality.hpp"

#include <string>

std::string QualityToString(Quality quality)
{
    switch (quality)
    {
    case Quality::Common:
        return "Обычное";
    case Quality::Uncommon:
        return "Необычное";
    case Quality::Rare:
        return "Редкое";
    case Quality::Epic:
        return "Эпическое";
    case Quality::Legendary:
        return "Легендарное";
    default:
        return "Неизвестное качество";
    }
}

std::string QualityToString(int quality)
{
    return QualityToString(static_cast<Quality>(quality));
}
