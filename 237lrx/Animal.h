#include "DynObject.h"

class Animal: public DynObject
{
protected:
    int life;

public:
    Animal(char _character, int _color, float _speed, int _life): DynObject(_character, _color, _speed), life(_life) {};
    virtual bool isAvailable() override { return true;}
    virtual bool isAlive() override
    {
        if(life<=0 ) return false;
        else return true;
    }
    virtual void attack(World& world) = 0;
};