#ifndef TIANMINGREN_H
#define TIANMINGREN_H

#include "Monkey.h"
#include <iostream>
#include <vector>
using namespace std;

class Tianmingren : public Monkey {
private:
    vector<string> MagicSkills;
    vector<string> StickSkills;

public:
    Tianmingren(const string Name, int HP, int MP,
        const vector<string> skills1, const vector<string> skills2);
    string speak() const override;
    string transform() const;
    string attack() const;
    void displayStats() const;
};

#endif