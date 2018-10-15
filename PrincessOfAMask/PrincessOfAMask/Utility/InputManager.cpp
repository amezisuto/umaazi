//////////////////////////////////////////////////////////////
// File.    InputManager.cpp
// Summary. InputManagerClass
// Date.    2018/08/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// インクルードディレクトリ
#include "InputManager.h"

// usingディレクトリ

// 定数
const int InputManager::SAVE_FRAME = 10;

/// <summary>
/// コンストラクタ
/// </summary>
InputManager::InputManager()
{
	mp_keyboard = std::make_unique<DirectX::Keyboard>();
}

/// <summary>
/// キーの入力状態の取得
/// </summary>
/// <returns>入力状態</returns>
DirectX::Keyboard::State InputManager::GetKeyState()
{
	return mp_keyboard->GetState();
}

/// <summary>
/// Trackerの取得
/// </summary>
/// <returns>Tracker</returns>
DirectX::Keyboard::KeyboardStateTracker InputManager::GetKeyTracker()
{
	return m_keyTracker;
}

/// <summary>
/// 更新処理
/// </summary>
void InputManager::Update()
{
	DirectX::Keyboard::State keyState = GetKeyState();
	m_keyTracker.Update(keyState);

	//毎フレーム記憶したコードのフレームを進める
	for (std::list<KeyData>::iterator it = m_keyMemo.begin(); it != m_keyMemo.end();it++)
	{
		it->frame++;
	}



}


void InputManager::AddKey(int code)
{
	m_keyMemo.push_back(KeyData(code));
}