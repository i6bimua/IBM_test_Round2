#ifndef MONKEY_H
#define MONKEY_H

#include "Animal.h"
#include <iostream>
using namespace std;

class Monkey : public Animal {
protected:
    string Name;
    int HP;
    int MP;

public:
    Monkey(const string Name, int HP, int MP);
    string move() const override;
    string speak() const override;
    void displayStats() const;
};

#endif