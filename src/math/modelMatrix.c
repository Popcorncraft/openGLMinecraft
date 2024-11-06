#include "common.h"

mat4 makeTranslationMatrix(vec4 translation){
    mat4 o = makeIdentityMatrix();

    o.m[3][0] = translation.x;
    o.m[3][1] = translation.y;
    o.m[3][2] = translation.z;

    return o;
}

mat4 makeRotationMatrix(vec4 rotation){
    mat4 o = makeIdentityMatrix();
    mat4 x = makeIdentityMatrix();
    mat4 y = makeIdentityMatrix();
    mat4 z = makeIdentityMatrix();

    vec4 radRotation = {rotation.x * PI / 180, rotation.y * PI / 180, rotation.z * PI / 180, 1};

    x.m[1][1] = cosf(radRotation.x);
    x.m[2][2] = cosf(radRotation.x);
    x.m[1][2] = -sinf(radRotation.x);
    x.m[2][1] = sinf(radRotation.x);

    y.m[0][0] = cosf(radRotation.y);
    y.m[2][2] = cosf(radRotation.y);
    y.m[0][2] = sinf(radRotation.y);
    y.m[2][0] = -sinf(radRotation.y);

    z.m[0][0] = cosf(radRotation.z);
    z.m[1][1] = cosf(radRotation.z);
    z.m[0][1] = -sinf(radRotation.z);
    z.m[1][0] = sinf(radRotation.z);
    
    o = multiplyMatricies(o, z);
    o = multiplyMatricies(o, y);
    o = multiplyMatricies(o, x);

    return o;
}

mat4 makeScaleMatrix(vec4 scale){
    mat4 o = makeIdentityMatrix();

    o.m[0][0] = scale.x;
    o.m[1][1] = scale.y;
    o.m[2][2] = scale.z;

    return o;
}