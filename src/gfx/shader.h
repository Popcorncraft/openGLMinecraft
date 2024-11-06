#ifndef SHADER_H
#define SHADER_H

enum shaderType{
    VERTEX = 0,
    FRAGMENT = 1
};

unsigned int compileShader(char *path, enum shaderType type);
unsigned int createShaderProgram(char *vertexPath, char *fragmentPath);

#endif