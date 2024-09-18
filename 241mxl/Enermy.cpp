#include "monkey.h"
#include "enermy.h"
#include <iostream>
bool Enermy::dect_eblood(){
	if (eblood <= 0)
		return false;
	else
		return true;
}
void Enermy::show()
{
	using std::cout;
	using std::endl;
	cout <<"敌人力量：" << pow << endl;
	cout << "敌人血量：" << eblood << endl;
}
void Enermy::showblood()
{

	if (eblood < 0)
		eblood = 0;
	using std::cout;
	using std::endl;
	cout << "敌人血量还有： ";
	cout << eblood << endl;
	std::cin.get();
}



//void KALAMI::Enermy_attack(Monkey& mo)
//{
//	mo.blood -= pow;
//}
//void Boss::Enermy_attack(Monkey& mo)
//{
//	mo.blood -= pow;
//}