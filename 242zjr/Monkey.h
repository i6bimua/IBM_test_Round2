#pragma once
#include<iostream>
using namespace std;
class Monkey
{
public:
	string Appearance;
	string Ability;

	void set_app(string app);
	string get_app();
	void set_abi(string abi);
	string get_abi();
};