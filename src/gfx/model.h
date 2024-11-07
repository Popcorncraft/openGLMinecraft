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

void loadModel(char *path, struct modelStruct *model);
void registerModel(char *path, vec4 position, vec4 rotation, vec4 scale);

#endif