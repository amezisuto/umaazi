#pragma once

#include "..\SceneManager\SceneBase.h"

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
	// スプライトバッチ
	std::unique_ptr<DirectX::SpriteBatch> m_sprites;

	// スプライトフォント
	std::unique_ptr<DirectX::SpriteFont> m_font;
};