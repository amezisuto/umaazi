#include "SaveManager.h"
#include "..\GameDebug\Debug.h"

SaveManager::~SaveManager()
{

}

SaveManager::SaveManager()
{
	
}

void SaveManager::Save()
{
	// �t�@�C���|�C���^�̐錾
	FILE        *fp;

	// �t�@�C�����J��
	fopen_s(&fp, "SaveData/SaveData.txt", "wt");
	if (!fp)
	{
		// �t�@�C���I�[�v���Ɏ��s�����Ƃ��̏���
		Debug::SingletonGetInstance().DebugRender("FileFalse", DirectX::SimpleMath::Vector2(10, 60));
		return;
	}

	// �t�@�C���ɏ�������
	char    str[32];
	size_t  len;
	wcstombs_s(&len, str, 32, L"", 32);
	fprintf(fp, "%s\n", str);             // ���O
	fprintf(fp, "%d\n", 1);     // ����
	for (int i = 0; i<7; i++)
	{
		fprintf(fp, "%d ", 1);    // ���x���
	}
	fprintf(fp, "\n");                    // ���x���̖��������s
										  
	fclose(fp);							// �t�@�C�������

	Debug::SingletonGetInstance().DebugRender("FileTrue", DirectX::SimpleMath::Vector2(10, 60));

}
