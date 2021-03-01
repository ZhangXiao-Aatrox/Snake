#include"snake.h"
#include<conio.h>


snake::snake(int x, int y, int len, int speed, Dir dir, char pic)
{
	my_Headx = x;
	my_Heady = y;//中心坐标
	my_Len = len;
	my_Speed = speed;
	my_Dir = dir;

	for (int i = 0; i < my_Len ;i++)//蛇的初始生成
	{
		unit s(0, 0, pic);
		my_Body.push_back(s);
		switch (dir)
		{
		case TUP: //向上横坐标不变 纵
			//my_Body[i].my_X = my_Headx;
			//my_Body[i].my_Y = my_Heady + i;
			break;
		case TDOWN: 
			//my_Body[i].my_X = my_Headx;
			//my_Body[i].my_Y = my_Heady - i;
			break;
		case TLEFT:
			//my_Body[i].my_X = my_Headx + i;
			//my_Body[i].my_Y = my_Heady;
			break;
		case TRIGHT://已默认向右
			my_Body[i].my_X = my_Headx - i;
			my_Body[i].my_Y = my_Heady;
			break;
		default: break;
		}
	}
}

snake::~snake()
{
}

void  snake::showSnake() 
{
	for (int i = 0; i < my_Len; i++)
	{
		my_Body[i].show();
	}
}

void snake::eraseSnake()
{
	for (int i = 0; i < my_Len; i++)
	{
		my_Body[i].erase();
	}
}

void snake::listen_kb()//用于识别行动方向
{
	char kb;
	if (_kbhit())
	{
		kb = _getch();//获取键盘输入
		if (kb == ' ')//暂停
		{
			showSnake();
			system("pause>nul");
			eraseSnake();
		}
		switch (kb)
		{
		//case'0x48':
		case'w':
		case'W':
			if (my_Dir == TDOWN)
				break;
			my_Dir = TUP;
			break;

		case 's':
		case 'S':
			if (my_Dir == TUP)
				break;
			my_Dir = TDOWN;
			break;
		case 'a':
		case 'A':
			if (my_Dir == TRIGHT)
				break;
			my_Dir = TLEFT;
			break;
		case 'd':
		case 'D':
			if (my_Dir == TLEFT)
				break;
			my_Dir = TRIGHT;
			break;
		
		}
	}
}



void snake::move()
{
	//实现蛇身的移动 body move
	listen_kb();//识别方向
	/*for (int i = my_Len - 1; i > 0; i--)
	{
		my_Body[i].my_X = my_Body[i - 1].my_X;
		my_Body[i].my_Y = my_Body[i - 1].my_Y;
	}*/		
	//实现蛇头的移动  head move
	vector<unit>snk = my_Body;
		switch (my_Dir)
		{
		case TUP:
			snk[0].my_Y--;
			//my_Body[0].my_Y--;
			break;
		case TDOWN:
			snk[0].my_Y++;
			//my_Body[0].my_Y++;
			break;
		case TLEFT:
			snk[0].my_X--;
			//my_Body[0].my_X--;
			break;
		case TRIGHT:
			snk[0].my_X++;
			//my_Body[0].my_X++;
			break;
		//case SPACE:
			//system("pause");
			//getchar();
			//break;
		default:
			break;
		}
		my_Body.insert(my_Body.begin(), snk[0]);
			//
		/*vector<unit> snk;
		snk = my_Body;
		my_Body.insert(my_Body.begin(), snk[0]);
		if (eatfood() == 1)
		{
			my_Len += 1;
		}
		else
		{
			my_Body.erase(my_Body.end()-1);
		}
			//*/
	showSnake();
	Sleep(my_Speed - 10*unit::LEVLE);
	eraseSnake();
}

bool snake::eatfood(food *r)//吃食物实现增长
{
	if (r->my_X == my_Body[0].my_X && r->my_Y == my_Body[0].my_Y)
	{
		my_Len += 1;
		unit::SCORE += 5;
		unit::LEVLE = unit::SCORE / 15;
		while (1)//避免食物出现在蛇身
		{
			r->CreatPos(); 
			for (int i = 1; i < my_Len ; i++)
			{
				if (r->my_X == my_Body[i].my_X && r->my_Y == my_Body[i].my_Y)
					break;
				else if (r->my_X != my_Body[i].my_X && r->my_Y != my_Body[i].my_Y)
				{
					r->show();
					return 1;
				}
			}
			
		}
		return 1;
	}
	else
		my_Body.erase(my_Body.end() - 1);
		return 0;

}
bool snake::aliveORdeath()//判输
{
	//自残
	for (int i = 1 ;i < my_Len;i++)
	{
		if (my_Body[0].my_X == my_Body[i].my_X&& my_Body[0].my_Y == my_Body[i].my_Y)
		{
			return false;
		}
	}
	//碰壁
	if (my_Body[0].my_X == unit::KLEFT || my_Body[0].my_Y == unit::KUP + 2 || my_Body[0].my_X == unit::KLEFT + unit::KWIDTH - 1 || my_Body[0].my_Y == unit::KUP + unit::KHEIGHT + 1)
	{
		return false;
	}
	return true;
}