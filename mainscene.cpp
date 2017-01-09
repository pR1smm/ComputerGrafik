#include "opengl.h"
#include "scenemanager.h"
#include "transformation.h"
#include "keyboardtransformation.h"
#include "mainwindow.h"
#include "controllablecamera.h"
#include "screenrenderer.h"
#include "trianglemesh.h"
#include "texture.h"
#include "shader.h"
#include "listener.h"
#include "shadermanager.h"

Node* initScene1();

void SceneManager::initScenes()
{
    ControllableCamera* cam = new ControllableCamera();
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
    //Objekte anlegen
    QString path(SRCDIR); //aus .pro-File!

    Node *root = new Node();

    //Geometrien können mehrfach verwendet werden -> gleiche Geometrie, anderes Erscheinungsbild
     Geometry* g = new TriangleMesh(path + QString("/modelstextures/ogrehead.obj"));
    Drawable* model = new Drawable(g);
    Texture* t;
    Shader* s = ShaderManager::getShader(path + QString("/shader/texture.vert"), path + QString("/shader/texture.frag"));
    Transformation *pos = new Transformation();

    // Nodes anlegen
    Node* posNode = new Node(pos);
    Node* modelNode = new Node(model);

    //Texturen laden
    t = model->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/ogrehead_diffuse.png"));

    //Shader fuer Textur setzen
    model->setShader(s);

    // Baum aufbauen
    root->addChild(posNode);
    posNode->addChild(modelNode);

    return(root);
}
