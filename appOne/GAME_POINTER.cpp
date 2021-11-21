#include "GAME_POINTER.h"
GAME_POINTER::GAME_POINTER(GAME* game)
{
    Game = game;
}

GAME_POINTER::~GAME_POINTER()
{
}

GAME* GAME_POINTER::game()
{
    return Game;
}
