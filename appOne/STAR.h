#pragma once
#include"MODEL.h"
class STAR : public MODEL {
public:
    STAR(int num = 12, float inner = 0.5f, float thickness=0.3f) {
        NumTriangles = num * 2;
        NumVertices = NumTriangles * 3;
        allocateMemory();
        //位置
        float theta = M_2PI / num;
        float radius = 0;
        for (int i = 0; i < NumTriangles / 2; i++) {
            int j = i * 3;
            //手前の面
            OPositions[j + 0].set(0, 0, 0.5f*thickness);
            radius = ((j + 1) % 2 == 1) ? 0.5f : 0.5f * inner;
            OPositions[j + 1].set(sin(theta * i) * radius,cos(theta * i) * radius, 0);
            radius = ((j + 2) % 2 == 1) ? 0.5f : 0.5f * inner;
            OPositions[j + 2].set(sin(theta * (i + 1)) * radius, cos(theta * (i + 1)) * radius, 0);
            //向こうの面
            int k = j + NumVertices / 2;
            OPositions[k + 0].set(0, 0, -0.5f*thickness);
            OPositions[k + 1] = OPositions[j + 2];
            OPositions[k + 2] = OPositions[j + 1];
        }
        //インデックス
        for (int i = 0; i < NumTriangles; i++) {
            int j = i * 3;
            Indices[j + 0] = j + 0;
            Indices[j + 1] = j + 2;
            Indices[j + 2] = j + 1;
        }
        //法線ベクトル
        int k, l, m;
        for (int i = 0; i < NumTriangles; i++) {
            int j = i * 3;
            k = Indices[j + 0];
            l = Indices[j + 1];
            m = Indices[j + 2];
            VECTOR a = OPositions[l] - OPositions[k];
            VECTOR b = OPositions[m] - OPositions[k];
            VECTOR c = normalize(cross(a, b));
            ONormals[k] = c;
            ONormals[l] = c;
            ONormals[m] = c;
        }
    }
};
