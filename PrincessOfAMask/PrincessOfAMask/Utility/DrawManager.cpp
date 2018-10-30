//////////////////////////////////////////////////////////////
// File.    DrawManager.cpp
// Summary. DrawManagerClass
// Date.    2018/10/18
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// �C���N���[�h�f�B���N�g��
#include <iostream>
#include <fstream>
#include <sstream>
#include <wchar.h>
#include <shlwapi.h>
#include <tchar.h>

#include "../pch.h"
#include "DrawManager.h"
#include "DeviceResources.h"

#include "FilePath.h"

#pragma comment(lib, "shlwapi.lib")

/// <summary>
/// �R���X�g���N�^
/// </summary>
DrawManager::DrawManager()
{
	// �X�v���C�g�o�b�`�̍쐬
	m_sprites = std::make_unique<DirectX::SpriteBatch>(DX::DeviceResources::SingletonGetInstance().GetD3DDeviceContext());
	// �R�����X�e�[�g�̍쐬 
	m_states = std::make_unique<DirectX::CommonStates>(DX::DeviceResources::SingletonGetInstance().GetD3DDevice());
}
/// <summary>
/// �f�X�g���N�^
/// </summary>
DrawManager::~DrawManager()
{
}

/// <summary>
/// �X�v���C�g�̕`��
/// </summary>
/// <param name="texture"></param>
/// <param name="pos"></param>
void DrawManager::Draw(ID3D11ShaderResourceView * texture, DirectX::SimpleMath::Vector2 pos)
{
	// �X�v���C�g�̕`��
	m_sprites->Begin(DirectX::SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_sprites->Draw(texture, pos);
	m_sprites->End();
}
/// <summary>
/// �X�v���C�g�̕`��(�؂���Ȃ�)
/// </summary>
/// <param name="texture"></param>
/// <param name="pos"></param>
/// <param name="sourceRectangle"></param>
void DrawManager::DrawRect(ID3D11ShaderResourceView * texture, DirectX::SimpleMath::Vector2 pos, RECT const * sourceRectangle)
{
	// �X�v���C�g�̕`��
	m_sprites->Begin(DirectX::SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_sprites->Draw(texture, pos, sourceRectangle);
	m_sprites->End();
}

/// <summary>
/// �e�N�X�`���̕`��
/// </summary>
/// <param name="textureName">�e�N�X�`���̖��O</param>
/// <param name="pos">�`�悷����W</param>
void DrawManager::Draw(char* textureName, DirectX::SimpleMath::Vector2 pos)
{
	// �t�@�C���p�X�ϐ��̏�����
	FilePath::ScenePath sceneFilePath[FilePath::ScenePath::NumScene];
	for (int i = 0; i < FilePath::ScenePath::NumScene; i++)
	{
		sceneFilePath[i] = FilePath::InitializeSceneFilePath(i);
	}
	FilePath::ObjectPath objectFilePath[FilePath::ObjectPath::NumObject];
	for (int i = 0; i < FilePath::ObjectPath::NumObject; i++)
	{
		objectFilePath[i] = FilePath::InitializeObjectFilePath(i);
	}

	std::wstring filePath;

	// �e�N�X�`���t�@�C���̃p�X����
	for (int i = 0; i < FilePath::ScenePath::NumScene; ++i)
	{
		int retval = 0;

		// �V�[���p�X�̐ݒ�
		char* scenePath;
		/*switch (sceneFilePath[i])
		{
		case FilePath::ScenePath::LogoScene:  scenePath = "LogoScene";  break;
		case FilePath::ScenePath::TitleScene: scenePath = "TitleScene"; break;
		case FilePath::ScenePath::PlayScene:  scenePath = "PlayScene";  break;
		}*/
		scenePath = FilePath::SetSceneFilePath(sceneFilePath[i]);

		for (int i = 0; i < FilePath::ObjectPath::NumObject; ++i)
		{
			// �I�u�W�F�N�g�p�X�̐ݒ�
			char* objectPath;
			/*switch (objectFilePath[i])
			{
			case FilePath::ObjectPath::Character: objectPath = "Character"; break;
			case FilePath::ObjectPath::UI:        objectPath = "UI";        break;
			case FilePath::ObjectPath::Animation: objectPath = "Animation"; break;
			}*/
			objectPath = FilePath::SetObjectFilePath(objectFilePath[i]);

			// �������A�����p�X�𐶐�
			std::wstringstream ss;
			ss << "Resources\\" << scenePath << "\\" << objectPath << "\\" << textureName;
			filePath = ss.str();

			// �t�@�C���𔭌������烋�[�v�𔲂���
			retval = PathFileExists(filePath.c_str());
			if (retval == 1)  break;
		}
		if (retval == 1)  break;

		if (i == FilePath::ScenePath::NumScene -1 && retval == 0)
		{
			// �S�t�@�C���T���Ă��e�N�X�`����������Ȃ��ꍇ�̓G���[
			throw std::range_error("Can't fount resource path.");
		}
	}

	// �e�N�X�`���̓ǂݍ���
	DirectX::CreateWICTextureFromFile(DX::DeviceResources::SingletonGetInstance().GetD3DDevice(), filePath.c_str(), nullptr, m_texture.GetAddressOf());

	if (!m_texture)
	{
		// �t�@�C���ǂݍ��ݎ��s
		throw std::range_error("Read failure.");
	}

	// �X�v���C�g�̕`��
	m_sprites->Begin(DirectX::SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_sprites->Draw(m_texture.Get(), pos);
	m_sprites->End();
}
/// <summary>
/// �e�N�X�`���̕`��
/// </summary>
/// <param name="textureName">�e�N�X�`���̖��O</param>
/// <param name="pos">�`�悷����W</param>
/// <param name="sourceRectangle">�؂�����W</param>
void DrawManager::DrawRect(char * textureName, DirectX::SimpleMath::Vector2 pos, RECT const * sourceRectangle)
{
	// �t�@�C���p�X�ϐ��̏�����
	FilePath::ScenePath sceneFilePath[FilePath::ScenePath::NumScene];
	for (int i = 0; i < FilePath::ScenePath::NumScene; i++)
	{
		sceneFilePath[i] = FilePath::InitializeSceneFilePath(i);
	}
	FilePath::ObjectPath objectFilePath[FilePath::ObjectPath::NumObject];
	for (int i = 0; i < FilePath::ObjectPath::NumObject; i++)
	{
		objectFilePath[i] = FilePath::InitializeObjectFilePath(i);
	}

	std::wstring filePath;

	// �e�N�X�`���t�@�C���̃p�X����
	for (int i = 0; i < FilePath::ScenePath::NumScene; ++i)
	{
		int retval = 0;

		// �V�[���p�X�̐ݒ�
		char* scenePath;
		switch (sceneFilePath[i])
		{
		case FilePath::ScenePath::LogoScene:  scenePath = "LogoScene";  break;
		case FilePath::ScenePath::TitleScene: scenePath = "TitleScene"; break;
		case FilePath::ScenePath::PlayScene:  scenePath = "PlayScene";  break;
		}
		for (int i = 0; i < FilePath::ObjectPath::NumObject; ++i)
		{
			// �I�u�W�F�N�g�p�X�̐ݒ�
			char* objectPath;
			switch (objectFilePath[i])
			{
			case FilePath::ObjectPath::Character: objectPath = "Character"; break;
			case FilePath::ObjectPath::UI:        objectPath = "UI";        break;
			case FilePath::ObjectPath::Animation: objectPath = "Animation"; break;
			}

			// �������A�����p�X�𐶐�
			std::wstringstream ss;
			ss << "Resources\\" << scenePath << "\\" << objectPath << "\\" << textureName;
			filePath = ss.str();

			// �t�@�C���𔭌������烋�[�v�𔲂���
			retval = PathFileExists(filePath.c_str());
			if (retval == 1)  break;
		}
		if (retval == 1)  break;

		if (i == FilePath::ScenePath::NumScene - 1 && retval == 0)
		{
			// �S�t�@�C���T���Ă��e�N�X�`����������Ȃ��ꍇ�̓G���[
			throw std::range_error("Can't fount resource path.");
		}
	}

	// �e�N�X�`���̓ǂݍ���
	DirectX::CreateWICTextureFromFile(DX::DeviceResources::SingletonGetInstance().GetD3DDevice(), filePath.c_str(), nullptr, m_texture.GetAddressOf());

	if (!m_texture)
	{
		// �t�@�C���ǂݍ��ݎ��s
		throw std::range_error("Read failure.");
	}

	// �X�v���C�g�̕`��
	m_sprites->Begin(DirectX::SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_sprites->Draw(m_texture.Get(), pos, sourceRectangle);
	m_sprites->End();
}
