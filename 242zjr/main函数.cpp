#include"Monkey.h"
#include"SunWukong.h"

int main()
{
	Monkey Feature;
	Feature.set_app("毛发浓密而富有光泽，四肢修长而有力");
	Feature.set_abi("善爬树，灵活运用双手");
	SunWukong Black_Wukong;
	Black_Wukong.set_mag("七十二变，火眼金睛");
	cout << "孙悟空的外貌：" << Feature.get_app() << endl;
	cout << "孙悟空的能力：" << Feature.get_abi() << endl;
	cout << "孙悟空的神通：" << Black_Wukong.get_mag() << endl;
	return 0;
}