//////////////////////////////////////////////////////////////
// File.    Player.h
// Summary. PlayerClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include "Emotion.h"
#include "PlayerStates.h"
#include "..\Utility\InputManager.h"

class Player : public SingletonBase<Player>
{
// メンバー変数
public:

private:
	//プレイヤーのステータス
	PlayerStates m_states;
	EmotionState m_emotion;

// メンバー関数
public:
	friend SingletonBase<Player>;

	// デストラクター
	~Player();

	// 更新
	void Update();
	// 描画
	void Render();

	// Getter
	PlayerStates GetPlayerStates()		  { return m_states; }
	EmotionState GetEmotion()             { return m_emotion; }

	// Setter
	void SetStates(PlayerStates states)   { m_states = states; }
	void SetEmotion(EmotionState emotion) { m_emotion = emotion; }

private:
	// コンストラクター
	Player(PlayerStates states);
};