#pragma once
#include "EnemyStates.h"
class Enemy
{
public:
	// コンストラクタ
	Enemy(EnemyType enemytype, EnemyStates states);
	// デストラクタ
	~Enemy();
	// 更新処理
	bool Update();
	// 描画処理
	void Render();
private:
	// 生きているかどうかの判定
	bool AliveEnemy();
private:
	// エネミーステータス
	EnemyStates m_states;
	// 敵の種類
	EnemyType m_enemyType;
};