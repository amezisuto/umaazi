//////////////////////////////////////////////////////////////
// File.    DrawManager.h
// Summary. DrawManagerClass
// Date.    2018/10/18
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include "../pch.h"
#include "SingletonBase.h"

class DrawManager:public SingletonBase<DrawManager>
{
// �����o�[�ϐ�
public:
	
private:
	std::unique_ptr<DirectX::SpriteBatch>                m_sprites;    // �X�v���C�g�o�b�`
	std::unique_ptr<DirectX::CommonStates>               m_states;     // �R�����X�e�[�g

	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>     m_texture;    // �e�N�X�`���n���h��

// �����o�[�֐�
public:
	friend SingletonBase<DrawManager>;

	// �f�X�g���N�^
	~DrawManager();

	// �X�v���C�g�̕`��
	void Draw(ID3D11ShaderResourceView* texture, DirectX::SimpleMath::Vector2 pos);
	void DrawRect(ID3D11ShaderResourceView* texture, DirectX::SimpleMath::Vector2 pos, RECT const* sourceRectangle);

	void Draw(char* textureName, DirectX::SimpleMath::Vector2 pos);
	void DrawRect(char* textureName, DirectX::SimpleMath::Vector2 pos, RECT const* sourceRectangle);
private:
	// �R���X�g���N�^
	DrawManager();
};