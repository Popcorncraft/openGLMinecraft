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

#endif