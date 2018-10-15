//////////////////////////////////////////////////////////////
// File.    InputManager.h
// Summary. InputManagerClass
// Date.    2018/08/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include <Keyboard.h>

#include "SingletonBase.h"
#include <list>

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

// メンバー変数
private:
	std::unique_ptr<DirectX::Keyboard> mp_keyboard;        // キー入力情報
	
	DirectX::Keyboard::KeyboardStateTracker m_keyTracker;  // キートラッカー

	std::list<KeyData> m_keyMemo;						   // キー入力の記憶

	static const int SAVE_FRAME;

// メンバー関数(関数、Getter、Setter)
private:
	// フレンド関数
	friend class SingletonBase<InputManager>;

	// コンストラクタ
	InputManager();

public:

	// 更新
	void Update();

	// キーボードの状態取得
	DirectX::Keyboard::State GetKeyState();
	
	// Trackerの取得
	DirectX::Keyboard::KeyboardStateTracker GetKeyTracker();

	// キーデータを追加する
	void AddKey(int code);
};