#include<iostream>
using namespace std;
class Animal
{
public:
	int age;
	string food;
};

class Monkey:public Animal
{
public:
	
	void SetData(int age, string food, string name) {
		this->age = age;
		this->food = food;
		this->name = name;
	}
	string name;
	void Show() {
		cout << "年龄：" << age << " " << "食物：" << food << " " << "名字：" << name << endl;
	}
};

class MonkeyKing:public Monkey
{
public:
	string MagicalPower;
	void MagicalShow() {
		cout << "特殊能力：" << MagicalPower << endl;
	}
};

int main() {
	Monkey monkey;//普通猴子
	monkey.SetData(10, "香蕉", "吉吉");
	monkey.Show();
	cout << "------------" << endl;
	MonkeyKing King;//孙悟空
	King.SetData(500, "桃子", "孙悟空");
	King.MagicalPower = "七十二变";
	King.Show();
	King.MagicalShow();
	
	system("pause");
	return 0;
}