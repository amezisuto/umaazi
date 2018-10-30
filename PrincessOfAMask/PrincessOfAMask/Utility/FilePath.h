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
	// �V�[���p�X
	enum ScenePath
	{
		LogoScene,        // ���S�V�[��
		TitleScene,       // �^�C�g���V�[��
		PlayScene,        // �v���C�V�[��
		
		NumScene          // ����
	};
	// �I�u�W�F�N�g�p�X
	enum ObjectPath
	{
		Character,        // �L����
		UI,               // UI
		Animation,        // �A�j���[�V����

		NumObject         // ����
	};
	// �p�X������
	struct PathLength
	{
		char* scenePath;
		char* objectPath;
	};

	// �V�[���p�X�̏�����
	ScenePath InitializeSceneFilePath(int num);
	// �I�u�W�F�N�g�p�X�̏�����
	ObjectPath InitializeObjectFilePath(int num);

	// �V�[���p�X�̐ݒ�
	char* SetSceneFilePath(ScenePath path);
	// �I�u�W�F�N�g�p�X�̐ݒ�
	char* SetObjectFilePath(ObjectPath path);
}