#include "common.h"

float getLength(vec4 v){
    return (sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2)));
}

vec4 normalize(vec4 v){
    float l = getLength(v);
    return ((vec4){v.x / l, v.y / l, v.z / l, v.w});
}

vec4 crossProduct(vec4 v1, vec4 v2){
    v1 = normalize(v1);
    v2 = normalize(v2);
    vec4 o;
    o.x = v1.y * v2.z - v1.z * v2.y;
    o.y = v1.z * v2.x - v1.x * v2.z;
    o.z = v1.x * v2.y - v1.y * v2.x;
    o.w = 1;
    return o;
}

vec4 addVec(vec4 v1, vec4 v2){
    return ((vec4){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w});
}

vec4 scaleVec(vec4 v, float s){
    return ((vec4){v.x * s, v.y * s, v.z * s, v.w * s, });
}

vec4 multVecMat(vec4 v, mat4 m){
    vec4 o;

    o.x = v.x * m.m[0][0] + v.y * m.m[0][1] + v.z * m.m[0][2] + v.w * m.m[0][3];
    o.y = v.x * m.m[1][0] + v.y * m.m[1][1] + v.z * m.m[1][2] + v.w * m.m[1][3];
    o.z = v.x * m.m[2][0] + v.y * m.m[2][1] + v.z * m.m[2][2] + v.w * m.m[1][3];
    o.w = v.x * m.m[3][0] + v.y * m.m[3][1] + v.z * m.m[3][2] + v.w * m.m[3][3];

    return o;
}