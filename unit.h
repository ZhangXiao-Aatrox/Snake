#pragma once
#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;



class unit
{
public:
	unit(int x = 10, int y = 5, char pic = '*');
	~unit();
	void show();
	void erase();
	static void gotoxy(int x, int y);
	static int SCORE;
	static int LEVLE;
	const static int KLEFT = 2;
	const static int KUP = 2;
	const static int KWIDTH = 70;
	const static int KHEIGHT = 30;
	int my_X;
	int my_Y;
	char my_Pic;
};

//int unit::gotoxy(int x, int y)
//{
//	COORD pos = { x,y };
//	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
//	SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
//	return 0;
//} 
