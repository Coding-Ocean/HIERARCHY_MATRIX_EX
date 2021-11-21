#pragma once
#include"MODEL.h"
class PLANE : public MODEL {
public:
    PLANE(float length=0.5f) {
        //�u���W�v�u�@���x�N�g���v�u�C���f�b�N�X�v�̐ݒ�O��
        //�K�����̂R�s�̐ݒ���s���I
        NumVertices = 4;
        NumTriangles = 2;
        allocateMemory();

        //���W�ݒ�
        OPositions[0].set(-length, 0.0f, -length);
        OPositions[1].set(-length, 0.0f,  length);
        OPositions[2].set( length, 0.0f, -length);
        OPositions[3].set( length, 0.0f,  length);

        //�@���x�N�g���ݒ�i���ʂł��P���_�ɂP�K�v�j
        ONormals[0].set(0, 1, 0);
        ONormals[1].set(0, 1, 0);
        ONormals[2].set(0, 1, 0);
        ONormals[3].set(0, 1, 0);

        //�C���f�b�N�X�ݒ�
        Indices[0] = 0;
        Indices[1] = 1;
        Indices[2] = 2;

        Indices[3] = 2;
        Indices[4] = 1;
        Indices[5] = 3;
    }
};
