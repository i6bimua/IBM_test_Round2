#ifndef TIGER_H
#define TIGER_H

#include "Animal.h"
#include <iostream>
using namespace std;

class Tiger : public Animal {
protected:
    string Name;
    int HP;
    int MP;

public:
    Tiger(const string Name, int HP, int MP);
    string move() const override;
    string speak() const override;
    void displayStats() const;
};

#endif