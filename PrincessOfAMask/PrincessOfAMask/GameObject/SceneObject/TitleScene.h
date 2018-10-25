//////////////////////////////////////////////////////////////
// File.    PlayScene.h
// Summary. PlaySceneClass
// Date.    2018/10/09
// Auther.  Eijirou Tsujii
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include "SceneBase.h"

class TitleScene : public SceneBase
{
public:
	//コンストラクタ
	TitleScene();

	//デストラクタ
	~TitleScene();

	//更新処理
	bool Update() override;

	//描画処理
	void Render() override;
private:
};