//////////////////////////////////////////////////////////////
// File.    DrawManager.h
// Summary. DrawManagerClass
// Date.    2018/10/18
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include "../pch.h"
#include "SingletonBase.h"

class DrawManager:public SingletonBase<DrawManager>
{
// メンバー変数
public:
	
private:
	std::unique_ptr<DirectX::SpriteBatch>     m_sprites;    // スプライトバッチ
	std::unique_ptr<DirectX::CommonStates>    m_states;     // コモンステート

// メンバー関数
public:
	friend SingletonBase<DrawManager>;

	// デストラクタ
	~DrawManager();

	// スプライトの描画
	void Draw(ID3D11ShaderResourceView* texture, DirectX::SimpleMath::Vector2 pos);
	void DrawRect(ID3D11ShaderResourceView* texture, DirectX::SimpleMath::Vector2 pos, RECT const* sourceRectangle);
private:
	// コンストラクタ
	DrawManager();
};