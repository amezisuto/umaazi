//シーンマネージャー
#pragma once

#include <list>
#include "SceneBase.h"

class SceneManager
{
public:
	// デストラクタ
	~SceneManager();

	// 実体化
	static SceneManager* GetInstance();

	// 実体の削除
	static void DeleteInstance();

	// 更新
	void Update();

	// 描画
	void Renrer();

	// シーンの追加
	void AddScene(SceneBase* scene);

private:

	// コンストラクタ
	SceneManager();

	// 削除タスクの実行
	void RemoveScene();

private:
	// 自身のポインタ
	static SceneManager* m_instance;

	// シーンの保管庫
	std::list<SceneBase*> m_list;

	// 削除シーン
	std::list<SceneBase*> m_removeList;
};

