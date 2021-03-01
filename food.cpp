#include"food.h"

food::food(char pic)
{
	//my_X = x;
	//my_Y = y;
	my_Pic = pic;
}

food::~food()
{
}

void food::CreatPos()
{
	srand((int)time(0));
	my_X= KLEFT + 1 + rand() % (KWIDTH - 2);
	my_Y = KUP + 3 + rand() % (KHEIGHT - 2);
}
