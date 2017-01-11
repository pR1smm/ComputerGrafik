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
#include "SlimeTicker.h"
#include "mainwindow.h"
#include "scenemanager.h"
#include "screenrenderer.h"
#include "shadermanager.h"
#include "texture.h"
#include "shader.h"
#include "trycallback.h"


#include "cslime.h"

Node* initScene1();
int v_Slot;
PhysicEngine* v_PhysicEngine;
Node* root;
CSlime* slime;
Drawable* v_Plane;
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
void setNodes(){
    root->addChild(new Node(slime->getSlimeMesh()));
    root->addChild(new Node(v_Plane));
}

void setPlane(){
    // Simple Plane laden
    v_Plane = new Drawable(new SimplePlane(20.f));
    v_Plane->getProperty<ModelTransformation>()->rotate(90, 1.f, 0.f, 0.f);
    v_Plane->setStaticGeometry(true); // Der Oberfläche ein statisches verhalten zuweisen
    PhysicObject* v_PlanePhys = v_PhysicEngine->createNewPhysicObject(v_Plane);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BoxAABB); // Automatische generierung einer Box
    v_PlanePhys->setConstructionInfo(v_Constrinf);
    v_PlanePhys->setRestitution(0.0f);
    v_PlanePhys->registerPhysicObject();

}

Node* initScene1()
{

    //Initioalisiert globale Variablen
    init();

    //Slime erzeugen
    slime = new CSlime(v_PhysicEngine);

    //Plane erzeugen (Temporär)
    setPlane();






    //setzt die Objekte in die scene
    setNodes();
    return root;
}

