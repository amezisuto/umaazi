//////////////////////////////////////////////////////////////
// File.    DrawManager.cpp
// Summary. DrawManagerClass
// Date.    2018/10/18
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// インクルードディレクトリ
#include "DrawManager.h"
#include "DeviceResources.h"

/// <summary>
/// コンストラクタ
/// </summary>
DrawManager::DrawManager()
{
	// スプライトバッチの作成
	m_sprites = std::make_unique<DirectX::SpriteBatch>(DX::DeviceResources::SingletonGetInstance().GetD3DDeviceContext());
	// コモンステートの作成 
	m_states = std::make_unique<DirectX::CommonStates>(DX::DeviceResources::SingletonGetInstance().GetD3DDevice());
}
/// <summary>
/// デストラクタ
/// </summary>
DrawManager::~DrawManager()
{
}

/// <summary>
/// スプライトの描画
/// </summary>
/// <param name="texture"></param>
/// <param name="pos"></param>
void DrawManager::Draw(ID3D11ShaderResourceView * texture, DirectX::SimpleMath::Vector2 pos)
{
	// スプライトの描画
	m_sprites->Begin(DirectX::SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_sprites->Draw(texture, pos);
	m_sprites->End();
}
/// <summary>
/// スプライトの描画(切り取りなし)
/// </summary>
/// <param name="texture"></param>
/// <param name="pos"></param>
/// <param name="sourceRectangle"></param>
void DrawManager::DrawRect(ID3D11ShaderResourceView * texture, DirectX::SimpleMath::Vector2 pos, RECT const * sourceRectangle)
{
	// スプライトの描画
	m_sprites->Begin(DirectX::SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_sprites->Draw(texture, pos, sourceRectangle);
	m_sprites->End();
}
