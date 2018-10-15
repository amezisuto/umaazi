//////////////////////////////////////////////////////////////
// File.    PlayScene.cpp
// Summary. PlaySceneClass
// Date.    2018/10/09
// Auther.  Eijirou Tsujii
//////////////////////////////////////////////////////////////

// インクルードディレクトリ
#include "PlayScene.h"
#include "../../Utility/DeviceResources.h"

// usingディレクトリ
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;


/// <summary>
/// コンストラクタ
/// </summary>
PlayScene::PlayScene()
{
	ID3D11Device* device = DX::DeviceResources::SingletonGetInstance().GetD3DDevice();
	ID3D11DeviceContext* context = DX::DeviceResources::SingletonGetInstance().GetD3DDeviceContext();
	RECT outputsize = DX::DeviceResources::SingletonGetInstance().GetOutputSize();

	// スプライトバッチの作成
	m_sprites = std::make_unique<SpriteBatch>(context);

	// スプライトフォントの作成
	m_font = std::make_unique<SpriteFont>(device, L"SegoeUI_18.spritefont");
}

/// <summary>
/// デストラクタ
/// </summary>
PlayScene::~PlayScene()
{
	//なにもしない
}

/// <summary>
/// 更新処理
/// </summary>
/// <returns>必要かどうか</returns>
bool PlayScene::Update()
{
	return true;
}

/// <summary>
/// 描画処理
/// </summary>
void PlayScene::Render()
{
	//デバッグテキスト
	m_sprites->Begin();

	m_font->DrawString(m_sprites.get(), L"PlayScene", Vector2(10.0f, 10.0f));

	m_sprites->End();
}
