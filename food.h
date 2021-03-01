#pragma once
#include "unit.h"
#include <cstdlib>//rand()
#include<ctime> //srand()
class food :
	public unit	
{
public:
	
	food(char pic='$');
	~food();
	void CreatPos();
};

