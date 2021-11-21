#pragma once
#include "OBJECT.h"
class PROJECTOR:
    public OBJECT
{
public:
    PROJECTOR(class GAME* game);
    int setup();
    struct DATA {
        float fov = 0;
        float aspect = 0;
        float near_ = 0;
        float far_ = 0;
    };
private:
    DATA Data;
};

