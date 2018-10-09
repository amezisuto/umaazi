//////////////////////////////////////////////////////////////
// File.    PlayScene.h
// Summary. PlaySceneClass
// Date.    2018/10/09
// Auther.  Eijirou Tsujii
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include "../../pch.h"
#include "SceneBase.h"

class PlayScene : public SceneBase
{
public:
	//�R���X�g���N�^
	PlayScene();
	
	//�f�X�g���N�^
	~PlayScene();

	//�X�V����
	bool Update() override;
	
	//�`�揈��
	void Render() override;
private:
	// �X�v���C�g�o�b�`
	std::unique_ptr<DirectX::SpriteBatch> m_sprites;

	// �X�v���C�g�t�H���g
	std::unique_ptr<DirectX::SpriteFont> m_font;
};