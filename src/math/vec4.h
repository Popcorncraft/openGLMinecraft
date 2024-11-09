#ifndef VEC4_H
#define VEC4_H

typedef union {
    float raw[4];
    struct{
        float x;
        float y;
        float z;
        float w;
    };
    struct{
        float r;
        float g;
        float b;
        float a;
    };
    struct{
        float yaw;
        float pitch;
        float roll;
    };
}vec4;

float getLength(vec4 v);
vec4 normalize(vec4 v);
vec4 crossProduct(vec4 v1, vec4 v2);
vec4 addVec(vec4 v1, vec4 v2);
vec4 scaleVec(vec4 v, float s);
vec4 multVecMat(vec4 v, mat4 m);

#endif