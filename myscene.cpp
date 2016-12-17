#include "scenemanager.h"
#include "screenrenderer.h"
#include "controllablecamera.h"
#include "trianglemesh.h"
#include "texture.h"
#include "shader.h"
#include "listener.h"
#include "transformation.h"
#include "keyboardtransformation.h"
#include "planet.h"
#include "color.h"
#include "soundmanager.h"
#include "shadermanager.h"

//Philipp war hier auch
//Philipp war nochmal hier
//Chris war hier

Node *initScene1();
Node *initScene2();

ScreenRenderer* sortedRenderer;
ScreenRenderer* preOrderRenderer;
unsigned int myScene, myScene2;

class SceneSwitcher: public Listener
{
    void keyboard(int key, int modifier)
    {
        if (key == '1')
        {
            sortedRenderer->setScene(myScene);
            SoundManager::instance()->setVolume(50);
            SoundManager::instance()->playSound(1);
        }
        else if(key =='2')
        {
            sortedRenderer->setScene(myScene2);
            SoundManager::instance()->setVolume(100);
            SoundManager::instance()->playSound(2);
        }
        else
        {
            SoundManager::instance()->playSound(3);
        }
    }
};

void SceneManager::initScenes()
{
    SceneSwitcher* lSwitch = new SceneSwitcher();
    ControllableCamera* cam = new ControllableCamera();
    RenderingContext* myContext = new RenderingContext(cam);
    unsigned int myContextNr = SceneManager::instance()->addContext(myContext);
    myScene = SceneManager::instance()->addScene(initScene1());
    myScene2 = SceneManager::instance()->addScene(initScene2());
    sortedRenderer = new ScreenRenderer(myContextNr, myScene);
    preOrderRenderer = new ScreenRenderer(myContextNr, myScene, false);
    preOrderRenderer->setEnabled(false);
    Q_UNUSED(lSwitch);

    //Vorsicht: Die Szene muss initialisiert sein, bevor das Fenster verändert wird (Fullscreen)
//    SceneManager::instance()->setActiveScene(myScene);
//    SceneManager::instance()->setActiveContext(myContextNr);
//    SceneManager::instance()->setFullScreen();
}

Node *initScene1()
{
    //Objekte anlegen
    QString path(SRCDIR); //aus .pro-File!

	
    //Sounds initialisieren
    SoundManager::instance()->registerSound(path+QString("/sounds/Hammering.mp3"));
    SoundManager::instance()->registerSound(path+QString("/sounds/CityAmbiance.mp3"));
    SoundManager::instance()->registerSound(path+QString("/sounds/LaserCannon.mp3"));

    SoundManager::instance()->setAmbientSoundLoop(path+QString("/sounds/NatureAmbiance.mp3"));

    Node *root = new Node();
    Drawable *model2 = new Drawable(new TriangleMesh(path+QString("/modelstextures/skyCaveShip.obj")));

    //Geometrien können mehrfach verwendet werden -> gleiche Geometrie, anderes Erscheinungsbild
     Geometry* g = new TriangleMesh(path + QString("/modelstextures/ogrehead.obj"));
    Drawable* model1 = new Drawable(g);
    Drawable* model = new Drawable(g);
    Texture* t;
    Shader* s =
      ShaderManager::getShader(path + QString("/shader/texture.vert"), path + QString("/shader/texture.frag"));
    Transformation *pos = new Transformation(), *pos2 = new Transformation();

	// Nodes anlegen
    Node* model1Node = new Node(model1);
    Node* posNode = new Node(pos);
    Node* modelNode = new Node(model);
    Node* pos2Node = new Node(pos2);
    Node* model2Node = new Node(model2);
	
    model1->deactivateFill();
    //Texturen laden
    t = model->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/ogrehead_diffuse.png"));

    //Texturen laden
    t = model2->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/skyCaveShip_TEX.png"));

    //Shader fuer Textur setzen
    model->setShader(s);
    model2->setShader(s);

    pos->translate(2.0, 0.0, 0.0);
    pos2->translate(0.0, 3.0, 0.0);

    // Baum aufbauen
    root->addChild(model1Node);
    root->addChild(posNode);
    posNode->addChild(modelNode);
    root->addChild(pos2Node);
    pos2Node->addChild(model2Node);

    return(root);
}

Node *initScene2()
{
//    Objekte anlegen
    Planet* sonne = new Planet(1.0);
    KeyboardTransformation* sonnensystem = new KeyboardTransformation();
    KeyboardTransformation *erdrotation = new KeyboardTransformation();
    KeyboardTransformation *mondrotation = new KeyboardTransformation();
    Transformation *erdUmlaufbahn = new Transformation();
    Transformation *mondOrbit = new Transformation();
    Planet *meineErde = new Planet(0.2F);
    Planet *meinMond = new Planet(0.05F);
    Color *c;
    float mondspeed = 7.0, umlaufspeed=mondspeed/12.0, erdspeed=mondspeed*28.0;

	// Nodes anlegen
    Node* sonneNode = new Node(sonne);
    Node* sonnensystemNode = new Node(sonnensystem);
    Node* erdrotationNode = new Node(erdrotation);
    Node* mondrotationNode = new Node(mondrotation);
    Node* erdUmlaufbahnNode = new Node(erdUmlaufbahn);
    Node* mondOrbitNode = new Node(mondOrbit);
    Node* meineErdeNode = new Node(meineErde);
    Node* meinMondNode = new Node(meinMond);
	
    //Farben
    c = sonne->getProperty<Color>();
    c->setValue(1.0,1.0,0.0,1.0);
    c = meineErde->getProperty<Color>();
    c->setValue(0.0,0.0,1.0,1.0);
    c = meinMond->getProperty<Color>();
    c->setValue(0.7F,0.7F,0.7F,1.0F);

    //Damit man die Drehungen sieht, Gitternetz aktivieren
    sonne->deactivateFill();
    meineErde->deactivateFill();
    meinMond->deactivateFill();

    //Keys belegen
    sonnensystem->setRotKeys(KeyboardTransformation::NoKey,
                             KeyboardTransformation::NoKey,
                             'r', 'R',
                             KeyboardTransformation::NoKey,
                             KeyboardTransformation::NoKey);
    sonnensystem->setRotspeed(umlaufspeed);
    erdrotation->setRotKeys('r', 'R',
                            KeyboardTransformation::NoKey,
                            KeyboardTransformation::NoKey,
                            KeyboardTransformation::NoKey,
                            KeyboardTransformation::NoKey
                            );
    erdrotation->setRotspeed(erdspeed);
    mondrotation->setRotKeys(KeyboardTransformation::NoKey,
                            KeyboardTransformation::NoKey,
                            KeyboardTransformation::NoKey,
                            KeyboardTransformation::NoKey,
                             'r', 'R'
                             );
    mondrotation->setRotspeed(mondspeed);

    //Vorsicht beim ändern von Rot. und Trans. derselben Transformation:
    //Die Reihenfolge ist wichtig!
    sonnensystem->rotate(45.0, 1.0, 0.0, 0.0); // Neigen, damit man die Umlaufbahn besser sieht
    erdUmlaufbahn->translate(3.0, 0.0, 0.0);   // Erdumlaufbahn
    mondOrbit->translate(0.5, 0.0, 0.0);

    // Szenengraph aufbauen
    sonnensystemNode->addChild(sonneNode);
    sonneNode->addChild(erdUmlaufbahnNode);
    erdUmlaufbahnNode->addChild(erdrotationNode);
    erdUmlaufbahnNode->addChild(mondrotationNode);
    mondrotationNode->addChild(mondOrbitNode);
    mondOrbitNode->addChild(meinMondNode);
    erdrotationNode->addChild(meineErdeNode);
    return (sonnensystemNode);
}

