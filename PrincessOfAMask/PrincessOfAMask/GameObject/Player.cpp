//////////////////////////////////////////////////////////////
// File.    Player.cpp
// Summary. PlayerClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// �C���N���[�h�f�B���N�g��
#include "Player.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Player::Player()
	: m_hp(0.0f),
      m_exp(0.0f),
	  m_level(0),
	  m_emotion(Emotion::NORMAL)
{
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Player::~Player()
{
}

/// <summary>
/// �X�V
/// </summary>
/// <returns>�I�����</returns>
bool Player::Update()
{
	return true;
}

/// <summary>
/// �`��
/// </summary>
void Player::Render()
{
}
