#include "mainscene.h"
//Unsere eigenen Klassen
#include "cslime.h"

//Globale Variablen
Node* initScene1();
int v_Slot;
PhysicEngine* v_PhysicEngine;
Node* root;
CSlime* slime;
Level* level;
SunLight* light1;

QString path(SRCDIR);

void SceneManager::initScenes()
{
    Camera* cam = new Camera;
    RenderingContext* myContext = new RenderingContext(cam);
    unsigned int myContextNr = SceneManager::instance()->addContext(myContext);
    unsigned int myScene = SceneManager::instance()->addScene(initScene1());
    ScreenRenderer* myRenderer = new ScreenRenderer(myContextNr, myScene);
    Q_UNUSED(myRenderer);

    // Vorsicht: Die Szene muss initialisiert sein, bevor das Fenster verändert wird (Fullscreen)
    SceneManager::instance()->setActiveScene(myScene);
    SceneManager::instance()->setActiveContext(myContextNr);
        SceneManager::instance()->setFullScreen();
}
void init(){
    light1 = new SunLight;
    // Physic Engine Erzeugen und einen Pointer auf Instanz holen
    PhysicEngineManager::createNewPhysicEngineSlot(PhysicEngineName::BulletPhysicsLibrary);
    v_PhysicEngine = PhysicEngineManager::getPhysicEngineBySlot(v_Slot);
    root = new Node(light1);

    light1->setDiffuse(0.7f, 0.7f, 0.7f);
    light1->setSpecular(0.6f, 0.6f, 0.6f);
    light1->setAmbient(0.6f, 0.6f, 0.6f);
    light1->turnOn();
}

Node* initScene1()
{
    //Initialisiert globale Variablen
    init();

    //Erstellt das Level
    level = new Level(v_PhysicEngine, root);

    //Slime erzeugen und als Kind von root anlegen
    slime = new CSlime(v_PhysicEngine);
    root->addChild(new Node(slime->getSlimeMesh()));
    return root;
}

