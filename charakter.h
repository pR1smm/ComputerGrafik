#ifndef CHARACTERTICKER_H
#define CHARACTERTICKER_H

#include "idleobserver.h"
#include "physics.h"
#include <QElapsedTimer>

// Klasse um unsere beiden Charaktere zu steuern
class CharacterTicker : public IdleObserver
{
public:
    CharacterTicker(DynamicCharacterWithCam* dynaCam);
    void doIt();

private:
    DynamicCharacterWithCam* m_DynaChWithCam;
    // Timer für genaue Delta Zeitberechnung
    QElapsedTimer m_Timer;
};

#endif // CHARACTERTICKER_H
