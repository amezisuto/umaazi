//////////////////////////////////////////////////////////////
// File.    Game.h
// Summary. GameClass
// Date.    2018/09/26
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// �C���N���[�h�f�B���N�g��
#include <iostream>
#include <fstream>
#include <sstream>

#include "DeviceResources.h"
#include "StepTimer.h"
#include "GameObject/SceneObject/SceneManager.h"

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game : public DX::IDeviceNotify
{
// �����o�[�ϐ�
public:
	DX::StepTimer                            m_timer;               // Rendering loop timer.

	std::unique_ptr<DirectX::CommonStates>   m_states;              // �R�����X�e�[�g
	std::unique_ptr<DirectX::SpriteBatch>    m_sprites;             // �X�v���C�g�o�b�`
	std::unique_ptr<DirectX::SpriteFont>     m_font;                // �X�v���C�g�t�H���g

	DirectX::SimpleMath::Matrix              m_view;                // �r���[�s��
	DirectX::SimpleMath::Matrix              m_projection;          // �ˉe�s��

private:

// �����o�[�֐�
public:
	// Constructor
    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowMoved();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

	// Getter
	// �R�����X�e�[�g���擾����
	DirectX::CommonStates* GetState() { return m_states.get(); };
	// �r���[�s����擾����
	const DirectX::SimpleMath::Matrix& GetView() { return m_view; }
	// �ˉe�s����擾����
	const DirectX::SimpleMath::Matrix& GetProjection() { return m_projection; }

private:
    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

};