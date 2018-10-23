//////////////////////////////////////////////////////////////
// File.    PlayScene.cpp
// Summary. PlaySceneClass
// Date.    2018/10/09
// Auther.  Eijirou Tsujii
//////////////////////////////////////////////////////////////

// インクルードディレクトリ
#include "PlayScene.h"
#include "../../Utility/DeviceResources.h"

#include "../../GameDebug/Debug.h"

#include "..\..\SaveData\SaveManager.h"

#include "..\EnemyStates.h"

#include "..\..\Utility\InputManager.h"

#include "..\EnemyManager.h"

#include "..\Enemy.h"
// usingディレクトリ
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;


/// <summary>
/// コンストラクタ
/// </summary>
PlayScene::PlayScene()
{
	// なにもしない
}

/// <summary>
/// デストラクタ
/// </summary>
PlayScene::~PlayScene()
{
	// なにもしない
}

/// <summary>
/// 更新処理
/// </summary>
/// <returns>必要かどうか</returns>
bool PlayScene::Update()
{
	if (InputManager::SingletonGetInstance().GetKeyState().A)
	{
		Enemy* enemy = new Enemy(EnemyType::Slime, EnemyStates("slime", 1, 1, 60, 1, 1, 1));
		EnemyManager::SingletonGetInstance().PopEnemy(enemy);
	}

	EnemyManager::SingletonGetInstance().Update();

	return true;
}

/// <summary>
/// 描画処理
/// </summary>
void PlayScene::Render()
{
	EnemyManager::SingletonGetInstance().Render();
}
