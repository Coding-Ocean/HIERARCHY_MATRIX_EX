#pragma once
#include"VECTOR.h"
#include"GAME_POINTER.h"
#include "OBJ_ID.h"
#include "OBJ_STATE.h"
class OBJECT
    :public GAME_POINTER
{
public:
    OBJECT(class GAME* game);
    virtual ~OBJECT();
    virtual int setup();
    virtual void update();
    virtual void draw();
    virtual VECTOR pos();
    virtual VECTOR angle();
/*
//�e�I�u�W�F�N�g���ʂɌĂяo�������o----------------------------------------
    //��]����B�w�肵�������ɂ�����������B�����I�������t���b�O�𗧂Ă�
    int rotate(VECTOR* angle, const VECTOR& dir, float speed, int endOfRotationFlag=0);
    //�e���ŏI�^�[�Q�b�g�ɓ����������ɌĂяo���ăt���b�O�𗧂Ă�
    void completeState();

//�S�I�u�W�F�N�g�ɉe������X�e�[�g�֘A�̃X�^�e�B�b�N�����o-------------------
    //�S�I�u�W�F�N�g�̃X�e�[�g���Ǘ�����(���C�����[�v����Ăяo����郁���o)
    static void objStateManager();
private:
    //�X�e�[�g�J�n���Ɂu�X�e�[�g�I���Ɣ��f���邽�߂̃t���b�O�v��n���ă��Z�b�g
    static void ResetEndFlags(int completedFlags);
    //�X�e�[�g���I��������ǂ������f�ł���
    static int EndOfState();
public:
    //Getter
    static OBJ_STATE objState();
    static int formationId();
private:
    //�I�u�W�F�N�g�̏��
    static OBJ_STATE ObjState;
    //���݂̃t�H�[���[�V����Id
    static int FormationId;
    //EndOfStateFlags��CompletedFlags�Ɠ������Ȃ����炻�̃X�e�[�g�͏I��
    static int EndOfStateFlags;
    static int CompletedFlags;
    //�X�e�[�g�J�n���AresetEndFlags()�̃p�����^�ɐݒ肷��t���O
    //(��������������邪�A���̂Ƃ��낱�ꂵ���v�����Ȃ�)
    static int RotationCompletedFlags;
    static int FlyingCompletedFlags;
*/
};
