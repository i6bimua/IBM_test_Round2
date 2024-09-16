// Monkey.h
#ifndef MONKEY_H
#define MONKEY_H

#include <string>

class Monkey {
public:
    // 构造函数
    Monkey(const std::string& name, int age);

    // 成员函数
    void eat(const std::string& food);
    void sleep();
    void display() const;

protected:
    std::string name;
    int age;
};

#endif // MONKEY_H
