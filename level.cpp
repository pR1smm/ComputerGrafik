#include "level.h"
#include "color.h"
#include "material.h"
#include "modeltransformation.h"

Level::Level(PhysicEngine* phys, Node* r)
{
    v_PhysicEngine = phys;
    root = r;
    buildLevel();
}

void Level::setPlane(){
    // Simple Plane laden

    Color *c;
    Shader* s = ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag"));
    v_Plane = new Drawable(new SimplePlane(500,100));
    v_Plane->getProperty<ModelTransformation>()->rotate(0, 1.f, 0.f, 0.f);
    v_Plane->getProperty<ModelTransformation>()->translate(.0f, .0f, -20.0f);
    v_Plane->setStaticGeometry(true); // Der Oberfläche ein statisches verhalten zuweisen
    PhysicObject* v_PlanePhys = v_PhysicEngine->createNewPhysicObject(v_Plane);
    c = v_Plane->getProperty<Color>();
    c->setValue(.3F,0.65,0.81F,1.0F);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BoxAABB); // Automatische generierung einer Box
    v_PlanePhys->setConstructionInfo(v_Constrinf);
    v_PlanePhys->setRestitution(0.0f);
    v_PlanePhys->registerPhysicObject();
    //shader

    root->addChild(new Node(v_Plane));
}

void Level::buildLevel(){
    setPlane();

    setHaus(0,-2,0); //HAUS1
    setLuefter(3,0,0);
    setAntenne(2,0,3);
    setStromkabel(-3,0,.8);

    setHaus(20,-2,0);   //HAUS2
    setRohr(17,0,0);
    setAntenne(17,0,-3.5);
    setStromkasten(21,0,-2);

    setHaus(35,-2,0); //HAUS3
    setStromkabel(38,0,.8);
    setRohr(35,0,0);

    setHaus(50,-2,0); //HAUS 4
    setHaus(60,-2,0);
    setAntenne(55,0,3);
    setAntenne(62,0,-3.5);
    setStromkasten(60,0,-2);
}

void Level::setRohr(int x, int y, int z){
    QString path(SRCDIR);

    Drawable *model = new Drawable(new TriangleMesh(path+QString("/modelstextures/Rohr.obj")));
    Texture* t;
    Shader* s = ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag"));
    Transformation *pos = new Transformation();

    Node* posNode = new Node(pos);
    Node* modelNode = new Node(model);

    //Texturen laden
    t = model->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/Rohr/rohr_Base_Color.png"));

    //shaderanpassungen
   Material* m;
    m = model->getProperty<Material>();

    //m->setDiffuse(0.f, 0.f, 0.f, 1.f);
    //m->setAmbient(0.f, .0f, .0f, 1.f);
    //m->setSpecular(0.8f, .8f, .8f, .7f);
    m->setShininess(8.f);
    //Shader fuer Textur setzen
    model->setShader(s);

    pos->translate(x,y,z);

    model->setStaticGeometry(true);


    PhysicObject* modelPhys = v_PhysicEngine->createNewPhysicObject(model);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BoxAABB); // Automatische generierung einer Box
    modelPhys->setConstructionInfo(v_Constrinf);
    modelPhys->setRestitution(0.0f);
    modelPhys->registerPhysicObject();


    root->addChild(posNode);
    posNode->addChild(modelNode);
}

void Level::setStromkabel(int x, int y, int z){
    QString path(SRCDIR);

    Drawable *model = new Drawable(new TriangleMesh(path+QString("/modelstextures/stromkabel.obj")));
    Texture* t;
    Shader* s = ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag"));
    Transformation *pos = new Transformation();

    Node* posNode = new Node(pos);
    Node* modelNode = new Node(model);

    //Texturen laden
    t = model->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/Stromkabel/None_Base_Color.png"));

    //shaderanpassungen
   Material* m;
    m = model->getProperty<Material>();

    //m->setDiffuse(0.f, 0.f, 0.f, 1.f);
    //m->setAmbient(0.f, .0f, .0f, 1.f);
    //m->setSpecular(0.8f, .8f, .8f, .7f);
    m->setShininess(8.f);
    //Shader fuer Textur setzen
    model->setShader(s);

    pos->translate(x,y,z);

    pos->rotate(20,0,1,0);

    model->setStaticGeometry(true);


    PhysicObject* modelPhys = v_PhysicEngine->createNewPhysicObject(model);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BVHTriangleMesh); // Automatische generierung einer Box
    modelPhys->setConstructionInfo(v_Constrinf);
    modelPhys->setRestitution(0.0f);
    modelPhys->registerPhysicObject();


    root->addChild(posNode);
    posNode->addChild(modelNode);
}

void Level::setStromkasten(int x, int y, int z){
    QString path(SRCDIR);

    Drawable *model = new Drawable(new TriangleMesh(path+QString("/modelstextures/stromkasten.obj")));
    Texture* t;
    Shader* s = ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag"));
    Transformation *pos = new Transformation();

    Node* posNode = new Node(pos);
    Node* modelNode = new Node(model);

    //Texturen laden
    t = model->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/None_Base_Color.png"));

    //shaderanpassungen
   Material* m;
    m = model->getProperty<Material>();

    //m->setDiffuse(0.f, 0.f, 0.f, 1.f);
    //m->setAmbient(0.f, .0f, .0f, 1.f);
    //m->setSpecular(0.8f, .8f, .8f, .7f);
    m->setShininess(8.f);
    //Shader fuer Textur setzen
    model->setShader(s);

    pos->translate(x,y,z);

    model->setStaticGeometry(true);


    PhysicObject* modelPhys = v_PhysicEngine->createNewPhysicObject(model);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BVHTriangleMesh); // Automatische generierung einer Box
    modelPhys->setConstructionInfo(v_Constrinf);
    modelPhys->setRestitution(0.0f);
    modelPhys->registerPhysicObject();


    root->addChild(posNode);
    posNode->addChild(modelNode);
}

void Level::setLuefter(int x, int y, int z){
    QString path(SRCDIR);

    Drawable *model = new Drawable(new TriangleMesh(path+QString("/modelstextures/lueftungskasten.obj")));
    Texture* t;
    Shader* s = ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag"));
    Transformation *pos = new Transformation();

    Node* posNode = new Node(pos);
    Node* modelNode = new Node(model);

    //Texturen laden
    t = model->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/lueftungskasten/None_Base_Color.png"));

    //shaderanpassungen
   Material* m;
    m = model->getProperty<Material>();

    //m->setDiffuse(0.f, 0.f, 0.f, 1.f);
    //m->setAmbient(0.f, .0f, .0f, 1.f);
    //m->setSpecular(0.8f, .8f, .8f, .7f);
    m->setShininess(8.f);
    //Shader fuer Textur setzen
    model->setShader(s);

    pos->translate(x,y,z);

    model->setStaticGeometry(true);


    PhysicObject* modelPhys = v_PhysicEngine->createNewPhysicObject(model);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BVHTriangleMesh); // Automatische generierung einer Box
    modelPhys->setConstructionInfo(v_Constrinf);
    modelPhys->setRestitution(0.0f);
    modelPhys->registerPhysicObject();


    root->addChild(posNode);
    posNode->addChild(modelNode);
}

void Level::setAntenne(int x, int y, int z){
    QString path(SRCDIR);

    Drawable *model = new Drawable(new TriangleMesh(path+QString("/modelstextures/antenne1.obj")));
    Texture* t;
    Shader* s = ShaderManager::getShader(QString("://shaders/texture.vert"),QString("://shaders/texture.frag"));
    Transformation *pos = new Transformation();

    Node* posNode = new Node(pos);
    Node* modelNode = new Node(model);

    //Texturen laden
    t = model->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/Antenne1/None_Base_Color.png"));

    //shaderanpassungen
   Material* m;
    m = model->getProperty<Material>();

    //m->setDiffuse(0.f, 0.f, 0.f, 1.f);
    //m->setAmbient(0.f, .0f, .0f, 1.f);
    //m->setSpecular(0.8f, .8f, .8f, .7f);
    m->setShininess(8.f);
    //Shader fuer Textur setzen
    model->setShader(s);

    pos->translate(x,y,z);

    model->setStaticGeometry(true);


    PhysicObject* modelPhys = v_PhysicEngine->createNewPhysicObject(model);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BVHTriangleMesh); // Automatische generierung einer Box
    modelPhys->setConstructionInfo(v_Constrinf);
    modelPhys->setRestitution(0.0f);
    modelPhys->registerPhysicObject();


    root->addChild(posNode);
    posNode->addChild(modelNode);
}

void Level::setHaus(int x, int y, int z){
    QString path(SRCDIR);

    Drawable *model = new Drawable(new TriangleMesh(path+QString("/modelstextures/skyscraper1.obj")));
    Texture* t;
    Shader* s = ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag"));
    Transformation *pos = new Transformation();

    Node* posNode = new Node(pos);
    Node* modelNode = new Node(model);

    //Texturen laden
    t = model->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/skysraper1.png"));

    //shaderanpassungen
   Material* m;
    m = model->getProperty<Material>();

    //m->setDiffuse(0.f, 0.f, 0.f, 1.f);
    //m->setAmbient(0.f, .0f, .0f, 1.f);
    //m->setSpecular(0.8f, .8f, .8f, .7f);
    m->setShininess(8.f);
    //Shader fuer Textur setzen
    model->setShader(s);

    //pos->rotate(-90,1,0,0);

    pos->translate(x,y,z);

    model->setStaticGeometry(true);


    PhysicObject* modelPhys = v_PhysicEngine->createNewPhysicObject(model);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BVHTriangleMesh); // Automatische generierung einer Box
    modelPhys->setConstructionInfo(v_Constrinf);
    modelPhys->setRestitution(0.0f);
    modelPhys->registerPhysicObject();


    root->addChild(posNode);
    posNode->addChild(modelNode);
}

void Level::setRoof()
{
    QString path(SRCDIR);
    Geometry* g = new TriangleMesh(path + QString("/modelstextures/skyscraper1.obj"));
    Drawable* model = new Drawable(g);
    Texture* t;
    Shader* s = ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag"));

    model->setStaticGeometry(true);
    PhysicObject* modelPhys= v_PhysicEngine->createNewPhysicObject(model);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BVHTriangleMesh); // Automatische generierung einer Box
    modelPhys->setConstructionInfo(v_Constrinf);
    modelPhys->registerPhysicObject();


    Transformation* pos = new Transformation();

    pos->translate(9,0,6);
    pos->rotate(90,1,0,0);
    pos->scale(1.3,1.3,1.3);




    Node* transNode = new Node(pos);

    root->addChild(transNode);
    transNode->addChild(new Node(model));

}
