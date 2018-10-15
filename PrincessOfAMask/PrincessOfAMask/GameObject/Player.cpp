//////////////////////////////////////////////////////////////
// File.    Player.cpp
// Summary. PlayerClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// インクルードディレクトリ
#include "Player.h"

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
	: m_hp(0.0f),
      m_exp(0.0f),
	  m_level(0),
	  m_emotion(Emotion::NORMAL)
{
}
/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
}

/// <summary>
/// 更新
/// </summary>
/// <returns>終了状態</returns>
bool Player::Update()
{
	return true;
}

/// <summary>
/// 描画
/// </summary>
void Player::Render()
{
}
