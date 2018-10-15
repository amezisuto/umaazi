//////////////////////////////////////////////////////////////
// File.    Emotion.h
// Summary. EmotionClass
// Date.    2018/10/12
// Auther.  Miu Himi
//////////////////////////////////////////////////////////////

#pragma once

// インクルードデイレクトリ
#include "../pch.h"

class Emotion
{
public:
	enum EmotionState
	{
		NORMAL,     // 普通
		JOY,        // 喜
		ANGER,      // 怒
		SADNESS,    // 哀
		Happiness,  // 楽

		NONE,       // 総数
	};
};