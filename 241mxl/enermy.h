#pragma once
#ifndef ENERMY_H_
#define ENERMY_H_
#include "monkey.h"
class Enermy
{
public:
	int eblood;
	int pow;
	bool dect_eblood();
	void show();
	void showblood();
	
};


class KALAMI :public Enermy
{
public:
	KALAMI() {eblood = 25; pow = 8;};
	//void Enermy_attack(Monkey& mo);
};

class Boss :public Enermy
{
public:
	Boss() { eblood = 100; pow = 25; };	
	//void Enermy_attack(Monkey& mo);
};
#endif