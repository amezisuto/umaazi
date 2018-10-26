//////////////////////////////////////////////////////////////
// File.    FilePath.cpp
// Summary. FilePathClass
// Date.    2018/10/25
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// インクルードディレクトリ
#include "FilePath.h"

/// <summary>
/// シーンパスの初期化
/// </summary>
/// <param name="num">パスID</param>
/// <returns>IDに沿ったパス</returns>
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
/// オブジェクトパスの初期化
/// </summary>
/// <param name="num">パスID</param>
/// <returns>IDに沿ったパス</returns>
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
