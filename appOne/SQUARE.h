#pragma once
#include"MODEL.h"
class SQUARE : public MODEL {
public:
    SQUARE() {
        //�u���W�v�u�@���x�N�g���v�u�C���f�b�N�X�v�̃o�b�t�@���m��
        int numSquares = 2;
        NumVertices = 4 * numSquares;
        NumTriangles = 2 * numSquares;
        allocateMemory();

        //���W�ݒ�
        OPositions[0].set(-0.5f, 0.5f, 0);
        OPositions[1].set(-0.5f, -0.5f, 0);
        OPositions[2].set(0.5f, 0.5f, 0);
        OPositions[3].set(0.5f, -0.5f, 0);
        OPositions[4].set(0.5f, 0.5f, 0);
        OPositions[5].set(0.5f, -0.5f, 0);
        OPositions[6].set(-0.5f, 0.5f, 0);
        OPositions[7].set(-0.5f, -0.5f, 0);

        //�@���x�N�g���ݒ�
        ONormals[0].set(0, 0, 1);
        ONormals[1].set(0, 0, 1);
        ONormals[2].set(0, 0, 1);
        ONormals[3].set(0, 0, 1);
        ONormals[4].set(0, 0, -1);
        ONormals[5].set(0, 0, -1);
        ONormals[6].set(0, 0, -1);
        ONormals[7].set(0, 0, -1);

        //�C���f�b�N�X�ݒ�
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
};
