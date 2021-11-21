#pragma once
#include "OBJECT.h"
class LIGHT :
    public OBJECT
{
public:
    LIGHT(class GAME* game);
    int setup();
    struct DATA {
        VECTOR pos;
    };
private:
    DATA Data;
};

