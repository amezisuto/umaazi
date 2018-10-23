#pragma once
#include "..\Utility\SingletonBase.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

class SaveManager : public SingletonBase<SaveManager>
{
public:
	friend SingletonBase<SaveManager>;

	~SaveManager();

	void Save();

private:
	SaveManager();

private:

};