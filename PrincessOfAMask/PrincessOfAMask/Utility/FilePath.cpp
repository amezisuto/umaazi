//////////////////////////////////////////////////////////////
// File.    FilePath.cpp
// Summary. FilePathClass
// Date.    2018/10/25
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// �C���N���[�h�f�B���N�g��
#include "FilePath.h"

/// <summary>
/// �V�[���p�X�̏�����
/// </summary>
/// <param name="num">�p�XID</param>
/// <returns>ID�ɉ������p�X</returns>
FilePath::ScenePath FilePath::InitializeSceneFilePath(int num)
{
	FilePath::ScenePath path[1];
	switch (num)
	{
	case ScenePath::LogoScene:  path[0] = ScenePath::LogoScene;   break;
	case ScenePath::TitleScene: path[0] = ScenePath::TitleScene;  break;
	case ScenePath::PlayScene:  path[0] = ScenePath::PlayScene;   break;
	}
	return path[0];

}
/// <summary>
/// �I�u�W�F�N�g�p�X�̏�����
/// </summary>
/// <param name="num">�p�XID</param>
/// <returns>ID�ɉ������p�X</returns>
FilePath::ObjectPath FilePath::InitializeObjectFilePath(int num)
{
	FilePath::ObjectPath path[1];
	switch (num)
	{
	case ObjectPath::Character: path[0] = ObjectPath::Character; break;
	case ObjectPath::UI:        path[0] = ObjectPath::UI;        break;
	case ObjectPath::Animation: path[0] = ObjectPath::Animation; break;
	}
	return path[0];
}

/// <summary>
/// �V�[���p�X�̕������Ԃ�
/// </summary>
/// <param name="path">�V�[���p�X�̖��O</param>
/// <returns>�p�X�̕�����</returns>
char* FilePath::SetSceneFilePath(ScenePath path)
{
	PathLength pathLen;

	switch (path)
	{
	case FilePath::ScenePath::LogoScene:  pathLen.scenePath = "LogoScene";  break;
	case FilePath::ScenePath::TitleScene: pathLen.scenePath = "TitleScene"; break;
	case FilePath::ScenePath::PlayScene:  pathLen.scenePath = "PlayScene";  break;
	}

	return pathLen.scenePath;
}
/// <summary>
/// �I�u�W�F�N�g�p�X�̕������Ԃ�
/// </summary>
/// <param name="path">�I�u�W�F�N�g�p�X�̖��O</param>
/// <returns>�p�X�̕�����</returns>
char* FilePath::SetObjectFilePath(ObjectPath path)
{
	PathLength pathLen;

	switch (path)
	{
	case FilePath::ObjectPath::Character: pathLen.objectPath = "Character"; break;
	case FilePath::ObjectPath::UI:        pathLen.objectPath = "UI";        break;
	case FilePath::ObjectPath::Animation: pathLen.objectPath = "Animation"; break;
	}

	return pathLen.objectPath;
}
