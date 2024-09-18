#include "monkey.h"
#include "enermy.h"
#include <iostream>
using namespace std;
void gate(Destiner& des, KALAMI & ka, int ch);
void gate(BigBroMONKEY& bro, Boss& bo, int ch);
bool detect_enermy_dead(Boss &bo);
bool detect_enermy_dead(KALAMI &ka);
void use_drug(Monkey& mo,int ch);
int main()
{
	int choice;
	Monkey Player;
	Destiner player(Player);
	player.Set_des(player);
	KALAMI kalami;
	
	//第一关
	player.show();
	kalami.show();
	cout << "第一关，你是天命人！" << endl;
	while (player.dect_blood())
	{
		cout << "请选择是否使用药物：1丹药 2甘露 0不用：";
		cin >> choice;
		use_drug(player,choice);
		cout << "请选择你的攻击方式：1基础攻击，2魔法，3物理攻击：\a" << endl;
		cin >> choice;

		gate(player, kalami, choice);
		if (detect_enermy_dead(kalami))
			break;
		player.sub_blood(kalami);
		
		player.showblood();
		if (!player.dect_blood())
		{
			cout << "你死了！游戏结束！\a";
			return 0;
		}
	}
	cin.get();
	cin.get();
	//第二关
	cout << endl;
	cout<<"第二关，你是齐天大圣！\a";
	Boss boss;
	BigBroMONKEY player1(player);
	player1.Set_big(player1);
	player1.show();
	boss.show();
	while (player1.dect_blood())
	{
		cout << "请选择是否使用药物：1丹药 2甘露 0不用：";
		cin >> choice;
		use_drug(player1, choice);
		cout << "请选择你的攻击方式：1基础攻击，2魔法，3物理攻击,4大招：\a";
		cin >> choice;
		gate(player1,boss,choice);
		if (detect_enermy_dead(boss))
			break;
		player1.sub_blood(boss);
		player1.showblood();
		if (!player1.dect_blood())
		{
			cout << "你死了！游戏结束！";
			return 0;
		}
	}
	cout << "游戏结束\a";
	cin.get();
	cin.get();
	return 0;
}
