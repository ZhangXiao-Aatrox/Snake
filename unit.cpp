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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
}

