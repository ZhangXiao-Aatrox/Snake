#include"UI.h"
#include"unit.h"

void ui::Gameui()//划边界
{
	unit::gotoxy(unit::KLEFT, unit::KUP);
	for (int i = 0; i < unit::KWIDTH; i++)
	{
		cout << "-";//上边界
	}
	for (int j = 0; j < unit::KHEIGHT; j++)
	{
		unit::gotoxy(unit::KLEFT, unit::KUP + 1 + j);
		cout << "|";//左边界
		unit::gotoxy(unit::KLEFT + unit::KWIDTH - 1, unit::KUP + 1 + j);
		cout << "|";//右边界
	}

	unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);
	for (int k = 0; k < unit::KWIDTH; k++)
	{
		cout << "-";//下边界
	}

	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 2);
	for (int j = 0; j < unit::KWIDTH - 2; j++)
	{
		cout << "-";//菜单边界
		
	}

}


void ui::Gameinfo()//介绍界面
{
	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);
	cout << "游戏名：贪吃蛇";
	unit::gotoxy(unit::KLEFT + 20, unit::KUP + 1);
	cout << "编写者：zx";
	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);
	cout << "当前得分：" << unit::SCORE;
	//cout<<my_Score;
	unit::gotoxy(unit::KLEFT + 55, unit::KUP + 1);
	cout << "当前等级：" << unit::LEVLE;
	//cout<<my_Score/10;
	//unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);//把光标移至界面下
}