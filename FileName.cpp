#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

class Turtle
{
protected:
    float Height;
    float Weight;

public:
    Turtle(float h, float w) :Height(h), Weight(w) {}

    void Info()
    {
        std::cout << "Turtle information" << std::endl;
        std::cout << "Height:" << Height << std::endl;
        std::cout << "Weight:" << Weight << std::endl;
    }
};

class Squirtle : public Turtle
{
private:
    int HP;
    int Attack;
    int Defense;

public:
    Squirtle(float h, float w, int hp, int atk, int def)
        :Turtle(h, w), HP(hp), Attack(atk), Defense(def) {}

    void Info()
    {
        Turtle::Info();
        std::cout << "Squirtle information" << std::endl;
        std::cout << "HP:" << HP << std::endl;
        std::cout << "Attack:" << Attack << std::endl;
        std::cout << "Defense:" << Defense << std::endl;
    }

};

int main()
{
    Turtle turtle(1.0, 17.0);
    Squirtle squirtle(0.5, 9.0, 44, 48, 65); //Height,Weight,HP,Attack,Defense
    turtle.Info();
    squirtle.Info();
    return 0;
}