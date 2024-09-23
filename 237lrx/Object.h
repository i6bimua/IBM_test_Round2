#pragma once

#include <vector>
#include "World.h"

struct Point
{
    unsigned int x;
    unsigned int y;

    Point(unsigned int _x, unsigned int _y): x(_x), y(_y) {};
};


class World;




class Object
{
protected:
    char character;
    std::vector<Point> pointSet;
    int color;
    
public:
    Object(char _character, int _color): character(_character), color(_color) {};
    virtual bool isAvailable() = 0;
    virtual bool isAlive() = 0;
    virtual void clear(World& world) = 0;
    virtual ~Object() = default;
    

};