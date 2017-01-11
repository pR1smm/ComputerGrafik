#include "trycallback.h"
#include "cslime.h"

TryCallback::TryCallback(CSlime *s){
    slime = s;
}

void TryCallback::callback(PhysicObject*& a, PhysicObject*& b, QList<CollisionPointInfo>& c)
{
    //Die Flag für´s springen zurücksetzen
    slime->inAir = false;
}
