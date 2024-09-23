#include "Tiger.h"
using namespace std;

Tiger::Tiger(const string Name, int HP, int MP) : Name(Name), HP(HP), MP(MP) {}

string Tiger::move() const {
    return Name + " 猛扑向你";
}

string Tiger::speak() const {
    return Name + " 发出“Haoooooo！”的吼叫";
}

void Tiger::displayStats() const {
    cout << Name << " 的 HP：" << HP << "，MP：" << MP << endl;
}