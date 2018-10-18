//////////////////////////////////////////////////////////////
// File.    InputManager.h
// Summary. InputManagerClass
// Date.    2018/08/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include <Keyboard.h>
#include <algorithm>
#include <list>

#include "SingletonBase.h"

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
	
// �����o�[�֐�(�֐��AGetter�ASetter)
private:
	
	// �R���X�g���N�^
	InputManager();

	// Tracker�̎擾
	DirectX::Keyboard::KeyboardStateTracker GetKeyTracker();

public:
	friend SingletonBase<InputManager>;

	// �X�V
	void Update();

	// �L�[�{�[�h�̏�Ԏ擾
	DirectX::Keyboard::State GetKeyState();

	// �L�[�f�[�^��ǉ�����
	void AddKey(int code);

	// �����o�[�ϐ�
private:
	std::unique_ptr<DirectX::Keyboard> mp_keyboard;        // �L�[���͏��

	DirectX::Keyboard::KeyboardStateTracker m_keyTracker;  // �L�[�g���b�J�[

	static std::list<KeyData> m_keySave;				   // �L�[���͂̋L��

	static const int SAVE_FRAME;						   // �L�[���L������t���[����

};