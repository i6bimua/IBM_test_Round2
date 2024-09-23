#include "Object.h"
#include "World.h"

class DynObject: public Object
{
protected:
    float speed;
    float displace;
public:
    
    DynObject(char _character, int _color, float _speed): Object(_character, _color)
    {
        speed=_speed;
        displace=0;
    }
    virtual void update(World& world) = 0;
};