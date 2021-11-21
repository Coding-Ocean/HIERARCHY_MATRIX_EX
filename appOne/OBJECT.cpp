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
/*
//各オブジェクトが個別に呼び出すメンバ----------------------------------------
//回転制御。指定した方向にゆっくり向ける。向き終わったらフラグを立てる。
int OBJECT::rotate(
    VECTOR* angle, const VECTOR& dir, float rotSpeed, int endOfRotationFlag)
{
    //Ｘ軸回転させるangleを求める
    //次の式のように「真下を向いたベクトル」と「ｂベクトル」の内積は、-b.yになる
    //cosθ = downVec(0,-1,0) ・ b(x,y,z) = -b.y
    VECTOR b = normalize(dir);
    float angleBetweenX = -(acos(-b.y) - 1.57f) - angle->x;
    angle->x += angleBetweenX * rotSpeed;
    //Ｙ軸回転させるangleを求める
    VECTOR a(sin(angle->y), 0, cos(angle->y));
    float dotProduct = a.x * b.x + a.z * b.z;
    float crossProduct = a.x * b.z - a.z * b.x;
    float angleBetweenY = atan2(-crossProduct, dotProduct);
    angle->y += angleBetweenY * rotSpeed;
    //回転終了
    if (-0.017f < angleBetweenY && angleBetweenY < 0.017f) {
        EndOfStateFlags |= endOfRotationFlag;
        return 1;
    }
    return 0;
}

//弾が最終ターゲットに当たった時に呼び出してフラッグを立てる。
void OBJECT::completeState()
{
    EndOfStateFlags = CompletedFlags;
}

//全オブジェクトに影響するステート関連のスタティックメンバ-------------------
OBJ_STATE OBJECT::ObjState = OBJ_STATE::MOVE;
int OBJECT::EndOfStateFlags = 0;
int OBJECT::CompletedFlags = 0;
int OBJECT::RotationCompletedFlags = 0b111;
int OBJECT::FlyingCompletedFlags = 0b1;
int OBJECT::FormationId = 0;

//全オブジェクトのステートを管理する(メインループから呼び出されるメンバ)
void OBJECT::objStateManager()
{
    if (ObjState == OBJ_STATE::MOVE) {
        //キー入力でフォーメーション切り替え
        if (isTrigger(KEY_X)) {
            ++FormationId %= 3;
        }
        //キー入力で回転開始へ
        if (isTrigger(KEY_Z)) {
            ResetEndFlags(RotationCompletedFlags);
            ObjState = OBJ_STATE::ROTATE;
        }
    }
    else if (ObjState == OBJ_STATE::ROTATE) {
        //全オブジェクトの回転が終了したら、弾の飛行へ
        if (EndOfState()) {
            ResetEndFlags(FlyingCompletedFlags);
            ObjState = OBJ_STATE::FLY;
        }
    }
    else if (ObjState == OBJ_STATE::FLY) {
        //弾が最終ターゲットに到達したら、元の方向に回転開始へ
        if (EndOfState()) {
            ResetEndFlags(RotationCompletedFlags);
            ObjState = OBJ_STATE::ROTATE_BACK;
        }
    }
    else if (ObjState == OBJ_STATE::ROTATE_BACK) {
        //全オブジェクトが元の方向に回転し終わったら、通常の動きへ
        if (EndOfState()) {
            ObjState = OBJ_STATE::MOVE;
        }
    }
}

void OBJECT::ResetEndFlags(int completedFlags)
{
    EndOfStateFlags = 0;
    CompletedFlags = completedFlags;
}

int OBJECT::EndOfState()
{
    return EndOfStateFlags == CompletedFlags;
}

//Getter
OBJ_STATE OBJECT::objState()
{
    return ObjState;
}

int OBJECT::formationId() 
{
    return FormationId;
}
*/