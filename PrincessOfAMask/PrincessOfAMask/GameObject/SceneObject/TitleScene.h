//////////////////////////////////////////////////////////////
// File.    PlayScene.h
// Summary. PlaySceneClass
// Date.    2018/10/09
// Auther.  Eijirou Tsujii
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include "SceneBase.h"

class TitleScene : public SceneBase
{
public:
	//�R���X�g���N�^
	TitleScene();

	//�f�X�g���N�^
	~TitleScene();

	//�X�V����
	bool Update() override;

	//�`�揈��
	void Render() override;
private:
};