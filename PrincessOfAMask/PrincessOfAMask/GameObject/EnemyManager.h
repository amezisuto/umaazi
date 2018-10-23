#pragma once
#include <list>
#include "..\Utility\SingletonBase.h"
#include "Enemy.h"
class EnemyManager : public SingletonBase<EnemyManager>
{
private:
	// �R���X�g���N�^
	EnemyManager();
	// �G�̏���
	void RemoveEnemy();
public:
	friend SingletonBase<EnemyManager>;
	// �f�X�g���N�^
	~EnemyManager();
	// �X�V����
	void Update();
	// �`�揈��
	void Render();
	// �G�̏o��
	void PopEnemy(Enemy* enemy);

private:
	// �G�̏o�����X�g
	std::list<Enemy*> m_enemylist;
	// ���ł���G�̃��X�g
	std::list<Enemy*> m_removeEnemylist;
};