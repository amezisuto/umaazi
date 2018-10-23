#include "Enemy.h"
#include "..\GameDebug\Debug.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="enemytype">エネミーの種類</param>
/// <param name="states">エネミーのステータス</param>
Enemy::Enemy(EnemyType enemytype, EnemyStates states)
:m_enemyType(enemytype)
,m_states(states)
{
	//なにもしない
}

/// <summary>
/// デストラクタ
/// </summary>
Enemy::~Enemy()
{
	//なにもしない
}

/// <summary>
/// 敵の更新処理
/// </summary>
/// <returns>エネミーが生きているかどうか</returns>
bool Enemy::Update()
{
	Debug::SingletonGetInstance().DebugRender(m_states.Name,Vector2(10,(float)m_states.Hp));
	m_states.Hp--;

	return AliveEnemy();
}

/// <summary>
/// エネミーの描画処理
/// </summary>
void Enemy::Render()
{

}

/// <summary>
/// エネミーが生きているかどうかの判定
/// </summary>
/// <returns>エネミーが生きているかどうか</returns>
bool Enemy::AliveEnemy()
{
	if (m_states.Hp <= 0)
	{
		return false;
	}
	return true;
}
