#include "EnemyManager.h"

using namespace std;

/// <summary>
/// コンストラクタ
/// </summary>
EnemyManager::EnemyManager()
{
	// なにもしない
}

/// <summary>
/// デストラクタ
/// </summary>
EnemyManager::~EnemyManager()
{
	// なにもしない
}

/// <summary>
/// 更新処理
/// </summary>
void EnemyManager::Update()
{
	// 消す予定のシーン削除
	RemoveEnemy();

	for (list<Enemy*>::iterator it = m_enemylist.begin(); it != m_enemylist.end(); it++)
	{
		if (!(*it)->Update())
		{
			// 削除予約をする
			m_removeEnemylist.push_back((*it));
		}
	}
}

/// <summary>
/// 描画処理
/// </summary>
void EnemyManager::Render()
{
	for (std::list<Enemy*>::iterator it = m_enemylist.begin(); it != m_enemylist.end(); it++)
	{
		(*it)->Render();
	}
}

/// <summary>
/// エネミーを出現リストに追加
/// </summary>
/// <param name="enemy">エネミー</param>
void EnemyManager::PopEnemy(Enemy* enemy)
{
	m_enemylist.push_back(enemy);
}

/// <summary>
/// エネミー
/// </summary>
void EnemyManager::RemoveEnemy()
{
	for (std::list<Enemy*>::iterator it = m_removeEnemylist.begin(); it != m_removeEnemylist.end(); it++)
	{
		m_enemylist.remove((*it));
		delete (*it);
		(*it) = nullptr;
	}
	// 削除リストを空にする
	m_removeEnemylist.clear();
}
