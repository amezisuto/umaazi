//////////////////////////////////////////////////////////////
// File.    ObjectBase.h
// Summary. ObjectBaseClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include "../pch.h"

class ObjectBase
{
// メンバー変数
protected:
	DirectX::SimpleMath::Vector2 m_pos;
	DirectX::SimpleMath::Vector2 m_vel;

// メンバー関数
public:
	// コンストラクター
	ObjectBase();
	// デストラクター
	virtual ~ObjectBase();

	// 更新
	virtual bool Update() = 0;
	// 描画
	virtual void Render() = 0;
};