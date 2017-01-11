#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "trianglemesh.h"
#include "scenemanager.h"
#include "screenrenderer.h"
#include "shadermanager.h"
#include "texture.h"
#include "shader.h"

class GameObject
{
public:
    GameObject();
    char name[50];
    Drawable* drawabel;
    Texture *t;
    Shader *s;
    PhysicEngine* v_PhysicEngine;

    Drawable* getMesh();
};

#endif // GAMEOBJECT_H
