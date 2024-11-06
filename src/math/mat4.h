#ifndef MAT4_H
#define MAT4_H

typedef struct mat4{
    float m[4][4];
}mat4;

mat4 makeIdentityMatrix();
mat4 multiplyMatricies(mat4 a, mat4 b);

#endif