#include "Tiger.h"
#include "Monkey.h"
#include "Tianmingren.h"
using namespace std;

int main() {
    vector<string> skills1 = { "广智", "幽魂" };
    vector<string> skills2 = { "劈棍","立棍","戳棍","截棍","斩棍" };

    Tiger tiger("虎先锋", 10000, 100);
    Monkey monkey1("吗喽 A", 10, 1);
    Tianmingren tianmingren("天命人", 9999, 9999, skills1, skills2);

    cout << tiger.move() << endl;
    cout << monkey1.move() << endl;
    cout << monkey1.speak() << endl;
    cout << tianmingren.move() << endl;
    cout << tianmingren.speak() << endl;
    cout << tiger.speak() << endl;
    cout << tianmingren.attack() << endl;
    cout << tianmingren.transform() << endl << endl;

    cout << "本轮过后，各自状态为" << endl;
    tiger.displayStats();
    monkey1.displayStats();
    tianmingren.displayStats();

    return 0;
}