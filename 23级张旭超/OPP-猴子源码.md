# OPP-猴子源码

```c++
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
		//懒得弄好了
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
```

## 纯虚函数

基类animal

```c++
class animal
{
private:
	int age;
	string name;
	string weapon;
    //分别为年龄，名字，武器
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
    //纯虚函数，吃喝
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
    //返回与赋值
};
```

## Monkey

```c++
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
    //初始化
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
    //吃喝
	void view()
	{
		cout << "attack=" << attack << " defence=" << defence << " hp=" << hp << endl;
	}
    //属性
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
    //受击
	void target(monkey* d)
	{
		d->beaten(this->attack);
	}
    //攻击
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
    //数据返回
};
```

## wukon

```c++
class wukon :public monkey
{
private:
	string npy;
	string dog;
    //两个特殊的数据，女朋友和xxx的🐕
	int o_D;
    //初始数据
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
        //经常打不中
	}
    //三个烧火棍
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
    //中介受击
	void beaten(double n)
	{
		int empt = rand() % 2;
		//懒得弄好了
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
    //受击
	void Harden()
	{
		int a = reDefence();
		o_D = a;
		a *= 10;
	}
    //变硬
};
```

