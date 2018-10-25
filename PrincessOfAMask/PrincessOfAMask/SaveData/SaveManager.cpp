#include "SaveManager.h"
#include "..\GameDebug\Debug.h"
#include "..\GameObject\Player.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

/// <summary>
/// コンストラクタ
/// </summary>
SaveManager::~SaveManager()
{

}

/// <summary>
/// デストラクタ
/// </summary>
SaveManager::SaveManager()
{
	
}

/// <summary>
/// セーブ
/// </summary>
void SaveManager::Save()
{
	ofstream outputfile("SaveData\\SaveData.txt");
	PlayerStates SaveStates = Player::SingletonGetInstance().GetPlayerStates();
	outputfile << SaveStates.Lv << "," << SaveStates.Hp << ",";
	outputfile.close();
}

/// <summary>
/// セーブデータのロード
/// </summary>
void SaveManager::LoadSave()
{
	string filepath = "SaveData\\SaveData";

	ostringstream oss;

	filepath += oss.str() + ".txt";

	ifstream ifs(filepath);

	string line;
	PlayerStates loadStates;
	PlayerStates bufStates;

	//txtの一行を読み込む
	while (getline(ifs, line))
	{
		istringstream lineSs(line);

		string buf;

		//一行カンマ区切りで取り出す
		for (int i = 0; getline(lineSs, buf, ','); i++)
		{
			istringstream ss(buf);
			
			//読み込んできた行の文字数値を入れる
			switch (i)
			{
			case static_cast<int> (PlayerInfId::LV) :
				ss >> loadStates.Lv;
				break;
			case static_cast<int> (PlayerInfId::HP) :
				ss >> loadStates.Hp;
				break;
			case static_cast<int> (PlayerInfId::ATK) :
				ss >> loadStates.Atack;
				break;
			case static_cast<int> (PlayerInfId::DEF) :
				ss >> loadStates.Defense;
				break;
			case static_cast<int> (PlayerInfId::EXP) :
				ss >> loadStates.Exp;
				break;
			case static_cast<int> (PlayerInfId::MONEY) :
				ss >> loadStates.Money;
				break;
			}
		}
	}
	Player::SingletonGetInstance().SetStates(loadStates);

}
