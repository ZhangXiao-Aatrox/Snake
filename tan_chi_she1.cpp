#include<cstdlib>
#include<windows.h>
#include"food.h"
#include"UI.h"
#include"snake.h"
#include<stdio.h>
#include<conio.h>
#include<dsound.h>
#pragma comment(lib,"Winmm.lib")
//隐藏光标
void hidden() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = {1,0};
	SetConsoleCursorInfo(hOut, &cci);
}
//背景音乐
void OpenMusic()
{
	mciSendString(TEXT("open BGM.wma alias mysong"), NULL, 0, NULL);
	mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
}
//关闭音乐
void CloseMusic()
{
	mciSendString(TEXT("close mysong"), NULL, 0, NULL);
}
	/*要取得[0, n)  就是rand（）% n     表示 从0到n - 1的数

要取得[a, b)的随机整数，使用(rand() % (b - a)) + a;
要取得[a, b]的随机整数，使用(rand() % (b - a + 1)) + a;
要取得(a, b]的随机整数，使用(rand() % (b - a)) + a + 1;
通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)
  */
void gamerunning()
{
	system("color F4");//控制台颜色
	OpenMusic();//背景音乐
		// CloseMusic();

	ui* s;
	s = new ui;
	s->Gameui();//生成边框
	s->Gameinfo();//生成介绍

	food* r;
	r = new food;
	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	r->CreatPos();//生成随机坐标
	r->show();//生成食物

	//ui *s;
	//s = new ui;
	//s->Gameui();//生成边框
	//s->Gameinfo();//生成介绍

	snake* k;
	k = new snake;

	hidden();//隐藏光标

	while (1)
	{

		if (k->aliveORdeath())
		{
			k->move();
			k->eatfood(r);
			s->Gameinfo();

		}
		else
		{
			
			k->showSnake();
			break;
		}
	}

	system("pause>nul");//不让文字输入
	system("cls");//翻页
	delete r, s, k;//释放空间
	r = NULL;
	s = NULL;
	k = NULL;
}

void menu()
{
	
	unit::gotoxy(50, 10);
	cout << "1. 启 动 游 戏 ";
	unit::gotoxy(50, 15);
	cout << "2. 游 戏 介 绍 ";
	unit::gotoxy(50, 20);
	cout << "3. 退 出 游 戏";
	char signal;

	signal = _getch();
	switch (signal)
	{
	case '1':
		system("CLS");
		gamerunning();
		CloseMusic();
		system("color 7");
		break;
	case '2':
		system("CLS");
		unit::gotoxy(50, 10);
		cout << "贪 吃 蛇 游 戏 规 则";
		unit::gotoxy(35, 15);
		cout << "通过键盘输入W A S D 控制上 下 左 右（不区分大小写）";
		unit::gotoxy(30, 20);
		cout << "吃到1个食物获得5分，每吃3个食物增加1级，等级越高，速度越快";
		unit::gotoxy(35, 25);
		cout << "蛇吃到自身 或 碰到边界则游戏失败 按任意键返回菜单";
		unit::gotoxy(50, 30);
		cout << "(游戏中途按空格键可暂停)";
		system("pause>nul");
		break;
	case '3':
		system("CLS");
		unit::gotoxy(50, 15);
		cout << "Thanks for your playing !";
		system("pause>nul");
		system("cls");
		exit(1);
		break;
	default:
		break;
	}
}

	int main()
	{
		while (1)
		{
			system("CLS");

			menu();
			unit::SCORE = 0;
			unit::LEVLE = 0;

			//system("pause>nul");

		}
		//system("color F4");//控制台颜色
		//OpenMusic();//背景音乐
		//	// CloseMusic();

		//ui* s;
		//s = new ui;
		//s->Gameui();//生成边框
		//s->Gameinfo();//生成介绍
		//
		//food *r;
		//r = new food;
		//srand((int)time(0));  // 产生随机种子  把0换成NULL也行
		//r->CreatPos();//生成随机坐标
		//r->show();//生成食物

		////ui *s;
		////s = new ui;
		////s->Gameui();//生成边框
		////s->Gameinfo();//生成介绍
		//
		//snake *k;
		//k = new snake;

		//hidden();//隐藏光标
		//
		//while (1)
		//{

		//	if (k->aliveORdeath())
		//	{
		//		k->move();
		//		k->eatfood(r);
		//		s->Gameinfo();
		//		
		//	}
		//	else
		//	{
		//		k->showSnake();
		//		break;
		//	}
		//}

		//system("pause>nul");//不让文字输入
		//system("cls");//翻页
		//delete r, s, k;//释放空间
		//r = NULL;
		//s = NULL;
		//k = NULL;
		return 0;
	}


