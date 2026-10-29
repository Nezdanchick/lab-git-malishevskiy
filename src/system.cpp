#include "system.hpp"

#include <iostream>

void ClearConsole()
{
    // Source - https://stackoverflow.com/a/32008479
    // Posted by catzilla, modified by community. See post 'Timeline' for change history
    // Retrieved 2026-10-29, License - CC BY-SA 3.0

    std::cout << "\033[2J\033[1;1H";
}
