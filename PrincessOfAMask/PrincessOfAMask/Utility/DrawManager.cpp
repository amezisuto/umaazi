//////////////////////////////////////////////////////////////
// File.    DrawManager.cpp
// Summary. DrawManagerClass
// Date.    2018/10/18
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// �C���N���[�h�f�B���N�g��
#include "DrawManager.h"
#include "DeviceResources.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
DrawManager::DrawManager()
{
	// �X�v���C�g�o�b�`�̍쐬
	m_sprites = std::make_unique<DirectX::SpriteBatch>(DX::DeviceResources::SingletonGetInstance().GetD3DDeviceContext());
	// �R�����X�e�[�g�̍쐬 
	m_states = std::make_unique<DirectX::CommonStates>(DX::DeviceResources::SingletonGetInstance().GetD3DDevice());
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
DrawManager::~DrawManager()
{
}

/// <summary>
/// �X�v���C�g�̕`��
/// </summary>
/// <param name="texture"></param>
/// <param name="pos"></param>
void DrawManager::Draw(ID3D11ShaderResourceView * texture, DirectX::SimpleMath::Vector2 pos)
{
	// �X�v���C�g�̕`��
	m_sprites->Begin(DirectX::SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_sprites->Draw(texture, pos);
	m_sprites->End();
}
/// <summary>
/// �X�v���C�g�̕`��(�؂���Ȃ�)
/// </summary>
/// <param name="texture"></param>
/// <param name="pos"></param>
/// <param name="sourceRectangle"></param>
void DrawManager::DrawRect(ID3D11ShaderResourceView * texture, DirectX::SimpleMath::Vector2 pos, RECT const * sourceRectangle)
{
	// �X�v���C�g�̕`��
	m_sprites->Begin(DirectX::SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_sprites->Draw(texture, pos, sourceRectangle);
	m_sprites->End();
}
