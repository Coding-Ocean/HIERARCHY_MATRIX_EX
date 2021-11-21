#pragma once
#include"VECTOR.h"
#include"GAME_POINTER.h"
#include "OBJ_ID.h"
#include "OBJ_STATE.h"
class OBJECT
    :public GAME_POINTER
{
public:
    OBJECT(class GAME* game);
    virtual ~OBJECT();
    virtual int setup();
    virtual void update();
    virtual void draw();
    virtual VECTOR pos();
    virtual VECTOR angle();
/*
//各オブジェクトが個別に呼び出すメンバ----------------------------------------
    //回転制御。指定した方向にゆっくり向ける。向き終わったらフラッグを立てる
    int rotate(VECTOR* angle, const VECTOR& dir, float speed, int endOfRotationFlag=0);
    //弾が最終ターゲットに当たった時に呼び出してフラッグを立てる
    void completeState();

//全オブジェクトに影響するステート関連のスタティックメンバ-------------------
    //全オブジェクトのステートを管理する(メインループから呼び出されるメンバ)
    static void objStateManager();
private:
    //ステート開始時に「ステート終了と判断するためのフラッグ」を渡してリセット
    static void ResetEndFlags(int completedFlags);
    //ステートが終わったかどうか判断できる
    static int EndOfState();
public:
    //Getter
    static OBJ_STATE objState();
    static int formationId();
private:
    //オブジェクトの状態
    static OBJ_STATE ObjState;
    //現在のフォーメーションId
    static int FormationId;
    //EndOfStateFlagsがCompletedFlagsと等しくなったらそのステートは終了
    static int EndOfStateFlags;
    static int CompletedFlags;
    //ステート開始時、resetEndFlags()のパラメタに設定するフラグ
    //(ここが難解すぎるが、今のところこれしか思いつかない)
    static int RotationCompletedFlags;
    static int FlyingCompletedFlags;
*/
};
