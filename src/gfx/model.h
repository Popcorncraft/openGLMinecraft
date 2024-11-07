#ifndef MODEL_H
#define MODEL_H

#include "common.h"

struct modelStruct{
    int vCount;
    float *v;

    int iCount;
    int *i;

    vec4 position;
    vec4 rotation;
    vec4 scale;
};

//struct modelStruct loadModel(char *path);

#endif