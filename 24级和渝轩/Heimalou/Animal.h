#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

/*
public：可以被该类中的函数、子类的函数、友元函数访问，也可以由该类的对象访问。
protected：可以被该类中的函数、子类的函数、友元函数访问，但不可以由该类的对象访问。
private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象访问。
private关键字的作用在于更好地隐藏类的内部实现。
*/
using namespace std;

class Animal {
public:
    string Name;
    int HP;
    int MP;
    virtual string move() const = 0;
    virtual string speak() const = 0;
    virtual ~Animal() {}
};

#endif