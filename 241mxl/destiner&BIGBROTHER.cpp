#include "monkey.h"
#include "enermy.h"
#include <iostream>
//destiner
void press();
Destiner::Destiner(Monkey& mo) : Monkey(mo)
{}

void Destiner::Set_des(Destiner& des, int p, int b, int mb)
{
	des.power = p;
	des.blood = b;
	des.max_blood = mb;
}
void Destiner::phy_skill_level1(Enermy& en)
{
	en.eblood =en.eblood - power;
}
void Destiner::mag_skill_level1(Enermy& en)
{
	if (dect_magic() >= 20)
	{
		en.eblood -= power * 2;
		magic -= 15;
	}
	else
		std::cout << "no enough magic!\n";
}







//bigbrother
BigBroMONKEY::BigBroMONKEY(Monkey & mo): Monkey (mo)
{}
void BigBroMONKEY::Set_big(BigBroMONKEY& big, int p, int b, int mb)
{
	power = p;
	blood = b;
	max_blood = mb;
}
void BigBroMONKEY::phy_skill_level2(Enermy& en)
{
	en.eblood -= power;
}
void BigBroMONKEY::mag_skill_level2(Enermy& en)
{
	if (dect_magic() >= 20)
	{
		en.eblood -= power * 2;
		magic -= 25;
	}
	else
		std::cout << "no enough magic!\n";
}
void BigBroMONKEY::BIGBANG(Enermy& en)
{
	if (dect_magic()>= 80)
	{
		press();
		std::cout << "bang!俺老孙来吔!!!!!!!!!!";
		std::cout << "\n";
		en.eblood -= 999;
	}
	else
		std::cout << "no enough magic!\n";
	std::cout << "你有法力值：" << magic;
	std::cin.get();
}

