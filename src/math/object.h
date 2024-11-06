#ifndef OBJECT_H
#define OBJECT_H

#include "common.h"

#include "gfx/model.h"

struct object{
    vec4 scale;
    vec4 rotation;
    vec4 translation;
    struct modelStruct model;
};


#endif