//////////////////////////////////////////////////////////////
// File.    Debug.h
// Summary. DebugClass
// Date.    2018/10/15
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include <iostream>
#include <fstream>
#include <sstream>

#include "../pch.h"
#include "../Utility/SingletonBase.h"

class Debug : public SingletonBase<Debug>
{
// �����o�[�ϐ�
public:
	friend SingletonBase<Debug>;
private:
	std::unique_ptr<DirectX::SpriteBatch>   m_sprites;       // �X�v���C�g�o�b�`
	std::unique_ptr<DirectX::SpriteFont>    m_font;          // �X�v���C�g�t�H���g

// �����o�[�֐�
public:
	~Debug();

	// �f�o�b�O�`��
	void DebugRender(char* debugLen, DirectX::SimpleMath::Vector2 debugPos);

private:
	Debug();

};