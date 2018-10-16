//////////////////////////////////////////////////////////////
// File.    Debug.cpp
// Summary. DebugClass
// Date.    2018/10/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////
 
// �C���N���[�h�f�B���N�g��
#include "Debug.h"
#include "../Utility/DeviceResources.h"

// using�f�B���N�g��
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

/// <summary>
/// �R���X�g���N�^
/// </summary>
Debug::Debug()
{
	// �X�v���C�g�o�b�`�̍쐬
	m_sprites = std::make_unique<SpriteBatch>(DX::DeviceResources::SingletonGetInstance().GetD3DDeviceContext());

	// �X�v���C�g�t�H���g�̍쐬
	m_font = std::make_unique<SpriteFont>(DX::DeviceResources::SingletonGetInstance().GetD3DDevice(), L"SegoeUI_18.spritefont");
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
Debug::~Debug()
{
}

/// <summary>
/// �f�o�b�O�`��
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
