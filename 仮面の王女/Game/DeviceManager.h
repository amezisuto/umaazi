#pragma once
#include "Utility\SingletonBase.h"

namespace System
{
	class DeviceManager : public Utility::SingletonBase<DeviceManager>
	{
	public:
		friend Utility::SingletonBase<DeviceManager>;
	private:
		//�R���X�g���N�^
		DeviceManager();
	public:
		//�f�o�C�X�擾�֐�
		ID3D11Device* GetDevice();

		//�f�o�C�X�̃Z�b�g
		void SetDevice(ID3D11Device* device);

		//�R���e�L�X�g�擾�֐�
		ID3D11DeviceContext* GetContext();

		//�R���e�L�X�g�̃Z�b�g
		void SetContext(ID3D11DeviceContext* context);

		//�A�E�g�v�b�g�T�C�Y�̎擾
		RECT GetOutputSize();

		//�A�E�g�v�b�g�T�C�Y�̃Z�b�g
		void SetOutputSize(RECT outputsize);

	private:

		ID3D11Device* m_device;

		ID3D11DeviceContext* m_context;

		RECT m_outputsize;
	};
}
