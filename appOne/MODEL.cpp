#include "MODEL.h"
extern COLOR_MODE ColorMode;

//MODELを継承した全てのクラスで共有するインスタンス
MATRIX MODEL::view;
MATRIX MODEL::proj;
VECTOR MODEL::lightPos;

MODEL::MODEL() 
{
}

MODEL::~MODEL() 
{
    if (OPositions)delete[] OPositions;
    if (ONormals)delete[] ONormals;
    if (Positions)delete[] Positions;
    if (Indices)delete[] Indices;
    if (Colors)delete[] Colors;
}

void MODEL::allocateMemory() 
{
    if (NumVertices == 0) {
        print("頂点数を設定していない");
    }
    if (NumTriangles == 0) {
        print("三角ポリゴン数を設定していない");
    }
    //位置と法線ベクトル（頂点バッファ）
    OPositions = new VECTOR[NumVertices];
    ONormals = new VECTOR[NumVertices];
    //座標変換後の位置
    Positions = new VECTOR[NumVertices];
    //計算後の頂点の色（明るさ）
    Colors = new COLOR[NumVertices];
    //インデックスバッファ
    NumIndices = NumTriangles * 3;
    Indices = new int[NumIndices];
}

void MODEL::draw(const MATRIX& world, const COLOR& color, float ambient) 
{
    //worldから回転・拡大縮小要素を取り出す
    MATRIX mRS = world;
    mRS._14 = mRS._24 = mRS._34 = 0;
    //回転後の法線
    VECTOR normal;
    //全頂点の計算
    for (int i = 0; i < NumVertices; i++) {
        //ワールド座標
        Positions[i] = world * OPositions[i];
        //ビュー座標
        Positions[i] = view * Positions[i];
        //投影座標
        Positions[i] = proj * Positions[i];
        //色・明るさ
        if (Lighting) {
            normal = normalize(mRS * ONormals[i]);
            float bright = max(ambient, dot(normal, lightPos));
            //float bright = max(0.5f, dot(normal, lightPos));
            if (ColorMode == RGB) {
                Colors[i] = color * bright;
            }
            else {
                Colors[i] = color;
                Colors[i].b *= bright;
            }
        }
        else {
            //指定色そのまま
            Colors[i] = color;
        }
    }
    //描画
    for (int i = 0; i < NumTriangles; i++) {
        //描画する三角形のインデックスj,k,l
        int ref = i * 3;
        int j = Indices[ref + 0];
        int k = Indices[ref + 1];
        int l = Indices[ref + 2];
        if (Culling) {
            //j,k,lが作る三角形が"表"かどうか判定する
            VECTOR a = Positions[k] - Positions[j];
            VECTOR b = Positions[l] - Positions[j];
            //表だったら描画する
            if (a.crossZ(b) > 0) {
                triangle3D(Positions[j], Positions[k], Positions[l]
                    , Colors[j], Colors[k], Colors[l]);
            }
        }
        else {
            //裏面でも描画する
            triangle3D(Positions[j], Positions[k], Positions[l]
                , Colors[j], Colors[k], Colors[l]);
        }
    }
}

void MODEL::noCulling() 
{
    Culling = 0;
}

void MODEL::noLighting() 
{
    Lighting = 0;
}
