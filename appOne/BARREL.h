#pragma once
#pragma once
#include"MODEL.h"
class BARREL : public MODEL {
public:
    BARREL() {
        //noCulling();

        //各バッファを確保-------------------------------------------
        int numCorners = 36;
        NumVertices = numCorners * 8 + 2;
        NumTriangles = numCorners * 8;
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
        float r = 0.5f;//外側半径
        float r2 = 0.3f;//内側半径
        float z = 1;
        int j = 0;
        //外側の筒
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i] * r, c[i] * r, -0.5f);
            OPositions[j++].set(s[i] * r, c[i] * r, z);
        }
        //内側の筒
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(-s[i] * r2, c[i] * r2, -0.5f);
            OPositions[j++].set(-s[i] * r2, c[i] * r2, z);
        }
        //前面のドーナツ
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i] * r, c[i] * r, z);
            OPositions[j++].set(s[i] * r2, c[i] * r2, z);
        }
        //筒の奥の前面
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(-s[i] * r, c[i] * r, -0.5f);
        }
        //背面
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i] * r, c[i] * r, -0.5f);
        }
        OPositions[j++].set(0, 0, -0.5f);
        OPositions[j++].set(0, 0, -0.5f);

        //法線ベクトル-----------------------------------------------
        j = 0;
        //外側の筒
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(s[i], c[i], 0);
            ONormals[j++].set(s[i], c[i], 0);
        }
        //内側の筒
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(s[i], -c[i], 0);
            ONormals[j++].set(s[i], -c[i], 0);
        }
        //前面
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, 1);
            ONormals[j++].set(0, 0, 1);
        }
        //筒の奥手前面
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, 1);
        }
        //背面
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, -1);
        }
        ONormals[j++].set(0, 0, 1);
        ONormals[j++].set(0, 0, -1);

        //インデックス-----------------------------------------------
        int max = numCorners * 2;
        j = 0;
        //外側、内側、前面ドーナツ
        int m;
        for (int l = 0; l < 3; l++) {
            m = max * l;
            for (int i = 0; i < numCorners; i++) {
                int k = i * 2;
                Indices[j++] = m + k + 0;
                Indices[j++] = m + k + 1;
                Indices[j++] = m + (k + 2) % max;

                Indices[j++] = Indices[j - 1];
                Indices[j++] = Indices[j - 3];
                Indices[j++] = Indices[j - 2] + 1;
            }
        }
        //後ろの円（表裏）
        for (int l = 0; l < 2; l++) {
            m = max * 3 + numCorners * l;
            for (int i = 0; i < numCorners; i++) {
                Indices[j++] = NumVertices - (2-l);
                Indices[j++] = m + i;
                Indices[j++] = m + (i + 1) % numCorners;
            }
        }

        //解放
        delete[]s;
        delete[]c;
    }
};