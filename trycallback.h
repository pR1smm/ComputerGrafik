#ifndef TRYCALLBACK_H
#define TRYCALLBACK_H

#include "physics.h"

#include "drawable.h"
#include "color.h"
#include "modeltransformation.h"
#include "SlimeTicker.h"

class CSlime;

// Dummy Klasse für Callback erzeugen, kann jede beliebige Klasse auch sein
class TryCallback
{
public:
    //SlimeTicker* ticker;
    TryCallback(CSlime* s);

    // wichtig ist das sie eine methode besitzt mit folgenden rückgabetypen und argumenten, der name der methode ist
    // unerheblich da mit einem zeiger darauf verwiesen wird
    void callback(PhysicObject*& a, PhysicObject*& b, QList<CollisionPointInfo>& c);
private:
    CSlime* slime;
};

#endif // TRYCALLBACK_H
