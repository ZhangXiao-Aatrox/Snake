#include"UI.h"
#include"unit.h"

void ui::Gameui()//���߽�
{
	unit::gotoxy(unit::KLEFT, unit::KUP);
	for (int i = 0; i < unit::KWIDTH; i++)
	{
		cout << "-";//�ϱ߽�
	}
	for (int j = 0; j < unit::KHEIGHT; j++)
	{
		unit::gotoxy(unit::KLEFT, unit::KUP + 1 + j);
		cout << "|";//��߽�
		unit::gotoxy(unit::KLEFT + unit::KWIDTH - 1, unit::KUP + 1 + j);
		cout << "|";//�ұ߽�
	}

	unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);
	for (int k = 0; k < unit::KWIDTH; k++)
	{
		cout << "-";//�±߽�
	}

	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 2);
	for (int j = 0; j < unit::KWIDTH - 2; j++)
	{
		cout << "-";//�˵��߽�
		
	}

}


void ui::Gameinfo()//���ܽ���
{
	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);
	cout << "��Ϸ����̰����";
	unit::gotoxy(unit::KLEFT + 20, unit::KUP + 1);
	cout << "��д�ߣ�zx";
	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);
	cout << "��ǰ�÷֣�" << unit::SCORE;
	//cout<<my_Score;
	unit::gotoxy(unit::KLEFT + 55, unit::KUP + 1);
	cout << "��ǰ�ȼ���" << unit::LEVLE;
	//cout<<my_Score/10;
	//unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);//�ѹ������������
}