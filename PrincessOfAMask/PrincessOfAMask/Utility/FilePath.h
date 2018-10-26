//////////////////////////////////////////////////////////////
// File.    FilePath.h
// Summary. FilePathClass
// Date.    2018/10/25
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once
#include "../pch.h"

namespace FilePath
{
	enum ScenePath
	{
		LogoScene,        // ロゴシーン
		TitleScene,       // タイトルシーン
		PlayScene,        // プレイシーン
		
		NumScene          // 総数
	};

	enum ObjectPath
	{
		Character,        // キャラ
		UI,               // UI
		Animation,        // アニメーション

		NumObject         // 総数
	};

	// シーンパスの初期化
	ScenePath InitializeSceneFilePath(int num);
	// オブジェクトパスの初期化
	ObjectPath InitializeObjectFilePath(int num);
}