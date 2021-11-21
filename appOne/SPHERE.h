#pragma once
#include"MODEL.h"
class SPHERE : public MODEL {
public:
    SPHERE(int numCorners = 36) {
        //�e�o�b�t�@���m��-------------------------------------------
        int numRings = numCorners / 2 - 1;
        int numCylinders = numRings - 1;
        NumVertices = numCorners * numRings;
        NumVertices += 2;//�O�ʁA���ʗp�ǉ�
        NumTriangles = numCorners * 2 * numCylinders;
        NumTriangles += numCorners * 2;//�O�ʁA���ʗp�ǉ�
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
        //����
        int j = 0;
        float radius = 0.5f;
        for (int k = 1; k <= numRings; k++) {
            float r = s[k] * radius;//ring radius;
            float z = c[k] * radius;//ring position z
            for (int i = 0; i < numCorners; i++) {
                OPositions[j++].set(s[i] * r, c[i] * r, z);//���v���
            }
        }
        //�O�ʒ��S
        OPositions[j++].set(0, 0, radius);
        //���ʒ��S
        OPositions[j++].set(0, 0, -radius);

        //�@���x�N�g��-----------------------------------------------
        //����
        j = 0;
        for (int k = 1; k <= numRings; k++) {
            float r = s[k];
            float z = c[k];
            for (int i = 0; i < numCorners; i++) {
                ONormals[j++].set(s[i] * r, c[i] * r, z);
            }
        }
        //�O�ʒ��S
        ONormals[j++].set(0, 0, 1);
        //���ʒ��S
        ONormals[j++].set(0, 0, -1);

        //�C���f�b�N�X-----------------------------------------------
        j = 0;
        for (int i = 0; i < numCorners * numCylinders; i++) {
            //�����O�p�`
            Indices[j++] = i;
            Indices[j++] = i + 1;
            Indices[j++] = i + numCorners;
            if (Indices[j - 2] % numCorners == 0)Indices[j - 2] -= numCorners;
            //�E��O�p�`
            Indices[j++] = Indices[j - 1];
            Indices[j++] = Indices[j - 3];
            Indices[j++] = Indices[j - 2] + 1;
            if (Indices[j - 1] % numCorners == 0)Indices[j - 1] -= numCorners;
        }
        //�O��(�����v���ɑI��)
        for (int i = 0; i < numCorners; i++) {
            Indices[j++] = NumVertices - 2;//�O�ʒ��S
            Indices[j++] = i + 1;
            Indices[j++] = i;
        }
        Indices[j - 2] -= numCorners;
        //����(���v���ɑI��)
        for (int i = 0; i < numCorners; i++) {
            int k = numCorners * numCylinders + i;
            Indices[j++] = NumVertices - 1;//���ʒ��S
            Indices[j++] = k;
            Indices[j++] = k + 1;
        }
        Indices[j - 1] -= numCorners;

        //���
        delete[]s;
        delete[]c;
    }
};