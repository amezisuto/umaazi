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
	// ファイルポインタの宣言
	FILE        *fp;

	// ファイルを開く
	fopen_s(&fp, "SaveData/SaveData.txt", "wt");
	if (!fp)
	{
		// ファイルオープンに失敗したときの処理
		Debug::SingletonGetInstance().DebugRender("FileFalse", DirectX::SimpleMath::Vector2(10, 60));
		return;
	}

	// ファイルに書き込む
	char    str[32];
	size_t  len;
	wcstombs_s(&len, str, 32, L"", 32);
	fprintf(fp, "%s\n", str);             // 名前
	fprintf(fp, "%d\n", 1);     // 性別
	for (int i = 0; i<7; i++)
	{
		fprintf(fp, "%d ", 1);    // 収支情報
	}
	fprintf(fp, "\n");                    // 収支情報の末尾を改行
										  
	fclose(fp);							// ファイルを閉じる

	Debug::SingletonGetInstance().DebugRender("FileTrue", DirectX::SimpleMath::Vector2(10, 60));

}
