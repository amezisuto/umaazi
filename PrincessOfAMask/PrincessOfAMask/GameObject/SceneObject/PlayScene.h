//////////////////////////////////////////////////////////////
// File.    PlayScene.h
// Summary. PlaySceneClass
// Date.    2018/10/09
// Auther.  Eijirou Tsujii
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
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
};