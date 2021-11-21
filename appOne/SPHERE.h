#pragma once
#include"MODEL.h"
class SPHERE : public MODEL {
public:
    SPHERE(int numCorners = 36) {
        //各バッファを確保-------------------------------------------
        int numRings = numCorners / 2 - 1;
        int numCylinders = numRings - 1;
        NumVertices = numCorners * numRings;
        NumVertices += 2;//前面、裏面用追加
        NumTriangles = numCorners * 2 * numCylinders;
        NumTriangles += numCorners * 2;//前面、裏面用追加
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
        //側面
        int j = 0;
        float radius = 0.5f;
        for (int k = 1; k <= numRings; k++) {
            float r = s[k] * radius;//ring radius;
            float z = c[k] * radius;//ring position z
            for (int i = 0; i < numCorners; i++) {
                OPositions[j++].set(s[i] * r, c[i] * r, z);//時計回り
            }
        }
        //前面中心
        OPositions[j++].set(0, 0, radius);
        //裏面中心
        OPositions[j++].set(0, 0, -radius);

        //法線ベクトル-----------------------------------------------
        //側面
        j = 0;
        for (int k = 1; k <= numRings; k++) {
            float r = s[k];
            float z = c[k];
            for (int i = 0; i < numCorners; i++) {
                ONormals[j++].set(s[i] * r, c[i] * r, z);
            }
        }
        //前面中心
        ONormals[j++].set(0, 0, 1);
        //裏面中心
        ONormals[j++].set(0, 0, -1);

        //インデックス-----------------------------------------------
        j = 0;
        for (int i = 0; i < numCorners * numCylinders; i++) {
            //左下三角形
            Indices[j++] = i;
            Indices[j++] = i + 1;
            Indices[j++] = i + numCorners;
            if (Indices[j - 2] % numCorners == 0)Indices[j - 2] -= numCorners;
            //右上三角形
            Indices[j++] = Indices[j - 1];
            Indices[j++] = Indices[j - 3];
            Indices[j++] = Indices[j - 2] + 1;
            if (Indices[j - 1] % numCorners == 0)Indices[j - 1] -= numCorners;
        }
        //前面(反時計回りに選択)
        for (int i = 0; i < numCorners; i++) {
            Indices[j++] = NumVertices - 2;//前面中心
            Indices[j++] = i + 1;
            Indices[j++] = i;
        }
        Indices[j - 2] -= numCorners;
        //裏面(時計回りに選択)
        for (int i = 0; i < numCorners; i++) {
            int k = numCorners * numCylinders + i;
            Indices[j++] = NumVertices - 1;//裏面中心
            Indices[j++] = k;
            Indices[j++] = k + 1;
        }
        Indices[j - 1] -= numCorners;

        //解放
        delete[]s;
        delete[]c;
    }
};