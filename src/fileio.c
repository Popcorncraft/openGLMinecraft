#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include "fileio.h"

char* fileToBuff(char *file){
    // File "id"
    FILE *fd;
    // Length of file
    long length;
    // Output
    char *buffer;

    // Create file descriptor
    fd = fopen(file, "rb");
    // Ensure fd was properly opened
    if (!fd){
        return NULL;
    }

    // Set "cursor" to end of file
    fseek(fd, 0, SEEK_END);
    // Read position of "cursor"
    length = ftell(fd);

    // Allocate a buffer of length + 1
    buffer = (char*)malloc(length+1);

    // Set "cursor" to begining
    fseek(fd, 0, SEEK_SET);

    // Read file to buffer
    fread(buffer, length, 1, fd);
    // Add null termination
    buffer[length] = 0;

    // Close file
    fclose(fd);

    // Return the file buffer
    return buffer;
}

unsigned int compileShader(char *path, enum shaderType type){
    // Turn shader source file into buffer
    char *shaderSource = fileToBuff(path);
    // Create subShader ID
    unsigned int subShader = 0;
    // Set ID to relevant type
    if (type == VERTEX){
        subShader = glCreateShader(GL_VERTEX_SHADER);
    }
    else if (type == FRAGMENT){
        subShader = glCreateShader(GL_FRAGMENT_SHADER);
    }
    else if (type == GEOMETRY){
        subShader = glCreateShader(GL_GEOMETRY_SHADER);
    }
    else {
        printf("NOT VALID SHADER TYPE");
    }

    // Input source to shader
    glShaderSource(subShader, 1, (const GLchar**)&shaderSource, NULL);
    // Compile shader
    glCompileShader(subShader);
    // Free the shader source buffer
    free(shaderSource);

    // Setup error handling variables
    int success = 0;
    char infoLog[512];
    // Check to see if shader was compiled successfully
    glGetShaderiv(subShader, GL_COMPILE_STATUS, &success);
    // If not compiled successfully get the error message and print an error
    if(!success){
        glGetShaderInfoLog(subShader, 512, NULL, infoLog);
        if (type == VERTEX){
            printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
        }
        else if (type == FRAGMENT){
            printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
        }
        else if (type == GEOMETRY){
            printf("ERROR::SHADER::GEOMETRY::COMPILATION_FAILED\n%s\n", infoLog);
        }
    }
    else{
        if (type == VERTEX){
            printf("Vertex Shader Compiled\n");
        }
        else if (type == FRAGMENT){
            printf("Fragment Shader Compiled\n");
        }
        else if (type == GEOMETRY){
            printf("Geometry Shader Compiled\n");
        }
    }
    return subShader;
}

void addShader(unsigned int shaderProgram, char *shaderPath, enum shaderType shaderType){
    unsigned int subShader = compileShader(shaderPath, shaderType);

    glAttachShader(shaderProgram , subShader);
    glDeleteShader(subShader);
}


