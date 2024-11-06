#ifndef MODEL_H
#define MODEL_H

struct modelStruct{
    int vCount;
    float v[24];

    int iCount;
    int i[36];
};

struct modelStruct loadModel(char *path);

#endif