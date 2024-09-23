#include "Monkey.h"
#include <ncurses.h>

class Wukong: public Monkey
{
private:
    int life = 10000;
    char character = '&';
    int color = COLOR_YELLOW;
    float speed = 0.5;
    int matrix[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};



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

    //大招：立辊
    virtual void standUpStick(World& world); 

    ~Wukong() {};
};