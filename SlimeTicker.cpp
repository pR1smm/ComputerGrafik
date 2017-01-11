#include "SlimeTicker.h"
#include "inputobserver.h"
#include "trycallback.h"
#include "cslime.h"

SlimeTicker::SlimeTicker(DynamicCharacterWithCam* dynaCam, CSlime* s) : IdleObserver()
{
    m_DynaChWithCam = dynaCam;
    m_Timer.restart();
    slime = s;
}

void SlimeTicker::doIt()
{
    long long time = m_Timer.restart();
    // Flags sammeln in welche richtungen der Character gehen soll
    unsigned long long v_MoveFlagsDynCh = 0;

    // Für Charakter mit verfolgerkamera
    v_MoveFlagsDynCh = 0;
    //in dem Enum Movement flag stehen noch weitere bewegungen die der charakter machen kann
    if (InputObserver::isKeyPressed('d'))
    {
        v_MoveFlagsDynCh |= MovementFlag::StraveRight;
    }
    if (InputObserver::isKeyPressed('a'))
    {
        v_MoveFlagsDynCh |= MovementFlag::StraveLeft;
    }
    if (InputObserver::isKeyPressed(Qt::Key_Space)&&slime->inAir==false)
    {
        // momentan geht jump immer, vielleicht sollte man dort wo man springen soll einen trigger platzieren
        // und dann das movement flag setzen wenn man hineinläuft und den callback abarbeitet
        v_MoveFlagsDynCh |= MovementFlag::Jump;
        slime->inAir = true;
    }
    // character in entsprechende richtungen bewegen
    m_DynaChWithCam->moveCharacter(time, v_MoveFlagsDynCh);
}
