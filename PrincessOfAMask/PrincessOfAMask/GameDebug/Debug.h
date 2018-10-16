//////////////////////////////////////////////////////////////
// File.    Debug.h
// Summary. DebugClass
// Date.    2018/10/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include <iostream>
#include <fstream>
#include <sstream>

#include "../pch.h"
#include "../Utility/SingletonBase.h"

class Debug : public SingletonBase<Debug>
{
// メンバー変数
public:
	friend SingletonBase<Debug>;
private:
	std::unique_ptr<DirectX::SpriteBatch>   m_sprites;       // スプライトバッチ
	std::unique_ptr<DirectX::SpriteFont>    m_font;          // スプライトフォント

// メンバー関数
public:
	~Debug();

	// デバッグ描画
	void DebugRender(char* debugLen, DirectX::SimpleMath::Vector2 debugPos);

private:
	Debug();

};