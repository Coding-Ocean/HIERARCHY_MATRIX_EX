#pragma once
#pragma once
#include"MODEL.h"
class BARREL : public MODEL {
public:
    BARREL() {
        //noCulling();

        //�e�o�b�t�@���m��-------------------------------------------
        int numCorners = 36;
        NumVertices = numCorners * 8 + 2;
        NumTriangles = numCorners * 8;
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
        float r = 0.5f;//�O�����a
        float r2 = 0.3f;//�������a
        float z = 1;
        int j = 0;
        //�O���̓�
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i] * r, c[i] * r, -0.5f);
            OPositions[j++].set(s[i] * r, c[i] * r, z);
        }
        //�����̓�
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(-s[i] * r2, c[i] * r2, -0.5f);
            OPositions[j++].set(-s[i] * r2, c[i] * r2, z);
        }
        //�O�ʂ̃h�[�i�c
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i] * r, c[i] * r, z);
            OPositions[j++].set(s[i] * r2, c[i] * r2, z);
        }
        //���̉��̑O��
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(-s[i] * r, c[i] * r, -0.5f);
        }
        //�w��
        for (int i = 0; i < numCorners; i++) {
            OPositions[j++].set(s[i] * r, c[i] * r, -0.5f);
        }
        OPositions[j++].set(0, 0, -0.5f);
        OPositions[j++].set(0, 0, -0.5f);

        //�@���x�N�g��-----------------------------------------------
        j = 0;
        //�O���̓�
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(s[i], c[i], 0);
            ONormals[j++].set(s[i], c[i], 0);
        }
        //�����̓�
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(s[i], -c[i], 0);
            ONormals[j++].set(s[i], -c[i], 0);
        }
        //�O��
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, 1);
            ONormals[j++].set(0, 0, 1);
        }
        //���̉���O��
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, 1);
        }
        //�w��
        for (int i = 0; i < numCorners; i++) {
            ONormals[j++].set(0, 0, -1);
        }
        ONormals[j++].set(0, 0, 1);
        ONormals[j++].set(0, 0, -1);

        //�C���f�b�N�X-----------------------------------------------
        int max = numCorners * 2;
        j = 0;
        //�O���A�����A�O�ʃh�[�i�c
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
        //���̉~�i�\���j
        for (int l = 0; l < 2; l++) {
            m = max * 3 + numCorners * l;
            for (int i = 0; i < numCorners; i++) {
                Indices[j++] = NumVertices - (2-l);
                Indices[j++] = m + i;
                Indices[j++] = m + (i + 1) % numCorners;
            }
        }

        //���
        delete[]s;
        delete[]c;
    }
};