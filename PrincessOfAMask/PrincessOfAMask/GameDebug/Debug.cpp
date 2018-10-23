//////////////////////////////////////////////////////////////
// File.    Debug.cpp
// Summary. DebugClass
// Date.    2018/10/15
// Auther.  Miu Himi ： Eijirou Tsujii
//////////////////////////////////////////////////////////////
 
// インクルードディレクトリ
#include "Debug.h"
#include "../Utility/DeviceResources.h"

// usingディレクトリ
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

/// <summary>
/// コンストラクタ
/// </summary>
Debug::Debug()
{
	// スプライトバッチの作成
	m_sprites = std::make_unique<SpriteBatch>(DX::DeviceResources::SingletonGetInstance().GetD3DDeviceContext());

	// スプライトフォントの作成
	m_font = std::make_unique<SpriteFont>(DX::DeviceResources::SingletonGetInstance().GetD3DDevice(), L"SegoeUI_18.spritefont");
}

/// <summary>
/// float型からwstring型への変換
/// </summary>
/// <param name="text">変換する数値</param>
/// <returns>変換したwstring</returns>
wstring Debug::NumtoWstring(float num)
{
	wstringstream ss;
	ss << "" << num;
	wstring str = ss.str();

	return str;
}

/// <summary>
/// char型からwstring型への変換
/// </summary>
/// <param name="text">変換する文字</param>
/// <returns>変換したwstring</returns>
std::wstring Debug::ChartoWstring(char * text)
{
	wstringstream ss;
	ss << "" << text;
	wstring str = ss.str();

	return str;
}

/// <summary>
/// デストラクタ
/// </summary>
Debug::~Debug()
{

}

/// <summary>
/// デバッグ描画
/// </summary>
void Debug::Render()
{
	// リストの中にある要素の数
	int listdata = 0;

	//スプライトの表示開始
	m_sprites->Begin();

	//リストの中にあるものを表示
	for (std::list<DebugTextData>::iterator it = m_debugText.begin(); it != m_debugText.end(); it++)
	{
		m_font->DrawString(m_sprites.get(),it->text.c_str(), it->pos);
	}

	//スプライトの表示終了
	m_sprites->End();

	//リストの中にある個数を数える
	for (std::list<DebugTextData>::iterator it = m_debugText.begin(); it != m_debugText.end(); it++)
	{
		listdata++;
	}

	//リストの中から取り出す
	for (int i = 0; i < listdata; i++)
	{
		m_debugText.pop_back();
	}

}

/// <summary>
/// リストにデータを追加する
/// </summary>
/// <param name="debugLen">表示したい文字</param>
/// <param name="debugPos">表示する場所</param>
void Debug::DebugRender(char* debugLen, DirectX::SimpleMath::Vector2 debugPos)
{
	m_debugText.push_back(DebugTextData(ChartoWstring(debugLen), debugPos));
}

/// <summary>
/// リストにデータを追加
/// </summary>
/// <param name="debugLen">表示したい数値</param>
/// <param name="debugPos">表示する場所</param>
void Debug::DebugRender(float debugLen, DirectX::SimpleMath::Vector2 debugPos)
{
	m_debugText.push_back(DebugTextData(NumtoWstring(debugLen), debugPos));
}

/// <summary>
/// リストにデータを追加する
/// </summary>
/// <param name="debugInf">表示するデータ</param>
/// <param name="debugPos">表示する場所</param>
void Debug::DebugRender(DirectX::SimpleMath::Vector2 debugInf, DirectX::SimpleMath::Vector2 debugPos)
{
	wstringstream ssX, ssY;
	ssX << "X = ";
	ssY << " , Y = ";
	wstring str = ssX.str() + NumtoWstring(debugInf.x) + ssY.str() + NumtoWstring(debugInf.y);

	m_debugText.push_back(DebugTextData(str, debugPos));
}

/// <summary>
/// リストにデータを追加する
/// </summary>
/// <param name="debugLen">表示するデータの名前</param>
/// <param name="debugInf">表示するデータ</param>
/// <param name="debugPos">表示する場所</param>
void Debug::DebugRender(char * debugLen, float debugInf, DirectX::SimpleMath::Vector2 debugPos)
{
	wstringstream ss;
	ss << debugLen << " : ";
	wstring str = ss.str() + NumtoWstring(debugInf);

	m_debugText.push_back(DebugTextData(str, debugPos));
}

/// <summary>
/// リストにデータを追加する
/// </summary>
/// <param name="debugLen">表示するデータの名前</param>
/// <param name="debugInf">表示するデータ</param>
/// <param name="debugPos">表示する場所</param>
void Debug::DebugRender(char * debugLen, DirectX::SimpleMath::Vector2 debugInf, DirectX::SimpleMath::Vector2 debugPos)
{
	wstringstream ss,ssY;
	ss << debugLen << " : X = ";
	ssY << " , Y = ";
	wstring str = ss.str() + NumtoWstring(debugInf.x) + ssY.str() + NumtoWstring(debugInf.y);

	m_debugText.push_back(DebugTextData(str, debugPos));
}

