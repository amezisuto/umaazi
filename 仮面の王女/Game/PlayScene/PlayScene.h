#pragma once

#include "..\SceneManager\SceneBase.h"

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