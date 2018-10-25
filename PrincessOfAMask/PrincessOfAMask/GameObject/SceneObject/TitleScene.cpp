#include "TitleScene.h"
#include "PlayScene.h"
#include "../../GameDebug/Debug.h"
#include "..\..\Utility\InputManager.h"
#include "..\..\SaveData\SaveManager.h"
#include "..\Player.h"
#include "SceneManager.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

TitleScene::TitleScene()
{
	// ‚È‚É‚à‚µ‚È‚¢
}

TitleScene::~TitleScene()
{
	// ‚È‚É‚à‚µ‚È‚¢
}

bool TitleScene::Update()
{
	if (InputManager::SingletonGetInstance().GetKeyState().Space)
	{
 		SaveManager::SingletonGetInstance().LoadSave();

		PlayScene* play = new PlayScene();
		SceneManager::GetInstance()->AddScene(play);
		return false;
	}

	return true;
}

void TitleScene::Render()
{
	Debug::SingletonGetInstance().DebugRender("TitleScene", Vector2(10, 10));
}
