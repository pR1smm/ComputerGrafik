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
     //v_Slime->getPhysicObject()->setRestitution(0.1f);

     // Character Objekt erzeugen mit einer Verfolgerkamera
     v_CharacterWithCam = v_PhysicEngine->createNewDynamicCharacterWithCam(v_Slime);
     // Kamera anhängen, die bestimmung der kameraposition wird nun komplett von dem character übernommen, einzig allein
     // die x achsendrehung kann noch beeinflusst werden
     v_CharacterWithCam->setCam(SceneManager::instance()->getActiveContext()->getCamera());
     // Relative Kameraposition zum Drawable setzen
     v_CharacterWithCam->setRelativeCamPosition(0.f, 2.f, 20.f);
     v_CharacterWithCam->setUpDownView(-5.0F);

     //Elastizität setzen, damit die Objegte nicht rum buggen
     v_Slime->getPhysicObject()->setRestitution((0.0));


     //Objekt in der Physik engine registrieren
     v_Slime->getPhysicObject()->registerPhysicObject();

     // Character Ticker der für die Steuerung unser Charaktere veranwortlich ist
     SlimeTicker* ticker = new SlimeTicker(v_CharacterWithCam, this);


     //Calback für Colisionserkenung erstellen
     TryCallback* callback = new TryCallback(this);

     // CallbackReceiver erzeugen der für ein Object der Klasse TryCallback
     SpecificResponseObject<TryCallback>* v_CallbackReceiver =
       new SpecificResponseObject<TryCallback>(callback, &TryCallback::callback);
     // Der Oberfläche den Callback hinzufügen welcher bei einer Collision ausgeführt wird
     // Der Callback wird außerdem nur für das Object aufgerufen an das es angehangen wurde
     v_Slime->getPhysicObject()->addResponseObject(v_CallbackReceiver);
}
//getter
Drawable* CSlime::getSlimeMesh(){ return v_Slime;}
