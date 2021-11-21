#pragma once
#include"MODEL.h"
class CUBE : public MODEL {
public:
    CUBE() {
        //�u���W�v�u�@���x�N�g���v�u�C���f�b�N�X�v�̃o�b�t�@���m��
        int numSquares = 6;
        NumVertices = 4 * numSquares;
        NumTriangles = 2 * numSquares;
        allocateMemory();

        //���W�ݒ�---------------------------------------------------
        //�K�v�Œ���̍��W��p�ӂ��āA���OPositions�z��ɔz��
        VECTOR p[8];
        p[0].set(-0.5f, 0.5f, 0.5f);
        p[1].set(-0.5f, -0.5f, 0.5f);
        p[2].set(0.5f, 0.5f, 0.5f);
        p[3].set(0.5f, -0.5f, 0.5f);
        p[4].set(0.5f, 0.5f, -0.5f);
        p[5].set(0.5f, -0.5f, -0.5f);
        p[6].set(-0.5f, 0.5f, -0.5f);
        p[7].set(-0.5f, -0.5f, -0.5f);
        //�U�ʕ��̍��W��ݒ�
        for (int i = 0; i < numSquares; i++) {
            int j = i * 4;
            if (i <= 3) {
                //�O�A�E�A��A���̑���
                int k = i * 2;
                OPositions[j + 0] = p[k + 0];
                OPositions[j + 1] = p[k + 1];
                OPositions[j + 2] = p[(k + 2) % 8];
                OPositions[j + 3] = p[(k + 3) % 8];
            }
            else if (i == 4) {
                //���
                OPositions[j + 0] = p[6];
                OPositions[j + 1] = p[0];
                OPositions[j + 2] = p[4];
                OPositions[j + 3] = p[2];
            }
            else if (i == 5) {
                //���
                OPositions[j + 0] = p[5];
                OPositions[j + 1] = p[3];
                OPositions[j + 2] = p[7];
                OPositions[j + 3] = p[1];
            }
        }

        //�@���x�N�g���ݒ�i���ʂł��P���_�ɂP�K�v�j---------------
        //�K�v�Œ���̃x�N�g����p�ӂ��āA���ONormals�z��ɔz��
        VECTOR n[6];
        n[0].set(0, 0, 1);
        n[1].set(1, 0, 0);
        n[2].set(0, 0, -1);
        n[3].set(-1, 0, 0);
        n[4].set(0, 1, 0);
        n[5].set(0, -1, 0);
        //�S���_���Ƃɖ@���x�N�g����ݒ�
        for (int i = 0; i < numSquares; i++) {
            int j = i * 4;
            ONormals[j + 0] = n[i];
            ONormals[j + 1] = n[i];
            ONormals[j + 2] = n[i];
            ONormals[j + 3] = n[i];
        }

        //�C���f�b�N�X�ݒ�-------------------------------------------
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

