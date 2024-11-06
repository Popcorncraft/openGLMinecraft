#include "common.h"

void registerUniformMat4(mat4 matrix, char name[], unsigned int shader){

    int matrixLocation = glGetUniformLocation(shader, name);

    glUseProgram(shader);

    glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, matrix.m[0]);
}