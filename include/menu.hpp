#pragma once

#include <string>
#include <vector>

class Menu
{
    std::vector<std::string> texts;
    std::vector<std::pair<std::string, void (*)()>> lines;
public:
    void Show();
    void AddText(std::string text);
    void AddLine(std::string line, void (*action)());
};
