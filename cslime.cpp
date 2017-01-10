#include "cslime.h"

CSlime::CSlime(PhysicEngine *eng)
{
    QString path(SRCDIR);

    v_PhysicEngine = eng;

    //slime mesh erzeugen
     v_Slime = new Drawable(new TriangleMesh(path+QString("/modelstextures/slimey.obj")));


     //shader laden
     s = ShaderManager::getShader(path + QString("/shader/texture.vert"), path + QString("/shader/texture.frag"));

     //textur setzen
     t=v_Slime->getProperty<Texture>();
     t->loadPicture(path+QString("/modelstextures/Slimey_texture.png"));

     //shader setzen
     v_Slime->setShader(s);

     //transformation setzen
     v_TransSlime = v_Slime->getProperty<ModelTransformation>();
     v_TransSlime->translate(0.f, 1.f, 2.f);

     // Character Objekt erzeugen mit einer Verfolgerkamera
     v_CharacterWithCam = v_PhysicEngine->createNewDynamicCharacterWithCam(v_Slime);
     // Kamera anhängen, die bestimmung der kameraposition wird nun komplett von dem character übernommen, einzig allein
     // die x achsendrehung kann noch beeinflusst werden
     v_CharacterWithCam->setCam(SceneManager::instance()->getActiveContext()->getCamera());
     // Relative Kameraposition zum Drawable setzen
     v_CharacterWithCam->setRelativeCamPosition(0.f, 4.f, 6.f);
     v_CharacterWithCam->setUpDownView(-30.0F);


     //Objekt in der Physik engine registrieren
     v_Slime->getPhysicObject()->registerPhysicObject();

     // Character Ticker der für die Steuerung unser Charaktere veranwortlich ist
     new CharacterTicker(v_CharacterWithCam);

}




//getter
Drawable* CSlime::getSlimeMesh(){ return v_Slime;}
