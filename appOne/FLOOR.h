#pragma once
#include "OBJECT.h"
#include "PLANE.h"
#include"MATRIX.h"
class FLOOR :
    public OBJECT
{
//Functions
public:
    FLOOR(class GAME* game);
    int setup();
    void draw();
    VECTOR pos();
//Data
    struct DATA {
        VECTOR pos;
        int range;
        float scale;
        COLOR color[2];
    };
private:
    DATA Data;
    PLANE Plane;
    MATRIX World;
};

