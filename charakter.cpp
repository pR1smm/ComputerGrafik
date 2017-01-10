#include "charakter.h"
#include "inputobserver.h"

CharacterTicker::CharacterTicker(DynamicCharacterWithCam* dynaCam) : IdleObserver()
{
    m_DynaChWithCam = dynaCam;
    m_Timer.restart();
}

void CharacterTicker::doIt()
{
    long long time = m_Timer.restart();
    // Flags sammeln in welche richtungen der Character gehen soll
    unsigned long long v_MoveFlagsDynCh = 0;

    // Für Charakter mit verfolgerkamera
    v_MoveFlagsDynCh = 0;
    // t f g h space zur steuerung, in dem Enum Movement flag stehen noch weitere bewegungen die der charakter machen
    // kann
    if (InputObserver::isKeyPressed('t'))
    {
        v_MoveFlagsDynCh |= MovementFlag::Forward;
    }
    if (InputObserver::isKeyPressed('f'))
    {
        v_MoveFlagsDynCh |= MovementFlag::TurnLeft;
    }
    if (InputObserver::isKeyPressed('g'))
    {
        v_MoveFlagsDynCh |= MovementFlag::Backward;
    }
    if (InputObserver::isKeyPressed('h'))
    {
        v_MoveFlagsDynCh |= MovementFlag::TurnRight;
    }
    if (InputObserver::isKeyPressed(Qt::Key_Space))
    {
        // momentan geht jump immer, vielleicht sollte man dort wo man springen soll einen trigger platzieren
        // und dann das movement flag setzen wenn man hineinläuft und den callback abarbeitet
        v_MoveFlagsDynCh |= MovementFlag::Jump;
    }
    // character in entsprechende richtungen bewegen
    m_DynaChWithCam->moveCharacter(time, v_MoveFlagsDynCh);
}
