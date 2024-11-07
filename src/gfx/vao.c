#include "common.h"

void setupBuffers(){
    // Set the VAO id as a VAO
    glGenVertexArrays(1, &window.vao);

    // Set the VBO id as a VBO
    glGenBuffers(1, &window.vbo);
    // Set the EBO id as an EBO
    glGenBuffers(1, &window.ebo);
}