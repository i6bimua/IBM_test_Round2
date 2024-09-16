// main.cpp
#include <iostream>
#include "Monkey.h"
#include "SunWukong.h"

int main() {
    // 创建 Monkey 对象
    Monkey monkey("Generic Monkey", 5);
    monkey.display();
    monkey.eat("banana");
    monkey.sleep();

    std::cout << std::endl;

    // 创建 SunWukong 对象
    SunWukong sunWukong("Sun Wukong", 500, 100);
    sunWukong.display();
    sunWukong.eat("peach");
    sunWukong.useMagic("72 Transformations");
    sunWukong.sleep();

    return 0;
}
