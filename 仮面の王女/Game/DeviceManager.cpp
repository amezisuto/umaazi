#include "DeviceManager.h"

using namespace System;

//�R���X�g���N�^
DeviceManager::DeviceManager()
{

}

//�f�o�C�X�擾�֐�
ID3D11Device* DeviceManager::GetDevice()
{
	return m_device;
}

//�f�o�C�X�̃Z�b�g
void DeviceManager::SetDevice(ID3D11Device* device)
{
	m_device = device;
}

//�R���e�L�X�g�擾�֐�
ID3D11DeviceContext* DeviceManager::GetContext()
{
	return m_context;
}

//�R���e�L�X�g�̃Z�b�g
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
