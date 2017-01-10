#include "opengl.h"
#include "scene.h"
#include "modeltransformation.h"
#include "keyboardtransformation.h"
#include "color.h"
#include "simplecube.h"
#include "simpleplane.h"
#include "simplesphere.h"
#include "trianglemesh.h"
#include "texture.h"
#include "charakter.h"
#include "mainwindow.h"
#include "scenemanager.h"
#include "screenrenderer.h"
#include "shadermanager.h"
#include "texture.h"
#include "shader.h"

#include "cslime.h"

Node* initScene1();

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

Node* initScene1()
{


    QString path(SRCDIR);

    // Physic Engine Erzeugen und einen Pointer auf Instanz holen
    int v_Slot = PhysicEngineManager::createNewPhysicEngineSlot(PhysicEngineName::BulletPhysicsLibrary);
    PhysicEngine* v_PhysicEngine = PhysicEngineManager::getPhysicEngineBySlot(v_Slot);
    Node* root = new Node;

    //Slime erzeugen
    CSlime* slime = new CSlime(v_PhysicEngine);

    root->addChild(new Node(slime->getSlimeMesh()));


    // Character Ticker der für die Steuerung unser Charaktere veranwortlich ist
    new CharacterTicker(slime->v_CharacterWithCam);

    // Simple Plane laden
    Drawable* v_Plane = new Drawable(new SimplePlane(20.f));
    v_Plane->getProperty<ModelTransformation>()->rotate(90, 1.f, 0.f, 0.f);
    v_Plane->setStaticGeometry(true); // Der Oberfläche ein statisches verhalten zuweisen
    PhysicObject* v_PlanePhys = v_PhysicEngine->createNewPhysicObject(v_Plane);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BoxAABB); // Automatische generierung einer Box
    v_PlanePhys->setConstructionInfo(v_Constrinf);
    v_PlanePhys->registerPhysicObject();

    root->addChild(new Node(v_Plane));
    return root;
}
