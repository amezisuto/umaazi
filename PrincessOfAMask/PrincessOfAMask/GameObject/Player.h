//////////////////////////////////////////////////////////////
// File.    Player.h
// Summary. PlayerClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include "Emotion.h"
#include "PlayerStates.h"
#include "..\Utility\InputManager.h"

class Player : public SingletonBase<Player>
{
// �����o�[�ϐ�
public:

private:
	//�v���C���[�̃X�e�[�^�X
	PlayerStates m_states;
	EmotionState m_emotion;

// �����o�[�֐�
public:
	friend SingletonBase<Player>;

	// �f�X�g���N�^�[
	~Player();

	// �X�V
	void Update();
	// �`��
	void Render();

	// Getter
	PlayerStates GetPlayerStates()		  { return m_states; }
	EmotionState GetEmotion()             { return m_emotion; }

	// Setter
	void SetStates(PlayerStates states)   { m_states = states; }
	void SetEmotion(EmotionState emotion) { m_emotion = emotion; }

private:
	// �R���X�g���N�^�[
	Player(PlayerStates states);
};