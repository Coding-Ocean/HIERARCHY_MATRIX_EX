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

        //�e�o�b�t�@���m��-------------------------------------------
        NumVertices = numCorners * 2;//����
        NumVertices += numCorners * 2 + 2;//�O��
        NumTriangles = numCorners * 2;//����
        NumTriangles += numCorners * 2;//�O��
        allocateMemory();

        //���W-------------------------------------------------------
        //s,c�z��ɁA���炩����sin,cos�̒l���v�Z���Ă���
        float* s = new float[numCorners];
        float* c = new float[numCorners];
        float angle = 3.1415926f * 2 / numCorners;
        for (int i = 0; i < numCorners; i++) {
            s[i] = sin(angle * i);
            c[i] = cos(angle * i);
        }
        //���ʁu��끨�O����끨�O�E�E�E�v�ƍ��W����ׂĂ���
        int j = 0;
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i] * backRadius, c[i] * backRadius, backZ);
            OPositions[j++].set(s[i] * frontRadius, c[i] *frontRadius, frontZ);
        }
        //�O
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(-s[i] * frontRadius, c[i] * frontRadius, frontZ);
        }
        //���
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i] *backRadius, c[i] * backRadius, backZ);
        }
        //�O�㒆�S
        OPositions[j++].set(0, 0, frontZ);
        OPositions[j++].set(0, 0, backZ);

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
        //�O
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, 1);
        }
        //���
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, -1);
        }
        //�O���S
        ONormals[j++].set(0, 0, 1);
        //��뒆�S
        ONormals[j++].set(0, 0, -1);

        //�C���f�b�N�X-----------------------------------------------
        //�S�p�`�P�ʂŒ��_�ԍ���I�����Ă���
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
        //�O��
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


        //���
        delete[]s;
        delete[]c;
    }
};