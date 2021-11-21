#pragma once
//#define _DEBUG_
class GAME_POINTER
{
public:
    GAME_POINTER(class GAME* game);
    virtual ~GAME_POINTER();
    class GAME* game();
private:
    class GAME* Game = 0;
};
