#pragma once

#include "Object.h"
#include <vector>

class Object;
class Point;

class World
{
private:
    std::vector<std::vector<Object*>> map;
    unsigned int width;
    unsigned int height;

public:
    bool readIsAvailable(Point& point);
    void write(const Object* object, Point& point);
    World(unsigned int _width, unsigned int _height): width(_width), height(_height)
    {
        map = std::vector<std::vector<Object*>>(width, std::vector<Object*>(height));
    }
};

