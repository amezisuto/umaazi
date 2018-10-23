#include "EnemyManager.h"

using namespace std;

/// <summary>
/// �R���X�g���N�^
/// </summary>
EnemyManager::EnemyManager()
{
	// �Ȃɂ����Ȃ�
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
EnemyManager::~EnemyManager()
{
	// �Ȃɂ����Ȃ�
}

/// <summary>
/// �X�V����
/// </summary>
void EnemyManager::Update()
{
	// �����\��̃V�[���폜
	RemoveEnemy();

	for (list<Enemy*>::iterator it = m_enemylist.begin(); it != m_enemylist.end(); it++)
	{
		if (!(*it)->Update())
		{
			// �폜�\�������
			m_removeEnemylist.push_back((*it));
		}
	}
}

/// <summary>
/// �`�揈��
/// </summary>
void EnemyManager::Render()
{
	for (std::list<Enemy*>::iterator it = m_enemylist.begin(); it != m_enemylist.end(); it++)
	{
		(*it)->Render();
	}
}

/// <summary>
/// �G�l�~�[���o�����X�g�ɒǉ�
/// </summary>
/// <param name="enemy">�G�l�~�[</param>
void EnemyManager::PopEnemy(Enemy* enemy)
{
	m_enemylist.push_back(enemy);
}

/// <summary>
/// �G�l�~�[
/// </summary>
void EnemyManager::RemoveEnemy()
{
	for (std::list<Enemy*>::iterator it = m_removeEnemylist.begin(); it != m_removeEnemylist.end(); it++)
	{
		m_enemylist.remove((*it));
		delete (*it);
		(*it) = nullptr;
	}
	// �폜���X�g����ɂ���
	m_removeEnemylist.clear();
}
