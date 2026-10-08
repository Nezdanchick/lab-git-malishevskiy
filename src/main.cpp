#include <iostream>
#include <memory>

#include "player.hpp"
#include "warrior.hpp"
#include "mage.hpp"
#include "paladin.hpp"
#include "evil.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    Player player;

    cout << "Присядь путник у костра и расскажи, кто ты: " << endl;
    cout << "\t1 - воин\n\t2 - волшебник\n\t3 - паладин" << endl;
    short choise = 0;
    cin >> choise;

    switch (choise)
    {
    case 1:
        player.Create(make_unique<Warrior>());
        break;
    case 2:
        player.Create(make_unique<Mage>());
        break;
    case 3:
        player.Create(make_unique<Paladin>());
        break;
    default:
        cout << "Таких героев еще не было в наших краях\n";
        return 0;
    }

    player.GetInfo();

    return 0;
}
