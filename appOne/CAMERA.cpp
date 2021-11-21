#include"input.h"
#include"mathUtil.h"
#include"GAME.h"
#include"MODEL.h"
#include "CAMERA.h"
CAMERA::CAMERA(class GAME* game)
    : OBJECT(game)
{
}

CAMERA::~CAMERA()
{
    SAFE_DELETE_ARRAY(Targets);
}

int CAMERA::setup()
{
    Data = game()->allData()->cameraData;

    Targets = new OBJECT * [Data.numTargets];
    for (int i = 0; i < Data.numTargets; i++) {
        Targets[i] = game()->object(Data.objId[i]);
    }

    return 0;
}

void CAMERA::update(){
    //経度（東西）
    if (isPress(KEY_J)) { Data.angle.y -= Data.rotSpeed; }
    if (isPress(KEY_L)) { Data.angle.y += Data.rotSpeed; }
    //緯度（南北）
    if (isPress(KEY_I)) { Data.angle.x += Data.rotSpeed; }
    if (isPress(KEY_K)) { Data.angle.x -= Data.rotSpeed; }
    //ズーム
    if (isPress(KEY_U)) { Data.distance -= Data.zoomSpeed; }
    if (isPress(KEY_O)) { Data.distance += Data.zoomSpeed; }
    if (Data.distance < 1.0f) { Data.distance = 1.0f; }
    //ターゲット変更
    if (isTrigger(KEY_C)) {
        ++Data.targetIdx %= Data.numTargets;
        if (Data.targetIdx == 0) {
            Data.distance = 17;
        }
        else {
            Data.distance = 6;
        }
    }
    TargetPos = Targets[Data.targetIdx]->pos();
    //カメラ位置（３D極座標）
    Data.pos.x = sin(Data.angle.y) * cos(Data.angle.x) * Data.distance;
    Data.pos.y = sin(Data.angle.x) * Data.distance;
    Data.pos.z = cos(Data.angle.y) * cos(Data.angle.x) * Data.distance;
    Data.pos += TargetPos;
    //上方ベクトル
    UpVec.y = cos(Data.angle.x);
    MODEL::view.camera(Data.pos, TargetPos, UpVec);
#ifdef _DEBUG_
    print((let)"Data.angle.y=" + Data.angle.y);
    print((let)"Data.angle.x=" + Data.angle.x);
    print((let)"Data.distance=" + Data.distance);
#endif
}

VECTOR CAMERA::angle() {
    return Data.angle;
}
