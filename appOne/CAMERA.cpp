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
    //�o�x�i�����j
    if (isPress(KEY_J)) { Data.angle.y -= Data.rotSpeed; }
    if (isPress(KEY_L)) { Data.angle.y += Data.rotSpeed; }
    //�ܓx�i��k�j
    if (isPress(KEY_I)) { Data.angle.x += Data.rotSpeed; }
    if (isPress(KEY_K)) { Data.angle.x -= Data.rotSpeed; }
    //�Y�[��
    if (isPress(KEY_U)) { Data.distance -= Data.zoomSpeed; }
    if (isPress(KEY_O)) { Data.distance += Data.zoomSpeed; }
    if (Data.distance < 1.0f) { Data.distance = 1.0f; }
    //�^�[�Q�b�g�ύX
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
    //�J�����ʒu�i�RD�ɍ��W�j
    Data.pos.x = sin(Data.angle.y) * cos(Data.angle.x) * Data.distance;
    Data.pos.y = sin(Data.angle.x) * Data.distance;
    Data.pos.z = cos(Data.angle.y) * cos(Data.angle.x) * Data.distance;
    Data.pos += TargetPos;
    //����x�N�g��
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
