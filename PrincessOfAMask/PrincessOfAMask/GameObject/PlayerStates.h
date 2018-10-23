#pragma once

struct PlayerStates
{
	int Hp;								// 体力
	int Lv;								// レベル
	int Atack;							// 攻撃力
	int Defense;						// 防御力
	int Exp;							// 経験値
	int Money;							// お金
	DirectX::SimpleMath::Vector2 pos;	// ポジション
	PlayerStates(int Hp,int Lv, int Atack,int Defense,int Exp,int Money)
	{
		this->Hp = Hp;
		this->Lv = Lv;
		this->Atack = Atack;
		this->Defense = Defense;
		this->Exp = Exp;
		this->Money = Money;
	}
};