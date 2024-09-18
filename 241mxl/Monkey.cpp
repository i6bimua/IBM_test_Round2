#include "monkey.h"
#include "enermy.h"
#include <iostream>
Monkey::Monkey(int p, int b, int mb)
{
	power = p;
	blood = b;
	max_blood = mb;
}

void Monkey::show()
{
	using std::cout;
	using std::endl;
	cout << "show:\n";
	cout <<"你的血量： " << blood << endl;
	cout <<"你的攻击力： " << power << endl;
	cout <<"你的最大血量" << max_blood << endl;
	cout << "你的法力值" << magic << endl;
}

void Monkey::basic_hit(Enermy &en)
{
	en.eblood -= power;
}
void Monkey::heal_blood()
{
	if(blood<max_blood)
		blood += 20;
	if (blood > max_blood)
		blood = max_blood;
	showblood();
}
void Monkey::add_magic()
{
	if(magic<max_magic)
		magic += 15;
	if (magic > max_magic)
		magic = max_magic;
	showmagic();
}
bool Monkey::dect_blood()const
{
	if (blood > 0)
		return 1;
	else
		return 0;
}
int  Monkey::dect_magic()const
{
	return magic;
}
void Monkey::sub_blood(Boss& bo)
{
	using std::cout;
	cout << "敌人对你进行了攻击!\n";
	blood -= (bo.pow)*3;
}
void Monkey::sub_blood(KALAMI& ka)
{
	using std::cout;
	cout << "敌人对你进行了攻击!\n";
	blood -= (ka.pow) * 2;
}

void Monkey::showblood()
{
	using namespace std;
	cout << "你的血量：" << blood << endl;
}

void Monkey::showmagic()
{
	using std::cout;
	using std::endl;
	cout << "你的法力： " << magic << endl;
}


