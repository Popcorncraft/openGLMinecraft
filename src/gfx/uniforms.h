#ifndef UNIFORMS_H
#define UNIFORMS_H

#include "common.h"

void registerUniformMat4(mat4 matrix, char name[], unsigned int shader);
void registerUniformVec4(vec4 vec, char name[], unsigned int shader);

#endif