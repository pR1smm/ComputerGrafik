#include "level.h"

#include "modeltransformation.h"

Level::Level(PhysicEngine* phys, Node* r)
{
    v_PhysicEngine = phys;
    root = r;
    buildLevel();
}

void Level::setPlane(){
    // Simple Plane laden
    v_Plane = new Drawable(new SimplePlane(200.f));
    v_Plane->getProperty<ModelTransformation>()->rotate(90, 1.f, 0.f, 0.f);
    v_Plane->setStaticGeometry(true); // Der Oberfläche ein statisches verhalten zuweisen
    PhysicObject* v_PlanePhys = v_PhysicEngine->createNewPhysicObject(v_Plane);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BoxAABB); // Automatische generierung einer Box
    v_PlanePhys->setConstructionInfo(v_Constrinf);
    v_PlanePhys->setRestitution(0.0f);
    v_PlanePhys->registerPhysicObject();
    root->addChild(new Node(v_Plane));
}

void Level::buildLevel(){
    setPlane();
    setLuefter();
}

void Level::setLuefter(){
    QString path(SRCDIR);

    Drawable *model = new Drawable(new TriangleMesh(path+QString("/modelstextures/lueftungskasten.obj")));
    Texture* t;
    Shader* s = ShaderManager::getShader(path + QString("/shader/texture.vert"), path + QString("/shader/texture.frag"));
    Transformation *pos = new Transformation();

    Node* posNode = new Node(pos);
    Node* modelNode = new Node(model);

    //Texturen laden
    t = model->getProperty<Texture>();
    t->loadPicture(path + QString("/modelstextures/lueftungskasten/None_Base_Color.png"));

    //Shader fuer Textur setzen
    model->setShader(s);

    pos->translate(2,0,1);

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

void Level::setRoof()
{
    QString path(SRCDIR);
    Geometry* g = new TriangleMesh(path + QString("/modelstextures/skyscraper1.obj"));
    Drawable* model = new Drawable(g);
    Texture* t;
    Shader* s = ShaderManager::getShader(path + QString("/shader/texture.vert"), path + QString("/shader/texture.frag"));

    model->setStaticGeometry(true);
    PhysicObject* modelPhys= v_PhysicEngine->createNewPhysicObject(model);
    PhysicObjectConstructionInfo* v_Constrinf = new PhysicObjectConstructionInfo();
    v_Constrinf->setCollisionHull(CollisionHull::BoxAABB); // Automatische generierung einer Box
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
