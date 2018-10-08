#include "DeviceManager.h"

using namespace System;

//コンストラクタ
DeviceManager::DeviceManager()
{

}

//デバイス取得関数
ID3D11Device* DeviceManager::GetDevice()
{
	return m_device;
}

//デバイスのセット
void DeviceManager::SetDevice(ID3D11Device* device)
{
	m_device = device;
}

//コンテキスト取得関数
ID3D11DeviceContext* DeviceManager::GetContext()
{
	return m_context;
}

//コンテキストのセット
void DeviceManager::SetContext(ID3D11DeviceContext * context)
{
	m_context = context;
}

RECT System::DeviceManager::GetOutputSize()
{
	return m_outputsize;
}

void System::DeviceManager::SetOutputSize(RECT outputsize)
{
	m_outputsize = outputsize;
}
