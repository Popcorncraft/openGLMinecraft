#include "common.h"

void registerUniformMat4(mat4 matrix, char name[], unsigned int shader){

    int matrixLocation = glGetUniformLocation(shader, name);

    glUseProgram(shader);

    glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, matrix.m[0]);
}

void registerUniformVec4(vec4 vec, char name[], unsigned int shader){

    int vecLocation = glGetUniformLocation(shader, name);

    glUseProgram(shader);

    glUniform4f(vecLocation, vec.x, vec.y, vec.z, vec.w);
}