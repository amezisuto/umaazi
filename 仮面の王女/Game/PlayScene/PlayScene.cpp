#include "PlayScene.h"
#include "..\DeviceManager.h"


//���O���
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;


/// <summary>
/// �R���X�g���N�^
/// </summary>
PlayScene::PlayScene()
{
	ID3D11Device* device = System::DeviceManager::GetInstance().GetDevice();
	ID3D11DeviceContext* context = System::DeviceManager::GetInstance().GetContext();
	RECT outputsize = System::DeviceManager::GetInstance().GetOutputSize();

	// �X�v���C�g�o�b�`�̍쐬
	m_sprites = std::make_unique< SpriteBatch>(context);

	// �X�v���C�g�t�H���g�̍쐬
	m_font = std::make_unique< SpriteFont>(device, L"SegoeUI_18.spritefont");
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
