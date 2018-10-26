//////////////////////////////////////////////////////////////
// File.    FilePath.h
// Summary. FilePathClass
// Date.    2018/10/25
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once
#include "../pch.h"

namespace FilePath
{
	enum ScenePath
	{
		LogoScene,        // ���S�V�[��
		TitleScene,       // �^�C�g���V�[��
		PlayScene,        // �v���C�V�[��
		
		NumScene          // ����
	};

	enum ObjectPath
	{
		Character,        // �L����
		UI,               // UI
		Animation,        // �A�j���[�V����

		NumObject         // ����
	};

	// �V�[���p�X�̏�����
	ScenePath InitializeSceneFilePath(int num);
	// �I�u�W�F�N�g�p�X�̏�����
	ObjectPath InitializeObjectFilePath(int num);
}