//////////////////////////////////////////////////////////////
// File.    InputManager.cpp
// Summary. InputManagerClass
// Date.    2018/08/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// �C���N���[�h�f�B���N�g��
#include "InputManager.h"

// using�f�B���N�g��

// �ÓI�ϐ��̏�����
const int InputManager::SAVE_FRAME = 10;
std::list<InputManager::KeyData> InputManager::m_keySave;


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
	for (std::list<KeyData>::iterator it = m_keySave.begin(); it != m_keySave.end();it++)
	{
		(it)->frame++;
	}

	//���t���[���ŋL�������R�[�h���폜
	m_keySave.erase(
		std::remove_if(m_keySave.begin(), m_keySave.end(),
			[](KeyData data) { return data.frame >= SAVE_FRAME; }),
		m_keySave.end());


}

/// <summary>
/// �L�[�̒ǉ�
/// </summary>
void InputManager::AddKey(int code)
{
	m_keySave.push_back(KeyData(code));
}