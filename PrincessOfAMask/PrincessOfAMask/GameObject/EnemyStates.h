#pragma once

//�G�l�~�[�̃X�e�[�^�X
struct EnemyStates
{
	int Atack;								//�U����
	int Defense;							//�h���
	int Hp;									//�̗�
	int Lv;									//���x��
	int Exp;								//�o���l
	int Money;								//����
	char* Name;								//���O
	DirectX::SimpleMath::Vector2 Pos;
	EnemyStates(char* Name, int Atack, int Defense, int Hp, int Lv, int Exp, int Money,DirectX::SimpleMath::Vector2 Pos)
	{
		this->Atack = Atack;
		this->Defense = Defense;
		this->Exp = Exp;
		this->Hp = Hp;
		this->Lv = Lv;
		this->Money = Money;
		this->Name = Name;
		this->Pos = Pos;
	}
};

//�G�l�~�[�̎��
enum EnemyType
{
	Slime,				//�X���C��
	
	NONE,				//����
};