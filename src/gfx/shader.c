#include <stdio.h>

#include "common.h"

unsigned int compileShader(char *path, enum shaderType type){
    // Turn shader source file into buffer
    char *shaderSource = filetobuf(path);
    // Create subShader ID
    unsigned int subShader = 0;
    // Set ID to relevant type
    switch(type){
        case VERTEX:
            subShader = glCreateShader(GL_VERTEX_SHADER);
            break;
        case FRAGMENT:
            subShader = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        case GEOMETRY:
            subShader = glCreateShader(GL_GEOMETRY_SHADER);
            break;
        default:
            printf("NOT VALID SHADER TYPE");
            break;
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
        switch(type){
            case VERTEX:
                printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
                break;
            case FRAGMENT:
                printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
                break;
            case GEOMETRY:
                printf("ERROR::SHADER::GEOMETRY::COMPILATION_FAILED\n%s\n", infoLog);
                break;
        }
    }
    else{
        switch(type){
            case VERTEX:
                printf("Vertex Shader Compiled\n");
                break;
            case FRAGMENT:
                printf("Fragment Shader Compiled\n");
                break;
            case GEOMETRY:
                printf("Geometry Shader Compiled\n");
                break;
        }
    }
    return subShader;
}

unsigned int createShaderProgram(char *vertexPath, char *fragmentPath, char *geometryPath){

    unsigned int vertexShader = compileShader(vertexPath, VERTEX);
    unsigned int fragmentShader = compileShader(fragmentPath, FRAGMENT);
    unsigned int geometryShader = compileShader(geometryPath, GEOMETRY);
    
    unsigned int shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glAttachShader(shaderProgram, geometryShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(geometryShader);

    return(shaderProgram);
}