#pragma once
#include "Utility\SingletonBase.h"

namespace System
{
	class DeviceManager : public Utility::SingletonBase<DeviceManager>
	{
	public:
		friend Utility::SingletonBase<DeviceManager>;
	private:
		//コンストラクタ
		DeviceManager();
	public:
		//デバイス取得関数
		ID3D11Device* GetDevice();

		//デバイスのセット
		void SetDevice(ID3D11Device* device);

		//コンテキスト取得関数
		ID3D11DeviceContext* GetContext();

		//コンテキストのセット
		void SetContext(ID3D11DeviceContext* context);

		//アウトプットサイズの取得
		RECT GetOutputSize();

		//アウトプットサイズのセット
		void SetOutputSize(RECT outputsize);

	private:

		ID3D11Device* m_device;

		ID3D11DeviceContext* m_context;

		RECT m_outputsize;
	};
}
