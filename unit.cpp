#include "unit.h"

int unit::LEVLE = 0;
int unit::SCORE = 0;
unit::unit(int x, int y, char pic)
{
	my_X = x;
	my_Y = y;
		my_Pic = pic;
}

unit::~unit()
{}

void unit::show()//
{
	gotoxy(my_X, my_Y);
	cout << my_Pic;
}
void unit::erase()
{
	gotoxy(my_X, my_Y);
	cout << " ";
}
void unit::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}

