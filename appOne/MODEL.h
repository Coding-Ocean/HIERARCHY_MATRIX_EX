#pragma once
#include"libOne.h"
class MODEL {
protected:
    int NumVertices = 0;
    int NumTriangles = 0;
    int NumIndices = 0;
    //計算前のOriginalデータ
    VECTOR* OPositions = 0;
    VECTOR* ONormals = 0;
    //計算後のデータ
    VECTOR* Positions = 0;
    COLOR* Colors = 0;
    //頂点を選択するインデックス配列
    int* Indices = 0;
    //裏面消去フラッグ
    int Culling = 1;
    //ライティング処理フラッグ
    int Lighting = 1;
public:
    //すべてのMODELのインスタンスで共有するメンバクラス
    static MATRIX view;
    static MATRIX proj;
    static VECTOR lightPos;
    //メンバ関数
    MODEL();
    virtual ~MODEL();
    void allocateMemory();
    void draw(
        const MATRIX& world, 
        const COLOR& color=COLOR(255,255,255), 
        float ambient = 0
    );
    void noCulling();
    void noLighting();
};
