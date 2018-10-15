//////////////////////////////////////////////////////////////
// File.    InputManager.h
// Summary. InputManagerClass
// Date.    2018/08/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include <Keyboard.h>

#include "SingletonBase.h"
#include <list>

class InputManager : public SingletonBase<InputManager>
{
public:
	// �L�[���̍\����
	struct KeyData
	{
		int code;
		int frame;
		KeyData(int code)
		{
			this->code = code;
			frame = 0;
		}
	};

// �����o�[�ϐ�
private:
	std::unique_ptr<DirectX::Keyboard> mp_keyboard;        // �L�[���͏��
	
	DirectX::Keyboard::KeyboardStateTracker m_keyTracker;  // �L�[�g���b�J�[

	std::list<KeyData> m_keyMemo;						   // �L�[���͂̋L��

	static const int SAVE_FRAME;

// �����o�[�֐�(�֐��AGetter�ASetter)
private:
	// �t�����h�֐�
	friend class SingletonBase<InputManager>;

	// �R���X�g���N�^
	InputManager();

public:

	// �X�V
	void Update();

	// �L�[�{�[�h�̏�Ԏ擾
	DirectX::Keyboard::State GetKeyState();
	
	// Tracker�̎擾
	DirectX::Keyboard::KeyboardStateTracker GetKeyTracker();

	// �L�[�f�[�^��ǉ�����
	void AddKey(int code);
};