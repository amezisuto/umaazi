#include "Enemy.h"
#include "..\GameDebug\Debug.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="enemytype">�G�l�~�[�̎��</param>
/// <param name="states">�G�l�~�[�̃X�e�[�^�X</param>
Enemy::Enemy(EnemyType enemytype, EnemyStates states)
:m_enemyType(enemytype)
,m_states(states)
{
	//�Ȃɂ����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Enemy::~Enemy()
{
	//�Ȃɂ����Ȃ�
}

/// <summary>
/// �G�̍X�V����
/// </summary>
/// <returns>�G�l�~�[�������Ă��邩�ǂ���</returns>
bool Enemy::Update()
{
	Debug::SingletonGetInstance().DebugRender(m_states.Name,Vector2(10,(float)m_states.Hp));
	m_states.Hp--;

	return AliveEnemy();
}

/// <summary>
/// �G�l�~�[�̕`�揈��
/// </summary>
void Enemy::Render()
{

}

/// <summary>
/// �G�l�~�[�������Ă��邩�ǂ����̔���
/// </summary>
/// <returns>�G�l�~�[�������Ă��邩�ǂ���</returns>
bool Enemy::AliveEnemy()
{
	if (m_states.Hp <= 0)
	{
		return false;
	}
	return true;
}
