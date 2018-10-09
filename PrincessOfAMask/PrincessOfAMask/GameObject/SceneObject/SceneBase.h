//////////////////////////////////////////////////////////////
// File.    SceneBase.h
// Summary. SceneBaseClass
// Date.    2018/10/09
// Auther.  Eijirou Tsujii
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include "../../pch.h"

class SceneBase
{
public:
	// コンストラクター
	SceneBase();
	// デストラクター
	~SceneBase();

	// 描画
	virtual bool Update() = 0;
	// 更新
	virtual void Render() = 0;
private:
};

