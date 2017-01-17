#include "trycallback.h"
#include "cslime.h"

TryCallback::TryCallback(CSlime *s){
    slime = s;
}

void TryCallback::callback(PhysicObject*& a, PhysicObject*& b, QList<CollisionPointInfo>& c)
{
    //Die Flag für´s springen zurücksetzen
    slime->inAir = false;
    Drawable* colidewith = (Drawable*)b->getGeometry();
   // colidewith->getProperty<ModelTransformation>()->translate(0.f, 3.f, 0.f);
}
