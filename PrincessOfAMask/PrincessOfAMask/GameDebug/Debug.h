//////////////////////////////////////////////////////////////
// File.    Debug.h
// Summary. DebugClass
// Date.    2018/10/15
// Auther.  Miu Himi ： Eijirou Tsujii
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include <iostream>
#include <fstream>
#include <sstream>

#include "../pch.h"
#include "../Utility/SingletonBase.h"
#include <list>

// デバッグ
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


class Debug : public SingletonBase<Debug>
{
// メンバー変数
public:
	friend SingletonBase<Debug>;
private:
	// キー情報の構造体
	struct DebugTextData
	{
		std::wstring text;
		DirectX::SimpleMath::Vector2 pos;
		DebugTextData(std::wstring text,DirectX::SimpleMath::Vector2 pos)
		{
			this->text = text;
			this->pos = pos;
		}
	};

	std::unique_ptr<DirectX::SpriteBatch>   m_sprites;       // スプライトバッチ
	std::unique_ptr<DirectX::SpriteFont>    m_font;          // スプライトフォント
	std::list<DebugTextData> m_debugText;					 // デバッグで表示するテキストリスト
	
// メンバー関数
public:
	~Debug();
	void Render();

	// リストに追加
	void DebugRender(char* debugLen, DirectX::SimpleMath::Vector2 debugPos);
	void DebugRender(float debugLen, DirectX::SimpleMath::Vector2 debugPos);
	void DebugRender(DirectX::SimpleMath::Vector2 debugInf, DirectX::SimpleMath::Vector2 debugPos);
	void DebugRender(char* debugLen, float debugInf, DirectX::SimpleMath::Vector2 debugPos);
	void DebugRender(char* debugLen, DirectX::SimpleMath::Vector2 debugInf, DirectX::SimpleMath::Vector2 debugPos);

private:
	Debug();
	std::wstring NumtoWstring(float num);
	std::wstring ChartoWstring(char* text);
};