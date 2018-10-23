#pragma once
#include "EnemyStates.h"
class Enemy
{
public:
	// �R���X�g���N�^
	Enemy(EnemyType enemytype, EnemyStates states);
	// �f�X�g���N�^
	~Enemy();
	// �X�V����
	bool Update();
	// �`�揈��
	void Render();
private:
	// �����Ă��邩�ǂ����̔���
	bool AliveEnemy();
private:
	// �G�l�~�[�X�e�[�^�X
	EnemyStates m_states;
	// �G�̎��
	EnemyType m_enemyType;
};