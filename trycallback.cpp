#include "trycallback.h"
#include "cslime.h"

TryCallback::TryCallback(CSlime *s){
    slime = s;
}

void TryCallback::callback(PhysicObject*& a, PhysicObject*& b, QList<CollisionPointInfo>& c)
{
    //über ein PhysicObject kann man auch wieder auf das Drawable zugreifen und es manipulieren
    Drawable* colidewith = (Drawable*)b->getGeometry();

    slime->inAir = false;


}
