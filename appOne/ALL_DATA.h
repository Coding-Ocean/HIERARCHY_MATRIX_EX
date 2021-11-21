#pragma once
#include "CAMERA.h"
#include "PROJECTOR.h"
#include "LIGHT.h"
#include "FLOOR.h"

struct ALL_DATA {
    float w, h;
    int fullScreenFlag;
    CAMERA::DATA cameraData;
    PROJECTOR::DATA projectorData;
    LIGHT::DATA lightData;
    FLOOR::DATA floorData;
};

void setAllData(ALL_DATA& allData);