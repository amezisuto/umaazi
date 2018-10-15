//////////////////////////////////////////////////////////////
// File.    InputManager.cpp
// Summary. InputManagerClass
// Date.    2018/08/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// �C���N���[�h�f�B���N�g��
#include "InputManager.h"

// using�f�B���N�g��

// �萔
const int InputManager::SAVE_FRAME = 10;

/// <summary>
/// �R���X�g���N�^
/// </summary>
InputManager::InputManager()
{
	mp_keyboard = std::make_unique<DirectX::Keyboard>();
}

/// <summary>
/// �L�[�̓��͏�Ԃ̎擾
/// </summary>
/// <returns>���͏��</returns>
DirectX::Keyboard::State InputManager::GetKeyState()
{
	return mp_keyboard->GetState();
}

/// <summary>
/// Tracker�̎擾
/// </summary>
/// <returns>Tracker</returns>
DirectX::Keyboard::KeyboardStateTracker InputManager::GetKeyTracker()
{
	return m_keyTracker;
}

/// <summary>
/// �X�V����
/// </summary>
void InputManager::Update()
{
	DirectX::Keyboard::State keyState = GetKeyState();
	m_keyTracker.Update(keyState);

	//���t���[���L�������R�[�h�̃t���[����i�߂�
	for (std::list<KeyData>::iterator it = m_keyMemo.begin(); it != m_keyMemo.end();it++)
	{
		it->frame++;
	}



}


void InputManager::AddKey(int code)
{
	m_keyMemo.push_back(KeyData(code));
}