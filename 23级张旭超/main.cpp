#include<iostream>
using namespace std;
class animal
{
private:
	int age;
	string name;
	string weapon;
public:
	animal()
	{
		age = 0;
		name = "null";
		weapon = "null";
	}
	void grow(int n=1)
	{
		age += n;
	}
	virtual void getEat(string &n) = 0;
	virtual void getDrink(string& n) = 0;
	void mdWeapon(string n)
	{
		weapon = n;
	}
	void mdName(string n)
	{
		name = n;
	}
	string reName()
	{
		return name;
	}
};
class monkey:public animal
{
private:
	int attack;
	int defence;
	int hp;
public:
	monkey(string n= "monkey")
	{

		attack = 1;
		defence = 1;
		hp = 10;
		mdWeapon("picktooth");
		mdName(n);
	}
	void getEat(string& n)
	{
		cout << "eat" << n << endl;
		cout << "attack+++ defence+++ hope++" << endl;
		attack+=3;
		defence+=3;
		hp++;
	}
	void getDrink(string& n)
	{
		cout << "eat" << n << endl;
		cout << "attack++ defence++ hope+++" << endl;
		attack ++;
		defence ++;
		hp+=5;
	}
	void view()
	{
		cout << "attack=" << attack << " defence=" << defence << " hp=" << hp << endl;
	}
	virtual void beaten(double n)
	{
		cout << reName() << "under attack" << endl;
		int temp = n - defence;
		if (temp)
			hp -= temp;
		if (!hp)
		{
			cout << reName() << "dead" << endl;
		}
		else
		{
			cout << "hp=" << hp << endl;
		}
	}
	void target(monkey* d)
	{
		d->beaten(this->attack);
	}
	int reAttack()
	{
		return attack;
	}
	int& reDefence()
	{
		return defence;
	}
	int& reHp()
	{
		return hp;
	}
};
class wukon :public monkey
{
private:
	string npy;
	string dog;
	int o_D;
public:
	wukon(string n = "monkey") :monkey(n)
	{
		o_D = 0;
	}
	void standAttack(monkey* k)
	{
		k->beaten(reAttack() * 1.8);
	}
	void prickAttack(monkey* k)
	{
		k->beaten(reAttack() * 1.6);
	}
	void splitAttack(monkey* k)
	{
		k->beaten(reAttack() * 0.9999);
	}
	void getAttack(double n)
	{
		cout << reName() << "under attack" << endl;
		int temp = n - reDefence();
		if (temp)
			reHp() -= temp;
		if (!reHp())
		{
			cout << reName() << "dead" << endl;
		}
		else
		{
			cout << "hp=" << reHp() << endl;
		}
	}
	void beaten(double n)
	{
		int empt = rand() % 2;
		switch (empt)
		{
		case 1:
			Harden();
			cout << "harden" << endl;
			reDefence() = o_D;
			break;
		case 2:
			cout << "Invalid" << endl;
			break;
		}
	}
	void Harden()
	{
		int a = reDefence();
		o_D = a;
		a *= 10;
	}
};
int main()
{
	wukon kk;
	monkey tt;
	tt.target(&kk);
}