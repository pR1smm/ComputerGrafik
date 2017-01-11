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
    v_Plane = new Drawable(new SimplePlane(20.f));
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
}
