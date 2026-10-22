#include <iostream>
#include <memory>

#include "player.hpp"
#include "warrior.hpp"
#include "mage.hpp"
#include "paladin.hpp"
#include "evil.hpp"
#include "playerType.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    Player player;

    cout << "Присядь путник у костра и расскажи, кто ты: " << endl;
    cout << "\t1 - воин\n\t2 - волшебник\n\t3 - паладин" << endl;
    PlayerType choise = PlayerType::None;
    cin >> (int&)choise;

    switch (choise)
    {
    case PlayerType::Warrior:
        player.Create(make_unique<Warrior>());
        break;
    case PlayerType::Mage:
        player.Create(make_unique<Mage>());
        break;
    case PlayerType::Paladin:
        player.Create(make_unique<Paladin>());
        break;
    default:
        cout << "Таких героев еще не было в наших краях\n";
        return 0;
    }

    player.GetInfo();

    switch (choise)
    {
    case PlayerType::Warrior:
        dynamic_cast<Warrior*>(player.GetCharacter())->GetWeapon()->Upgrade();
        break;
    case PlayerType::Mage:
        dynamic_cast<Mage*>(player.GetCharacter())->GetSpell()->Upgrade();
        break;
    case PlayerType::Paladin:
        dynamic_cast<Paladin*>(player.GetCharacter())->GetWeapon()->Upgrade();
        dynamic_cast<Paladin*>(player.GetCharacter())->GetSpell()->Upgrade();
        break;
    default:
        break;
    }

    return 0;
}
