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
	// シーンパス
	enum ScenePath
	{
		LogoScene,        // ロゴシーン
		TitleScene,       // タイトルシーン
		PlayScene,        // プレイシーン
		
		NumScene          // 総数
	};
	// オブジェクトパス
	enum ObjectPath
	{
		Character,        // キャラ
		UI,               // UI
		Animation,        // アニメーション

		NumObject         // 総数
	};
	// パス文字列
	struct PathLength
	{
		char* scenePath;
		char* objectPath;
	};

	// シーンパスの初期化
	ScenePath InitializeSceneFilePath(int num);
	// オブジェクトパスの初期化
	ObjectPath InitializeObjectFilePath(int num);

	// シーンパスの設定
	char* SetSceneFilePath(ScenePath path);
	// オブジェクトパスの設定
	char* SetObjectFilePath(ObjectPath path);
}