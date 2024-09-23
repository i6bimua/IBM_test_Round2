#include "Monkey.h"
using namespace std;

Monkey::Monkey(const string Name, int HP, int MP) : Name(Name), HP(HP), MP(MP) {}

string Monkey::move() const {
    return Name + " 爬上树了!";
}

string Monkey::speak() const {
    return Name + " 发出“Ooh ooh ah ah!”的声音";
}

void Monkey::displayStats() const {
    cout << Name << " 的 HP：" << HP << "，MP：" << MP << endl;
}