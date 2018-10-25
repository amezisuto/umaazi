//////////////////////////////////////////////////////////////
// File.    Player.cpp
// Summary. PlayerClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// �C���N���[�h�f�B���N�g��
#include "Player.h"
#include "..\GameDebug\Debug.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Player::Player()
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
void Player::Update()
{
	Debug::SingletonGetInstance().DebugRender("Player",Vector2(60,60));

	Debug::SingletonGetInstance().DebugRender("HP",m_states.Hp, Vector2(100, 100));
	
	Debug::SingletonGetInstance().DebugRender("Lv", m_states.Lv, Vector2(100, 130));
	
	Debug::SingletonGetInstance().DebugRender("Exp", m_states.Exp, Vector2(100, 160));
}

/// <summary>
/// �`��
/// </summary>
void Player::Render()
{
}
