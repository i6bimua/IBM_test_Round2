#pragma once
#ifndef MONKKEY_H_
#define MONKEY_H_
#include"enermy.h"

class Monkey
{
public:
	int magic=50;
	int max_magic = 100;
	int exp=0;
	int power;
	int blood;
	int max_blood;
	void show();
	void basic_hit(Enermy& en);
	void heal_blood();
	void add_magic();
	bool dect_blood()const;
	int dect_magic()const;
	void sub_blood(Boss &bo);
	void sub_blood(KALAMI& ka);
	Monkey(int p=0, int b=0, int mb=0);
	void showblood();
	void showmagic();
	
	
};

class Destiner :public Monkey
{
public:
	Destiner(Monkey &mo);
	void Set_des(Destiner& des, int p = 10, int b = 40, int mb = 40);
	void phy_skill_level1(Enermy& en);
	void mag_skill_level1(Enermy& en);
	
};


class BigBroMONKEY :public Monkey
{
public:
	BigBroMONKEY(Monkey & mo);
	void Set_big(BigBroMONKEY& big, int p = 20, int b = 100, int mb = 100);
	void phy_skill_level2(Enermy& en);
	void mag_skill_level2(Enermy& en);
	void BIGBANG(Enermy& en);
};

#endif