//////////////////////////////////////////////////////////////
// File.    PlayScene.cpp
// Summary. PlaySceneClass
// Date.    2018/10/09
// Auther.  Eijirou Tsujii
//////////////////////////////////////////////////////////////

// �C���N���[�h�f�B���N�g��
#include "PlayScene.h"
#include "../../Utility/DeviceResources.h"

#include "../../GameDebug/Debug.h"

#include "..\..\SaveData\SaveManager.h"

#include "..\EnemyStates.h"

#include "..\..\Utility\InputManager.h"

#include "..\EnemyManager.h"

#include "..\Enemy.h"
// using�f�B���N�g��
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;


/// <summary>
/// �R���X�g���N�^
/// </summary>
PlayScene::PlayScene()
{
	// �Ȃɂ����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
PlayScene::~PlayScene()
{
	// �Ȃɂ����Ȃ�
}

/// <summary>
/// �X�V����
/// </summary>
/// <returns>�K�v���ǂ���</returns>
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
/// �`�揈��
/// </summary>
void PlayScene::Render()
{
	EnemyManager::SingletonGetInstance().Render();
}
