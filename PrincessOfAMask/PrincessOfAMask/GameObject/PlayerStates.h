#pragma once
#include "Emotion.h"

struct PlayerStates
{
	int Lv;								// レベル
	int Hp;								// 体力
	int Atack;							// 攻撃力
	int Defense;						// 防御力
	int Exp;							// 経験値
	int Money;							// お金
	DirectX::SimpleMath::Vector2 pos;	// ポジション
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
	LV,				// レベル
	HP,				// 体力
	ATK,			// 攻撃力
	DEF,			// 防御力
	EXP,			// 経験値
	MONEY,			// お金
	POS,			// ポジション
};
