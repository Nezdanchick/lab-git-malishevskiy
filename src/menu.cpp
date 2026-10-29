#include "menu.hpp"

#include <iostream>

void Menu::Show()
{
    for (const auto& text : texts)
    {
        std::cout << text << std::endl;
    }
    
    for (size_t i = 0; i < lines.size(); ++i)
    {
        std::cout << "\t" << (i + 1) << " - " << lines[i].first << std::endl;
    }

    int choice;
    std::cout << "Выберите: ";
    std::cin >> choice;
    if (choice >= 1 && choice <= static_cast<int>(lines.size()))
    {
        lines[choice - 1].second();
    }
}

void Menu::AddText(std::string text)
{
    texts.push_back(text + "\n");
}

void Menu::AddLine(std::string line, void (*action)())
{
    lines.push_back(std::make_pair(line, action));
}
