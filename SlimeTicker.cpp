#include "SlimeTicker.h"
#include "inputobserver.h"
#include "trycallback.h"
#include "cslime.h"

SlimeTicker::SlimeTicker(DynamicCharacterWithCam* dynaCam, CSlime* s) : IdleObserver()
{
    m_DynaChWithCam = dynaCam;
    m_Timer.restart();
    slime = s;
    p = slime->v_TransSlime->getModelMatrix();
}

void SlimeTicker::doIt()
{

    //slime->v_TransSlime->translate(slime->v_TransSlime->getModelMatrix().);
    long long time = m_Timer.restart();
    // Flags sammeln in welche richtungen der Character gehen soll
    unsigned long long v_MoveFlagsDynCh = 0;

    m_DynaChWithCam->setJumpSpeed(10);

    // Für Charakter mit verfolgerkamera
    v_MoveFlagsDynCh = 0;
    //in dem Enum Movement flag stehen noch weitere bewegungen die der charakter machen kann
    if (InputObserver::isKeyPressed('d'))
    {
        v_MoveFlagsDynCh |= MovementFlag::StraveRight;

       //Skaalierung
       if (amk==false)
       {
           if(x>250) amk= true;
       p.scale(0.999,1,0.999);
       slime->v_TransSlime->setModelMatrix(p);
       x++;
       }
       else
       {
           if(x==1) amk = false;
       p.scale(1.001,1,1.001);
       slime->v_TransSlime->setModelMatrix(p);
       x--;
        }
    }
    if (InputObserver::isKeyPressed('a'))
    {
        v_MoveFlagsDynCh |= MovementFlag::StraveLeft;
        //Skalierung
        if (amk==false)
        {
            if(x>250) amk= true;
        p.scale(0.999,1,0.999);
        slime->v_TransSlime->setModelMatrix(p);
        x++;
        }
        else
        {
            if(x==1) amk = false;
        p.scale(1.001,1,1.001);
        slime->v_TransSlime->setModelMatrix(p);
        x--;
         }
    }
    if (InputObserver::isKeyPressed(Qt::Key_Space)&&slime->inAir==false)
    {
        // momentan geht jump immer, vielleicht sollte man dort wo man springen soll einen trigger platzieren
        // und dann das movement flag setzen wenn man hineinläuft und den callback abarbeitet
        v_MoveFlagsDynCh |= MovementFlag::Jump;
        slime->inAir = true;

    }
    if (slime->inAir==true)
    {
        //Rotation
        p.rotate(0.5,0,360,0);
        slime->v_TransSlime->setModelMatrix(p);
    }

    slime->v_TransSlime->setModelMatrix(p);
    // character in entsprechende richtungen bewegen
    m_DynaChWithCam->moveCharacter(time, v_MoveFlagsDynCh);
}
