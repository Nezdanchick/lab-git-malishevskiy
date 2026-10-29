#include <iostream>
#include <memory>

#include "player.hpp"
#include "warrior.hpp"
#include "mage.hpp"
#include "paladin.hpp"
#include "evil.hpp"
#include "playerType.hpp"
#include "menu.hpp"
#include "gameState.hpp"

using namespace std;

unique_ptr<Player> player;

int main()
{
    setlocale(LC_ALL, "Rus");

    player = make_unique<Player>();

    Menu characterCreationMenu;
    Menu mainMenu;
    Menu storyMenu;
    Menu characterInfoMenu;
    Menu exitMenu;

    // Main Menu
    mainMenu.AddText("Добро пожаловать в игру!");
    mainMenu.AddLine("История", []() {
        SetGameState(GameState::Story);
    });
    mainMenu.AddLine("Создать персонажа", []() {
        SetGameState(GameState::CharacterCreation);
    });
    mainMenu.AddLine("Информация о персонаже", []() {
        SetGameState(GameState::CharacterInfo);
    });
    mainMenu.AddLine("Выйти", []() {
        SetGameState(GameState::Exit);
    });

    // Character Creation
    characterCreationMenu.AddText("Выберите класс персонажа:");
    characterCreationMenu.AddLine("Воин", []() {
        player->Create<Warrior>();
        SetGameState(GameState::MainMenu);
    });
    characterCreationMenu.AddLine("Волшебник", []() {
        player->Create<Mage>();
        SetGameState(GameState::MainMenu);
    });
    characterCreationMenu.AddLine("Паладин", []() {
        player->Create<Paladin>();
        SetGameState(GameState::MainMenu);
    });
    characterCreationMenu.AddLine("Назад", []() {
        SetGameState(GameState::MainMenu);
    });
    
    // Story Menu
    storyMenu.AddText("Путник продолжил свой путь и наткнулся на нового врага...");
    storyMenu.AddLine("В главное меню", []() {
        SetGameState(GameState::MainMenu);
    });

    // Character Info Menu
    characterInfoMenu.AddLine("Информация о персонаже", []() {
        player->GetInfo();
    });
    characterInfoMenu.AddLine("Назад", []() {
        SetGameState(GameState::MainMenu);
    });

    // Exit Menu
    exitMenu.AddLine("Выйти из игры", []() {
        SetGameState(GameState::Exit);
    });

    cout << "Присядь путник у костра и расскажи, кто ты: " << endl;

    SetGameState(GameState::MainMenu);

    while (GetGameState() != GameState::Exit)
    {
        switch (GetGameState())
        {
            case GameState::MainMenu:
                mainMenu.Show();
                break;
            case GameState::CharacterCreation:
                characterCreationMenu.Show();
                break;
            case GameState::Story:
                storyMenu.Show();
                break;
            case GameState::CharacterInfo:
                characterInfoMenu.Show();
                break;
            default:
                break;
        }
    }

    return 0;
}
