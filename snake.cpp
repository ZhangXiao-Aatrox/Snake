#include"snake.h"
#include<conio.h>


snake::snake(int x, int y, int len, int speed, Dir dir, char pic)
{
	my_Headx = x;
	my_Heady = y;//��������
	my_Len = len;
	my_Speed = speed;
	my_Dir = dir;

	for (int i = 0; i < my_Len ;i++)//�ߵĳ�ʼ����
	{
		unit s(0, 0, pic);
		my_Body.push_back(s);
		switch (dir)
		{
		case TUP: //���Ϻ����겻�� ��
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
		case TRIGHT://��Ĭ������
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

void snake::listen_kb()//����ʶ���ж�����
{
	char kb;
	if (_kbhit())
	{
		kb = _getch();//��ȡ��������
		if (kb == ' ')//��ͣ
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
	//ʵ��������ƶ� body move
	listen_kb();//ʶ����
	/*for (int i = my_Len - 1; i > 0; i--)
	{
		my_Body[i].my_X = my_Body[i - 1].my_X;
		my_Body[i].my_Y = my_Body[i - 1].my_Y;
	}*/		
	//ʵ����ͷ���ƶ�  head move
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

bool snake::eatfood(food *r)//��ʳ��ʵ������
{
	if (r->my_X == my_Body[0].my_X && r->my_Y == my_Body[0].my_Y)
	{
		my_Len += 1;
		unit::SCORE += 5;
		unit::LEVLE = unit::SCORE / 15;
		while (1)//����ʳ�����������
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
bool snake::aliveORdeath()//����
{
	//�Բ�
	for (int i = 1 ;i < my_Len;i++)
	{
		if (my_Body[0].my_X == my_Body[i].my_X&& my_Body[0].my_Y == my_Body[i].my_Y)
		{
			return false;
		}
	}
	//����
	if (my_Body[0].my_X == unit::KLEFT || my_Body[0].my_Y == unit::KUP + 2 || my_Body[0].my_X == unit::KLEFT + unit::KWIDTH - 1 || my_Body[0].my_Y == unit::KUP + unit::KHEIGHT + 1)
	{
		return false;
	}
	return true;
}