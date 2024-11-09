#ifndef MODELMATRIX_H
#define MODELMATRIX_H

mat4 makeTranslationMatrix(vec4 translation);
mat4 makeRotationMatrix(vec4 rotation);
mat4 makeScaleMatrix(vec4 scale);
mat4 makeProjectionMatrix(float fov, float nearPlane, float farPlane);

#endif