//////////////////////////////////////////////////////////////
// File.    Player.h
// Summary. PlayerClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include "../pch.h"

#include "ObjectBase.h"
#include "Emotion.h"

class Player : ObjectBase
{
// メンバー変数
public:

private:
	float m_hp;
	float m_exp;
	int m_level;
	Emotion::EmotionState m_emotion;

// メンバー関数
public:
	// コンストラクター
	Player();
	// デストラクター
	~Player();

	// 更新
	bool Update();
	// 描画
	void Render();

	// Getter
	float GetHp()                                  { return m_hp; }
	float GetExp()                                 { return m_exp; }
	int GetLevel()                                 { return m_level; }
	Emotion::EmotionState GetEmotion()             { return m_emotion; }

	// Setter
	void SetHp(float hp)                           { m_hp = hp; }
	void SetExp(float exp)                         { m_exp = exp; }
	void SetLevel(int level)                       { m_level = level; }
	void SetEmotion(Emotion::EmotionState emotion) { m_emotion = emotion; }

private:

};