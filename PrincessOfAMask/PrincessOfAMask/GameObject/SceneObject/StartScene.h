#pragma once
#include "SceneManager.h"
#include "TitleScene.h"
#include "PlayScene.h"
void StartScene()
{
	//PlayScene* play = new PlayScene();
	TitleScene * title = new TitleScene();
	SceneManager::GetInstance()->AddScene(title);
}