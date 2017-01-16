#ifndef CHARACTERTICKER_H
#define CHARACTERTICKER_H

#include "idleobserver.h"
#include "physics.h"
#include <QElapsedTimer>

class CSlime;

// Klasse um unsere beiden Charaktere zu steuern
class SlimeTicker : public IdleObserver
{
public:
    SlimeTicker(DynamicCharacterWithCam* dynaCam, CSlime* s);
    void doIt();
private:
    DynamicCharacterWithCam* m_DynaChWithCam;
    // Timer für genaue Delta Zeitberechnung
    QElapsedTimer m_Timer;
    CSlime* slime;
    int x=2;
    QMatrix4x4 p;
    bool amk = false;
};

#endif // CHARACTERTICKER_H
