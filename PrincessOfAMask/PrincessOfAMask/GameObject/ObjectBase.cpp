//////////////////////////////////////////////////////////////
// File.    ObjectBase.cpp
// Summary. ObjectBaseClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

// インクルードディレクトリ
#include "ObjectBase.h"

/// <summary>
/// コンストラクタ
/// </summary>
ObjectBase::ObjectBase()
	: m_pos(0.0f, 0.0f),
	  m_vel(0.0f, 0.0f)
{
}
/// <summary>
/// デストラクタ
/// </summary>
ObjectBase::~ObjectBase()
{
}
