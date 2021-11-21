#pragma once
#include"MODEL.h"
class CUBE : public MODEL {
public:
    CUBE() {
        //「座標」「法線ベクトル」「インデックス」のバッファを確保
        int numSquares = 6;
        NumVertices = 4 * numSquares;
        NumTriangles = 2 * numSquares;
        allocateMemory();

        //座標設定---------------------------------------------------
        //必要最低限の座標を用意して、後でOPositions配列に配る
        VECTOR p[8];
        p[0].set(-0.5f, 0.5f, 0.5f);
        p[1].set(-0.5f, -0.5f, 0.5f);
        p[2].set(0.5f, 0.5f, 0.5f);
        p[3].set(0.5f, -0.5f, 0.5f);
        p[4].set(0.5f, 0.5f, -0.5f);
        p[5].set(0.5f, -0.5f, -0.5f);
        p[6].set(-0.5f, 0.5f, -0.5f);
        p[7].set(-0.5f, -0.5f, -0.5f);
        //６面分の座標を設定
        for (int i = 0; i < numSquares; i++) {
            int j = i * 4;
            if (i <= 3) {
                //前、右、後、左の側面
                int k = i * 2;
                OPositions[j + 0] = p[k + 0];
                OPositions[j + 1] = p[k + 1];
                OPositions[j + 2] = p[(k + 2) % 8];
                OPositions[j + 3] = p[(k + 3) % 8];
            }
            else if (i == 4) {
                //上面
                OPositions[j + 0] = p[6];
                OPositions[j + 1] = p[0];
                OPositions[j + 2] = p[4];
                OPositions[j + 3] = p[2];
            }
            else if (i == 5) {
                //底面
                OPositions[j + 0] = p[5];
                OPositions[j + 1] = p[3];
                OPositions[j + 2] = p[7];
                OPositions[j + 3] = p[1];
            }
        }

        //法線ベクトル設定（平面でも１頂点に１つ必要）---------------
        //必要最低限のベクトルを用意して、後でONormals配列に配る
        VECTOR n[6];
        n[0].set(0, 0, 1);
        n[1].set(1, 0, 0);
        n[2].set(0, 0, -1);
        n[3].set(-1, 0, 0);
        n[4].set(0, 1, 0);
        n[5].set(0, -1, 0);
        //４頂点ごとに法線ベクトルを設定
        for (int i = 0; i < numSquares; i++) {
            int j = i * 4;
            ONormals[j + 0] = n[i];
            ONormals[j + 1] = n[i];
            ONormals[j + 2] = n[i];
            ONormals[j + 3] = n[i];
        }

        //インデックス設定-------------------------------------------
        for (int i = 0; i < numSquares; i++) {
            int j = i * 6;
            int k = i * 4;

            Indices[j + 0] = k + 0;
            Indices[j + 1] = k + 1;
            Indices[j + 2] = k + 2;

            Indices[j + 3] = k + 2;
            Indices[j + 4] = k + 1;
            Indices[j + 5] = k + 3;
        }
    }
    ~CUBE() {}
};

