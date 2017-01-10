#ifndef CHARAKTER_H
#define CHARAKTER_H


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

class Charakter
{
public:
    Charakter();
    ~Charakter();
    KeyboardTransformation *ogerPfad = new KeyboardTransformation();
};

#endif // CHARAKTER_H
