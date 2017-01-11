#ifndef LEVEL_H
#define LEVEL_H

#include "drawable.h"
#include "simpleplane.h"
#include "physics.h"

class Level
{
public:
    Level(PhysicEngine *phys, Node* r);
    void setPlane();    //Eine einfache Plane fürs testen erstellen
    void buildLevel();  //Hier steht der Code für den Aufbau des Levels

    Drawable* v_Plane;
    PhysicEngine* v_PhysicEngine;
    Node* root;
};

#endif // LEVEL_H
