#pragma once
#include "VECTOR.h"
#include "OBJECT.h"
class CAMERA :
    public OBJECT
{
public:
    CAMERA(class GAME* game);
    ~CAMERA();
    int setup();
    void update();
    VECTOR angle();
    struct DATA {
        VECTOR pos;
        VECTOR angle;
        float distance = 0;
        float rotSpeed = 0;
        float zoomSpeed = 0;
        int targetIdx = 0;
        int numTargets = 0;
        OBJ_ID objId[8];//‚±‚±‚ÍŽè”²‚«‚Å‚W‚ÉŒÅ’è
    };
private:
    struct DATA Data;
    OBJECT** Targets;
    VECTOR TargetPos;
    VECTOR UpVec;
};

