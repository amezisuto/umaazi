#pragma once

//エネミーのステータス
struct EnemyStates
{
	int Atack;								//攻撃力
	int Defense;							//防御力
	int Hp;									//体力
	int Lv;									//レベル
	int Exp;								//経験値
	int Money;								//お金
	char* Name;								//名前
	EnemyStates(char* Name, int Atack, int Defense, int Hp, int Lv, int Exp, int Money)
	{
		this->Atack = Atack;
		this->Defense = Defense;
		this->Exp = Exp;
		this->Hp = Hp;
		this->Lv = Lv;
		this->Money = Money;
		this->Name = Name;
	}
};

//エネミーの種類
enum EnemyType
{
	Slime,				//スライム
	
	NONE,				//総数
};