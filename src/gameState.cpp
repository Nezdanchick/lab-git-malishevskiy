#include "gameState.hpp"

static GameState currentState = GameState::MainMenu;

GameState GetGameState()
{
    return currentState;
}
void SetGameState(GameState newState)
{
    currentState = newState;
}
