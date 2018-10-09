//////////////////////////////////////////////////////////////
// File.    InputManager.h
// Summary. InputManagerClass
// Date.    2018/08/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include "../pch.h"

#include <Keyboard.h>
#include <Mouse.h>

#include "SingletonBase.h"

class InputManager : public SingletonBase<InputManager>
{
// �����o�[�ϐ�
private:
	std::unique_ptr<DirectX::Keyboard> mp_keyboard;        // �L�[���͏��
	std::unique_ptr<DirectX::Mouse> mp_mouse;              // �}�E�X���͏��
	

	DirectX::Mouse::ButtonStateTracker m_mouseTracker;          // �}�E�X�g���b�J�[
	DirectX::Keyboard::KeyboardStateTracker m_keyTracker;  // �L�[�g���b�J�[

// �����o�[�֐�(�֐��AGetter�ASetter)
private:
	// �t�����h�֐�
	friend class SingletonBase<InputManager>;

	// �R���X�g���N�^
	InputManager();

public:

	// �X�V
	void Update();

	// �}�E�X�̏�Ԏ擾
	DirectX::Mouse::State GetMouseState();
	// �L�[�{�[�h�̏�Ԏ擾
	DirectX::Keyboard::State GetKeyState();
	// Tracker�̎擾
	DirectX::Mouse::ButtonStateTracker GetTracker();
	DirectX::Keyboard::KeyboardStateTracker GetKeyTracker();

	// �}�E�X���W�̎擾
	int GetMousePosX() { return GetMouseState().x; }
	int GetMousePosY() { return GetMouseState().y; }
};