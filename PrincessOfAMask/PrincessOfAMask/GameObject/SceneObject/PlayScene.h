//////////////////////////////////////////////////////////////
// File.    PlayScene.h
// Summary. PlaySceneClass
// Date.    2018/10/09
// Auther.  Eijirou Tsujii
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include "SceneBase.h"

class PlayScene : public SceneBase
{
public:
	//コンストラクタ
	PlayScene();
	
	//デストラクタ
	~PlayScene();

	//更新処理
	bool Update() override;
	
	//描画処理
	void Render() override;
private:
};