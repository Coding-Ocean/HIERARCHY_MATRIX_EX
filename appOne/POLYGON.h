#pragma once
#include"MODEL.h"
class POLYGON : public MODEL {
public:
    POLYGON(int numCorners = 5) {
        //�e�o�b�t�@���m��-------------------------------------------
        NumVertices = numCorners * 2 + 2;
        NumTriangles = numCorners * 2;
        allocateMemory();

        //���W-------------------------------------------------------
        //s,c�z��ɁA���炩����sin,cos�̒l���v�Z���Ă���
        float* s = new float[numCorners];
        float* c = new float[numCorners];
        float angle = 3.1415926f * 2 / numCorners;
        for (int i = 0; i < numCorners; i++) {
            s[i] = sin(angle * i) * 0.5f;
            c[i] = cos(angle * i) * 0.5f;
        }
        //�O��
        int j = 0;
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(-s[i], c[i], 0);//�����v���
        }
        //����
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i], c[i], 0);//���v���
        }
        //�O�ʒ��S
        OPositions[j++].set(0, 0, 0);
        //���ʒ��S
        OPositions[j++].set(0, 0, 0);

        //�@���x�N�g��-----------------------------------------------
        //�O��
        j = 0;
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, 1);
        }
        //����
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, -1);
        }
        //�O�ʒ��S
        ONormals[j++].set(0, 0, 1);
        //���ʒ��S
        ONormals[j++].set(0, 0, -1);

        //�C���f�b�N�X-----------------------------------------------
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

        //���
        delete[]s;
        delete[]c;
    }
};