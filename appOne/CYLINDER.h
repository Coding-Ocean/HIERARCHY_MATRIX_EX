#pragma once
#include"MODEL.h"
class CYLINDER : public MODEL {
public:

    CYLINDER(
        int numCorners = 36,
        float frontZ = 0.5f,
        float backZ = -0.5f,
        float frontRadius = 0.5f,
        float backRadius = 0.5f) {

        //各バッファを確保-------------------------------------------
        NumVertices = numCorners * 2;//側面
        NumVertices += numCorners * 2 + 2;//前後
        NumTriangles = numCorners * 2;//側面
        NumTriangles += numCorners * 2;//前後
        allocateMemory();

        //座標-------------------------------------------------------
        //s,c配列に、あらかじめsin,cosの値を計算しておく
        float* s = new float[numCorners];
        float* c = new float[numCorners];
        float angle = 3.1415926f * 2 / numCorners;
        for (int i = 0; i < numCorners; i++) {
            s[i] = sin(angle * i);
            c[i] = cos(angle * i);
        }
        //側面「後ろ→前→後ろ→前・・・」と座標を並べていく
        int j = 0;
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i] * backRadius, c[i] * backRadius, backZ);
            OPositions[j++].set(s[i] * frontRadius, c[i] *frontRadius, frontZ);
        }
        //前
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(-s[i] * frontRadius, c[i] * frontRadius, frontZ);
        }
        //後ろ
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i] *backRadius, c[i] * backRadius, backZ);
        }
        //前後中心
        OPositions[j++].set(0, 0, frontZ);
        OPositions[j++].set(0, 0, backZ);

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
        //前
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, 1);
        }
        //後ろ
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, -1);
        }
        //前中心
        ONormals[j++].set(0, 0, 1);
        //後ろ中心
        ONormals[j++].set(0, 0, -1);

        //インデックス-----------------------------------------------
        //４角形単位で頂点番号を選択していく
        int max = numCorners * 2;
        j = 0;
        for (int i = 0; i < numCorners; i++) {
            int k = i * 2;
            Indices[j++] = k + 0;
            Indices[j++] = k + 1;
            Indices[j++] = (k + 2) % max;

            Indices[j++] = Indices[j - 1];
            Indices[j++] = Indices[j - 3];
            Indices[j++] = Indices[j - 2] + 1;
        }
        //前後
        int center = NumVertices - 2;
        int start;
        for (int k = 0; k < 2; k++) {
            center += k;
            start = numCorners * 2 + numCorners * k;
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