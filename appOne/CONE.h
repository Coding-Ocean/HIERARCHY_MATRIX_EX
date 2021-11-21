#pragma once
#include"MODEL.h"
class CONE : public MODEL {
public:
    CONE(int numCorners = 36, float radius = 0.5f, float topZ = 0.866f) {
        //各バッファを確保-------------------------------------------
        NumVertices = numCorners * 2;//側面
        NumVertices += numCorners + 1;//背面用追加
        NumTriangles = numCorners;//側面
        NumTriangles += numCorners;//背面用追加
        allocateMemory();

        //座標-------------------------------------------------------
        //s,c配列に、あらかじめsin,cosの値を計算しておく
        float* s = new float[numCorners];
        float* c = new float[numCorners];
        float angle = 3.1415926f * 2 / numCorners;
        for (int i = 0; i < numCorners; i++) {
            s[i] = sin(angle * i) * radius;
            c[i] = cos(angle * i) * radius;
        }
        //側面「後ろ→前中心→後ろ→前中心・・・」と座標を並べていく
        int j = 0;
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i], c[i], 0);
            OPositions[j++].set(0, 0, topZ);
        }
        //裏面
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i], c[i], 0);//時計回り
        }
        //裏面中心
        OPositions[j++].set(0, 0, 0);

        //法線ベクトル-----------------------------------------------
        j = 0;
        for (int i = 0; i < numCorners; i++) {
            int k = i * 2;
            VECTOR a = OPositions[k + 1] - OPositions[k];
            VECTOR b(c[i], -s[i], 0);
            VECTOR n = normalize(cross(a, b));
            ONormals[j++] = n;
            ONormals[j++] = n;
        }
        //裏面
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, -1);
        }
        //裏面中心
        ONormals[j++].set(0, 0, -1);

        //インデックス-----------------------------------------------
        //側面
        j = 0;
        for (int i = 0; i < numCorners; i++) {
            int k = i * 2;
            Indices[j++] = k + 0;
            Indices[j++] = k + 1;
            Indices[j++] = k + 2;
        }
        Indices[j - 1] = 0;
        //裏面
        for (int i = 0; i < numCorners; i++) {
            Indices[j++] = NumVertices - 1;//裏面中心
            Indices[j++] = numCorners * 2 + i;
            Indices[j++] = numCorners * 2 + i + 1;
        }
        Indices[j - 1] -= numCorners;

        //解放
        delete[]s;
        delete[]c;
    }
};