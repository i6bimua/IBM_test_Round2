// SunWukong.h
#ifndef SUNWUKONG_H
#define SUNWUKONG_H

#include "Monkey.h"

class SunWukong : public Monkey {
public:
    // 构造函数
    SunWukong(const std::string& name, int age, int power);

    // 成员函数
    void useMagic(const std::string& magic);
    void display() const ;

private:
    int power;
};

#endif // SUNWUKONG_H
