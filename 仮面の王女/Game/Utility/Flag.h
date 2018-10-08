#pragma once

namespace Utility
{
	class Flag
	{
	public:

		// �R���X�g���N�^
		Flag()
			: mFlag(0)
		{

		}

		/// <summary>
		/// �t���O�𗧂Ă�
		/// </summary>
		void On(unsigned int flag)
		{
			mFlag |= flag;
		}

		/// <summary>
		/// �t���O�𕚂���
		/// </summary>
		/// <param name="flag"></param>
		void Off(unsigned int flag)
		{
			mFlag &= ~flag;
		}
		
		/// <summary>
		/// �t���O�������Ă邩�m�F
		/// </summary>
		/// <param name="flag"></param>
		/// <returns>true = �����Ă�@false = �����ĂȂ�</returns>
		bool Is(unsigned int flag)
		{
			return (mFlag & flag) != 0;
		}

	private:

		unsigned int mFlag;
	};
}