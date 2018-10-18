//////////////////////////////////////////////////////////////
// File.    InputManager.h
// Summary. InputManagerClass
// Date.    2018/08/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include <Keyboard.h>
#include <algorithm>
#include <list>

#include "SingletonBase.h"

class InputManager : public SingletonBase<InputManager>
{
public:
	// キー情報の構造体
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
	
// メンバー関数(関数、Getter、Setter)
private:
	
	// コンストラクタ
	InputManager();

	// Trackerの取得
	DirectX::Keyboard::KeyboardStateTracker GetKeyTracker();

public:
	friend SingletonBase<InputManager>;

	// 更新
	void Update();

	// キーボードの状態取得
	DirectX::Keyboard::State GetKeyState();

	// キーデータを追加する
	void AddKey(int code);

	// メンバー変数
private:
	std::unique_ptr<DirectX::Keyboard> mp_keyboard;        // キー入力情報

	DirectX::Keyboard::KeyboardStateTracker m_keyTracker;  // キートラッカー

	static std::list<KeyData> m_keySave;				   // キー入力の記憶

	static const int SAVE_FRAME;						   // キーを記憶するフレーム数

};