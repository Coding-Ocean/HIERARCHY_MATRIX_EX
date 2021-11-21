#pragma once
#include"MODEL.h"
class CONE : public MODEL {
public:
    CONE(int numCorners = 36, float radius = 0.5f, float topZ = 0.866f) {
        //�e�o�b�t�@���m��-------------------------------------------
        NumVertices = numCorners * 2;//����
        NumVertices += numCorners + 1;//�w�ʗp�ǉ�
        NumTriangles = numCorners;//����
        NumTriangles += numCorners;//�w�ʗp�ǉ�
        allocateMemory();

        //���W-------------------------------------------------------
        //s,c�z��ɁA���炩����sin,cos�̒l���v�Z���Ă���
        float* s = new float[numCorners];
        float* c = new float[numCorners];
        float angle = 3.1415926f * 2 / numCorners;
        for (int i = 0; i < numCorners; i++) {
            s[i] = sin(angle * i) * radius;
            c[i] = cos(angle * i) * radius;
        }
        //���ʁu��끨�O���S����끨�O���S�E�E�E�v�ƍ��W����ׂĂ���
        int j = 0;
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i], c[i], 0);
            OPositions[j++].set(0, 0, topZ);
        }
        //����
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i], c[i], 0);//���v���
        }
        //���ʒ��S
        OPositions[j++].set(0, 0, 0);

        //�@���x�N�g��-----------------------------------------------
        j = 0;
        for (int i = 0; i < numCorners; i++) {
            int k = i * 2;
            VECTOR a = OPositions[k + 1] - OPositions[k];
            VECTOR b(c[i], -s[i], 0);
            VECTOR n = normalize(cross(a, b));
            ONormals[j++] = n;
            ONormals[j++] = n;
        }
        //����
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, -1);
        }
        //���ʒ��S
        ONormals[j++].set(0, 0, -1);

        //�C���f�b�N�X-----------------------------------------------
        //����
        j = 0;
        for (int i = 0; i < numCorners; i++) {
            int k = i * 2;
            Indices[j++] = k + 0;
            Indices[j++] = k + 1;
            Indices[j++] = k + 2;
        }
        Indices[j - 1] = 0;
        //����
        for (int i = 0; i < numCorners; i++) {
            Indices[j++] = NumVertices - 1;//���ʒ��S
            Indices[j++] = numCorners * 2 + i;
            Indices[j++] = numCorners * 2 + i + 1;
        }
        Indices[j - 1] -= numCorners;

        //���
        delete[]s;
        delete[]c;
    }
};