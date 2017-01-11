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
    //    SceneManager::instance()->setFullScreen();
}
void init(){
    // Physic Engine Erzeugen und einen Pointer auf Instanz holen
    PhysicEngineManager::createNewPhysicEngineSlot(PhysicEngineName::BulletPhysicsLibrary);
    v_PhysicEngine = PhysicEngineManager::getPhysicEngineBySlot(v_Slot);
    root = new Node;
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

