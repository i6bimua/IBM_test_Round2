#include "Tianmingren.h"
using namespace std;

Tianmingren::Tianmingren(const string Name, int HP, int MP,
    const vector<string> skills1, const vector<string> skills2) :
    Monkey(Name, HP, MP), MagicSkills(skills1), StickSkills(skills2) {}

string Tianmingren::speak() const {
    return Name + " 说：“哇哒！俺老孙——来也！”";
}

string Tianmingren::transform() const {
    if (!MagicSkills.empty()) {
        return Name + " 使用七十二变，变成了 " + MagicSkills.front();
    }
    else {
        return Name + " 没有任何技能！";
    }
}

string Tianmingren::attack() const {
    if (!StickSkills.empty()) {
        return Name + " 使用金箍棒进行了 " + StickSkills.front() + " 攻击";
    }
    else {
        return Name + " 没有任何棍法！";
    }
}

void Tianmingren::displayStats() const {
    cout << Name << " 的 HP：" << HP << "，MP：" << MP << endl;
}