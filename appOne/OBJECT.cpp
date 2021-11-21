#include "GAME.h"
#include "OBJECT.h"

OBJECT::OBJECT(GAME* game)
    :GAME_POINTER(game)
{
}

OBJECT::~OBJECT()
{
}

int OBJECT::setup()
{
    return 0;
}

void OBJECT::update()
{
}

void OBJECT::draw()
{
}

VECTOR OBJECT::pos()
{
    return VECTOR();
}

VECTOR OBJECT::angle()
{
    return VECTOR();
}
