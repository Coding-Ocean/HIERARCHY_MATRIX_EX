#pragma once
#include"MODEL.h"
class POLYGON : public MODEL {
public:
    POLYGON(int numCorners = 5) {
        //各バッファを確保-------------------------------------------
        NumVertices = numCorners * 2 + 2;
        NumTriangles = numCorners * 2;
        allocateMemory();

        //座標-------------------------------------------------------
        //s,c配列に、あらかじめsin,cosの値を計算しておく
        float* s = new float[numCorners];
        float* c = new float[numCorners];
        float angle = 3.1415926f * 2 / numCorners;
        for (int i = 0; i < numCorners; i++) {
            s[i] = sin(angle * i) * 0.5f;
            c[i] = cos(angle * i) * 0.5f;
        }
        //前面
        int j = 0;
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(-s[i], c[i], 0);//反時計回り
        }
        //裏面
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i], c[i], 0);//時計回り
        }
        //前面中心
        OPositions[j++].set(0, 0, 0);
        //裏面中心
        OPositions[j++].set(0, 0, 0);

        //法線ベクトル-----------------------------------------------
        //前面
        j = 0;
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, 1);
        }
        //裏面
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, -1);
        }
        //前面中心
        ONormals[j++].set(0, 0, 1);
        //裏面中心
        ONormals[j++].set(0, 0, -1);

        //インデックス-----------------------------------------------
        j = 0;
        int center = NumVertices - 2;
        int start = 0;
        for (int k = 0; k < 2; k++) {
            center += k;
            start = numCorners * k;
            for (int i = 0; i < numCorners; i++) {
                Indices[j++] = center;
                Indices[j++] = start + i;
                Indices[j++] = start + i + 1;
            }
            Indices[j - 1] -= numCorners;
        }

        //解放
        delete[]s;
        delete[]c;
    }
};