#ifndef CSLIME_H
#define CSLIME_H
#pragma once
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

class CSlime
{
public:
    CSlime(PhysicEngine* eng);
    Drawable* v_Slime;
    ModelTransformation* v_TransSlime;
    Texture *t;
    Shader *s;
    PhysicEngine* v_PhysicEngine;
    DynamicCharacterWithCam* v_CharacterWithCam;
    Drawable* getSlimeMesh();

    bool inAir;
};

#endif // CSLIME_H
