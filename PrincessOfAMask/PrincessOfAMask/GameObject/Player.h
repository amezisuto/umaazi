//////////////////////////////////////////////////////////////
// File.    Player.h
// Summary. PlayerClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include "../pch.h"

#include "ObjectBase.h"
#include "Emotion.h"

class Player : ObjectBase
{
// �����o�[�ϐ�
public:

private:
	float m_hp;
	float m_exp;
	int m_level;
	Emotion::EmotionState m_emotion;

// �����o�[�֐�
public:
	// �R���X�g���N�^�[
	Player();
	// �f�X�g���N�^�[
	~Player();

	// �X�V
	bool Update();
	// �`��
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