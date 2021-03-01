#pragma once
#include<vector>
#include"unit.h"
#include"food.h"
#include"snake.h"

typedef enum Dir
{
	TUP, TDOWN, TLEFT, TRIGHT
};
class snake
{
public:
	int my_Headx;
	int my_Heady;
	int my_Len;
	int my_Speed;
	Dir my_Dir;
	vector<unit> my_Body;

	snake(int x = 40, int y = 10, int len = 4, int speed = 200, Dir dir = TRIGHT, char pic = 'o');
	~snake();
	void showSnake();
	void eraseSnake();
	void move();
	void listen_kb();
	bool eatfood(food *r);
	bool aliveORdeath();
};