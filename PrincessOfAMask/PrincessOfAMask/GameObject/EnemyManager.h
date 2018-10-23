#pragma once
#include <list>
#include "..\Utility\SingletonBase.h"
#include "Enemy.h"
class EnemyManager : public SingletonBase<EnemyManager>
{
private:
	// コンストラクタ
	EnemyManager();
	// 敵の消滅
	void RemoveEnemy();
public:
	friend SingletonBase<EnemyManager>;
	// デストラクタ
	~EnemyManager();
	// 更新処理
	void Update();
	// 描画処理
	void Render();
	// 敵の出現
	void PopEnemy(Enemy* enemy);

private:
	// 敵の出現リスト
	std::list<Enemy*> m_enemylist;
	// 消滅する敵のリスト
	std::list<Enemy*> m_removeEnemylist;
};