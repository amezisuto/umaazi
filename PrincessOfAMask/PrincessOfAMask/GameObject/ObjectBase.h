//////////////////////////////////////////////////////////////
// File.    ObjectBase.h
// Summary. ObjectBaseClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include "../pch.h"

class ObjectBase
{
// �����o�[�ϐ�
protected:
	DirectX::SimpleMath::Vector2 m_pos;
	DirectX::SimpleMath::Vector2 m_vel;

// �����o�[�֐�
public:
	// �R���X�g���N�^�[
	ObjectBase();
	// �f�X�g���N�^�[
	virtual ~ObjectBase();

	// �X�V
	virtual bool Update() = 0;
	// �`��
	virtual void Render() = 0;
};