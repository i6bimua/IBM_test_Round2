#include "Animal.h"
#include <ncurses.h>

class Monkey: public Animal
{
private:
    int life = 100;
    char character = '&';
    int color = COLOR_YELLOW;
    float speed = 0.1;
    int matrix[2][2] = {{0,0}, {0,1}};



public:
    Monkey(Point p): Animal(character, color, speed, life)
    {
        for(int i=0; i<sizeof(matrix)/sizeof(matrix[0]); i++)
        {
            pointSet.push_back(Point(matrix[i][0]+p.x, matrix[i][1]+p.y));
        }

    }

    virtual void attack(World& world) override;
    virtual void update(World& world) override;
    virtual void clear(World& world)  override;

    ~Monkey() {};
};