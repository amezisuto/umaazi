#pragma once
#include "Emotion.h"

struct PlayerStates
{
	int Lv;								// ���x��
	int Hp;								// �̗�
	int Atack;							// �U����
	int Defense;						// �h���
	int Exp;							// �o���l
	int Money;							// ����
	DirectX::SimpleMath::Vector2 pos;	// �|�W�V����
	/*PlayerStates(int Hp,int Lv, int Atack,int Defense,int Exp,int Money)
	{
		this->Hp = Hp;
		this->Lv = Lv;
		this->Atack = Atack;
		this->Defense = Defense;
		this->Exp = Exp;
		this->Money = Money;
	}*/
};


enum PlayerInfId
{
	LV,				// ���x��
	HP,				// �̗�
	ATK,			// �U����
	DEF,			// �h���
	EXP,			// �o���l
	MONEY,			// ����
	POS,			// �|�W�V����
};
