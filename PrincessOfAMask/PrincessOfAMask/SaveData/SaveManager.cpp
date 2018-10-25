#include "SaveManager.h"
#include "..\GameDebug\Debug.h"
#include "..\GameObject\Player.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

/// <summary>
/// �R���X�g���N�^
/// </summary>
SaveManager::~SaveManager()
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
SaveManager::SaveManager()
{
	
}

/// <summary>
/// �Z�[�u
/// </summary>
void SaveManager::Save()
{
	ofstream outputfile("SaveData\\SaveData.txt");
	PlayerStates SaveStates = Player::SingletonGetInstance().GetPlayerStates();
	outputfile << SaveStates.Lv << "," << SaveStates.Hp << ",";
	outputfile.close();
}

/// <summary>
/// �Z�[�u�f�[�^�̃��[�h
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

	//txt�̈�s��ǂݍ���
	while (getline(ifs, line))
	{
		istringstream lineSs(line);

		string buf;

		//��s�J���}��؂�Ŏ��o��
		for (int i = 0; getline(lineSs, buf, ','); i++)
		{
			istringstream ss(buf);
			
			//�ǂݍ���ł����s�̕������l������
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
