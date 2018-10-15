//////////////////////////////////////////////////////////////
// File.    Game.h
// Summary. GameClass
// Date.    2018/09/26
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// インクルードディレクトリ
#include <iostream>
#include <fstream>
#include <sstream>

#include "Utility/DeviceResources.h"
#include "StepTimer.h"
#include "GameObject/SceneObject/SceneManager.h"

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game : public DX::IDeviceNotify
{
// メンバー変数
public:
	DX::StepTimer                            m_timer;               // Rendering loop timer.

	std::unique_ptr<DirectX::CommonStates>   m_states;              // コモンステート
	std::unique_ptr<DirectX::SpriteBatch>    m_sprites;             // スプライトバッチ
	std::unique_ptr<DirectX::SpriteFont>     m_font;                // スプライトフォント

	DirectX::SimpleMath::Matrix              m_view;                // ビュー行列
	DirectX::SimpleMath::Matrix              m_projection;          // 射影行列

private:

// メンバー関数
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
	// コモンステートを取得する
	DirectX::CommonStates* GetState() { return m_states.get(); };
	// ビュー行列を取得する
	const DirectX::SimpleMath::Matrix& GetView() { return m_view; }
	// 射影行列を取得する
	const DirectX::SimpleMath::Matrix& GetProjection() { return m_projection; }

private:
    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

};