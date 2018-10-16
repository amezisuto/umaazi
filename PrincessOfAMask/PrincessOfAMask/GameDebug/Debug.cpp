//////////////////////////////////////////////////////////////
// File.    Debug.cpp
// Summary. DebugClass
// Date.    2018/10/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////
 
// インクルードディレクトリ
#include "Debug.h"
#include "../Utility/DeviceResources.h"

// usingディレクトリ
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

/// <summary>
/// コンストラクタ
/// </summary>
Debug::Debug()
{
	// スプライトバッチの作成
	m_sprites = std::make_unique<SpriteBatch>(DX::DeviceResources::SingletonGetInstance().GetD3DDeviceContext());

	// スプライトフォントの作成
	m_font = std::make_unique<SpriteFont>(DX::DeviceResources::SingletonGetInstance().GetD3DDevice(), L"SegoeUI_18.spritefont");
}
/// <summary>
/// デストラクタ
/// </summary>
Debug::~Debug()
{
}

/// <summary>
/// デバッグ描画
/// </summary>
/// <param name="debugLen"></param>
/// <param name="debugPos"></param>
void Debug::DebugRender(char* debugLen, DirectX::SimpleMath::Vector2 debugPos)
{
	wstringstream ss;
	ss << debugLen;
	wstring str = ss.str();

	m_sprites->Begin();
	m_font->DrawString(m_sprites.get(), str.c_str(), debugPos);
	m_sprites->End();
}
