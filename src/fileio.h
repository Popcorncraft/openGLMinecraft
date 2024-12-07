#ifndef FILEIO_H
#define FILEIO_H

enum shaderType{
    VERTEX = 0,
    FRAGMENT = 1,
    GEOMETRY = 2
};

char* fileToBuff(char *file);
void addShader(unsigned int shaderProgram, char *shaderPath, enum shaderType shaderType);

#endif