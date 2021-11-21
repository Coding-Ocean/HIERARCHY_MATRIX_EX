#pragma once
#include"MODEL.h"
class JAG : public MODEL {
public:
    JAG(int numCorners = 6,float inner = 1, float thickness = 1) {

        //�e�o�b�t�@���m��-------------------------------------------
        NumVertices = numCorners * 6 + 2;
        NumTriangles = numCorners * 4;
        allocateMemory();

        //���W-------------------------------------------------------
        //s,c�z��ɁA���炩����sin,cos�̒l���v�Z���Ă���
        float* s = new float[numCorners];
        float* c = new float[numCorners];
        float angle = 3.1415926f * 2 / numCorners;
        for (int i = 0; i < numCorners; i++) {
            float radius = (i % 2 == 0) ? 0.5f : 0.5f * inner;
            s[i] = sin(angle * i) * radius;
            c[i] = cos(angle * i) * radius;
        }
        //����
        int j = 0;
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i], c[i], -0.5f * thickness);
            OPositions[j++].set(s[i], c[i], 0.5f * thickness);
            int k = (i + 1) % numCorners;
            OPositions[j++].set(s[k], c[k], -0.5f * thickness);
            OPositions[j++].set(s[k], c[k], 0.5f * thickness);
        }
        //�O��
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(-s[i], c[i], 0.5f * thickness);
        }
        //����
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i], c[i], -0.5f * thickness);
        }
        //�O�ʒ���
        OPositions[j++].set(0, 0, 0.5f * thickness);
        //���ʒ���
        OPositions[j++].set(0, 0, -0.5f * thickness);

        //�@���x�N�g��-----------------------------------------------
        //����
        j = 0;
        for (int i = 0; i < numCorners; i++) {
            int k = i * 4;
            VECTOR a = OPositions[k + 1] - OPositions[k];
            VECTOR b = OPositions[k + 2] - OPositions[k];
            VECTOR n = normalize(cross(a, b));
            ONormals[j++] = n;
            ONormals[j++] = n;
            ONormals[j++] = n;
            ONormals[j++] = n;
        }
        //�O��
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, 1);
        }
        //����
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, -1);
        }
        //�O�ʒ���
        ONormals[j++].set(0, 0, 1);
        //���ʒ���
        ONormals[j++].set(0, 0, -1);

        //�C���f�b�N�X-----------------------------------------------
        //����
        j = 0;
        for (int i = 0; i < numCorners; i++) {
            int k = i * 4;
            Indices[j++] = k + 0;
            Indices[j++] = k + 1;
            Indices[j++] = k + 2;

            Indices[j++] = Indices[j - 1];
            Indices[j++] = Indices[j - 3];
            Indices[j++] = k + 3;
        }
        //�O��
        for (int i = 0; i < numCorners; i++) {
            int k = numCorners * 4 + i;
            Indices[j++] = NumVertices - 2;
            Indices[j++] = k;
            Indices[j++] = k + 1;
        }
        Indices[j - 1] -= numCorners;
        //����
        for (int i = 0; i < numCorners; i++) {
            int k = numCorners * 5 + i;
            Indices[j++] = NumVertices - 1;
            Indices[j++] = k;
            Indices[j++] = k + 1;
        }
        Indices[j - 1] -= numCorners;


        //���
        delete[]s;
        delete[]c;
    }
};