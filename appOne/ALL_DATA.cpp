#include "ALL_DATA.h"
void setAllData(ALL_DATA& ad)
{
    //window
    {
        ad.w = 1600;
        ad.h = 900;
        ad.fullScreenFlag = 0;
    }
    //camera
    {
        ad.cameraData.angle.set(0.32f, 0, 0);
        ad.cameraData.distance = 17;
        ad.cameraData.rotSpeed = 0.01f;
        ad.cameraData.zoomSpeed = 0.01f;
        ad.cameraData.targetIdx = 0;
        ad.cameraData.numTargets = 1;
        ad.cameraData.objId[0] = OBJ_ID::FLOOR;
    }
    //projector
    {
        ad.projectorData.fov = 0.785f;
        ad.projectorData.aspect = 1.7777777f;
        ad.projectorData.near_ = 0.1f;
        ad.projectorData.far_ = 100.0f;
    }
    //light
    {
        ad.lightData.pos.set(0, 1, 0);
    }
    //floor
    {
        ad.floorData.pos.set(0, 1, 0);//床の位置ではない。カメラルックアット座標。
        ad.floorData.range = 3;
        ad.floorData.scale = 3;
        ad.floorData.color[0].set(0, 0, 0);
        ad.floorData.color[1].set(80, 128, 80);
    }
}
