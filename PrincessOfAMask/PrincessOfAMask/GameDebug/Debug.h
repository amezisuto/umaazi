//////////////////////////////////////////////////////////////
// File.    Debug.h
// Summary. DebugClass
// Date.    2018/10/15
// Auther.  Miu Himi �F Eijirou Tsujii
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include <iostream>
#include <fstream>
#include <sstream>

#include "../pch.h"
#include "../Utility/SingletonBase.h"
#include <list>

// �f�o�b�O
#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


class Debug : public SingletonBase<Debug>
{
// �����o�[�ϐ�
public:
	friend SingletonBase<Debug>;
private:
	// �L�[���̍\����
	struct DebugTextData
	{
		std::wstring text;
		DirectX::SimpleMath::Vector2 pos;
		DebugTextData(std::wstring text,DirectX::SimpleMath::Vector2 pos)
		{
			this->text = text;
			this->pos = pos;
		}
	};

	std::unique_ptr<DirectX::SpriteBatch>   m_sprites;       // �X�v���C�g�o�b�`
	std::unique_ptr<DirectX::SpriteFont>    m_font;          // �X�v���C�g�t�H���g
	std::list<DebugTextData> m_debugText;					 // �f�o�b�O�ŕ\������e�L�X�g���X�g
	
// �����o�[�֐�
public:
	~Debug();
	void Render();

	// ���X�g�ɒǉ�
	void DebugRender(char* debugLen, DirectX::SimpleMath::Vector2 debugPos);
	void DebugRender(float debugLen, DirectX::SimpleMath::Vector2 debugPos);
	void DebugRender(DirectX::SimpleMath::Vector2 debugInf, DirectX::SimpleMath::Vector2 debugPos);
	void DebugRender(char* debugLen, float debugInf, DirectX::SimpleMath::Vector2 debugPos);
	void DebugRender(char* debugLen, DirectX::SimpleMath::Vector2 debugInf, DirectX::SimpleMath::Vector2 debugPos);

private:
	Debug();
	std::wstring NumtoWstring(float num);
	std::wstring ChartoWstring(char* text);
};