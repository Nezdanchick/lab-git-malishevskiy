#pragma once

enum class GameState
{
    CharacterCreation,
    MainMenu,
    Story,
    CharacterInfo,
    Exit
};

GameState GetGameState();
void SetGameState(GameState state);
