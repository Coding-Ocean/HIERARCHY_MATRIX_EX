#include "GAME.h"
#include "OBJECT.h"

OBJECT::OBJECT(GAME* game)
    :GAME_POINTER(game)
{
}

OBJECT::~OBJECT()
{
}

int OBJECT::setup()
{
    return 0;
}

void OBJECT::update()
{
}

void OBJECT::draw()
{
}

VECTOR OBJECT::pos()
{
    return VECTOR();
}

VECTOR OBJECT::angle()
{
    return VECTOR();
}
/*
//�e�I�u�W�F�N�g���ʂɌĂяo�������o----------------------------------------
//��]����B�w�肵�������ɂ�����������B�����I�������t���O�𗧂Ă�B
int OBJECT::rotate(
    VECTOR* angle, const VECTOR& dir, float rotSpeed, int endOfRotationFlag)
{
    //�w����]������angle�����߂�
    //���̎��̂悤�Ɂu�^�����������x�N�g���v�Ɓu���x�N�g���v�̓��ς́A-b.y�ɂȂ�
    //cos�� = downVec(0,-1,0) �E b(x,y,z) = -b.y
    VECTOR b = normalize(dir);
    float angleBetweenX = -(acos(-b.y) - 1.57f) - angle->x;
    angle->x += angleBetweenX * rotSpeed;
    //�x����]������angle�����߂�
    VECTOR a(sin(angle->y), 0, cos(angle->y));
    float dotProduct = a.x * b.x + a.z * b.z;
    float crossProduct = a.x * b.z - a.z * b.x;
    float angleBetweenY = atan2(-crossProduct, dotProduct);
    angle->y += angleBetweenY * rotSpeed;
    //��]�I��
    if (-0.017f < angleBetweenY && angleBetweenY < 0.017f) {
        EndOfStateFlags |= endOfRotationFlag;
        return 1;
    }
    return 0;
}

//�e���ŏI�^�[�Q�b�g�ɓ����������ɌĂяo���ăt���b�O�𗧂Ă�B
void OBJECT::completeState()
{
    EndOfStateFlags = CompletedFlags;
}

//�S�I�u�W�F�N�g�ɉe������X�e�[�g�֘A�̃X�^�e�B�b�N�����o-------------------
OBJ_STATE OBJECT::ObjState = OBJ_STATE::MOVE;
int OBJECT::EndOfStateFlags = 0;
int OBJECT::CompletedFlags = 0;
int OBJECT::RotationCompletedFlags = 0b111;
int OBJECT::FlyingCompletedFlags = 0b1;
int OBJECT::FormationId = 0;

//�S�I�u�W�F�N�g�̃X�e�[�g���Ǘ�����(���C�����[�v����Ăяo����郁���o)
void OBJECT::objStateManager()
{
    if (ObjState == OBJ_STATE::MOVE) {
        //�L�[���͂Ńt�H�[���[�V�����؂�ւ�
        if (isTrigger(KEY_X)) {
            ++FormationId %= 3;
        }
        //�L�[���͂ŉ�]�J�n��
        if (isTrigger(KEY_Z)) {
            ResetEndFlags(RotationCompletedFlags);
            ObjState = OBJ_STATE::ROTATE;
        }
    }
    else if (ObjState == OBJ_STATE::ROTATE) {
        //�S�I�u�W�F�N�g�̉�]���I��������A�e�̔�s��
        if (EndOfState()) {
            ResetEndFlags(FlyingCompletedFlags);
            ObjState = OBJ_STATE::FLY;
        }
    }
    else if (ObjState == OBJ_STATE::FLY) {
        //�e���ŏI�^�[�Q�b�g�ɓ��B������A���̕����ɉ�]�J�n��
        if (EndOfState()) {
            ResetEndFlags(RotationCompletedFlags);
            ObjState = OBJ_STATE::ROTATE_BACK;
        }
    }
    else if (ObjState == OBJ_STATE::ROTATE_BACK) {
        //�S�I�u�W�F�N�g�����̕����ɉ�]���I�������A�ʏ�̓�����
        if (EndOfState()) {
            ObjState = OBJ_STATE::MOVE;
        }
    }
}

void OBJECT::ResetEndFlags(int completedFlags)
{
    EndOfStateFlags = 0;
    CompletedFlags = completedFlags;
}

int OBJECT::EndOfState()
{
    return EndOfStateFlags == CompletedFlags;
}

//Getter
OBJ_STATE OBJECT::objState()
{
    return ObjState;
}

int OBJECT::formationId() 
{
    return FormationId;
}
*/