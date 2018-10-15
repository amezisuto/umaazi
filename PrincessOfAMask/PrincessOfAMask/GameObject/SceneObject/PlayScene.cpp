//////////////////////////////////////////////////////////////
// File.    PlayScene.cpp
// Summary. PlaySceneClass
// Date.    2018/10/09
// Auther.  Eijirou Tsujii
//////////////////////////////////////////////////////////////

// �C���N���[�h�f�B���N�g��
#include "PlayScene.h"
#include "../../Utility/DeviceResources.h"

// using�f�B���N�g��
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;


/// <summary>
/// �R���X�g���N�^
/// </summary>
PlayScene::PlayScene()
{
	ID3D11Device* device = DX::DeviceResources::SingletonGetInstance().GetD3DDevice();
	ID3D11DeviceContext* context = DX::DeviceResources::SingletonGetInstance().GetD3DDeviceContext();
	RECT outputsize = DX::DeviceResources::SingletonGetInstance().GetOutputSize();

	// �X�v���C�g�o�b�`�̍쐬
	m_sprites = std::make_unique<SpriteBatch>(context);

	// �X�v���C�g�t�H���g�̍쐬
	m_font = std::make_unique<SpriteFont>(device, L"SegoeUI_18.spritefont");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
PlayScene::~PlayScene()
{
	//�Ȃɂ����Ȃ�
}

/// <summary>
/// �X�V����
/// </summary>
/// <returns>�K�v���ǂ���</returns>
bool PlayScene::Update()
{
	return true;
}

/// <summary>
/// �`�揈��
/// </summary>
void PlayScene::Render()
{
	//�f�o�b�O�e�L�X�g
	m_sprites->Begin();

	m_font->DrawString(m_sprites.get(), L"PlayScene", Vector2(10.0f, 10.0f));

	m_sprites->End();
}
