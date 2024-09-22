#include"Monkey.h"
string Appearance;
string Ability;

void Monkey::set_app(string app)
{
	Appearance = app;
}
string Monkey::get_app()
{
	return Appearance;
}
void Monkey::set_abi(string abi)
{
	Ability = abi;
}
string Monkey::get_abi()
{
	return Ability;
}

