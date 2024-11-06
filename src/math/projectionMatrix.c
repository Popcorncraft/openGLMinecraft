#include "common.h"

mat4 makeProjectionMatrix(float fov, float nearPlane, float farPlane){
    mat4 o = makeIdentityMatrix();

    float aspectRatio = (float)window.size.height / (float)window.size.width;

    float fovScale = 1 / tanf(fov * PI / 180 / 2);

    o.m[0][0] = aspectRatio * fovScale;
    o.m[1][1] = fovScale;
    o.m[2][2] = (farPlane) / (farPlane - nearPlane);
    o.m[3][2] = (-farPlane * nearPlane) / (farPlane - nearPlane);
    o.m[2][3] = 1;
    //o.m[3][3] = 0;

    return o;
}