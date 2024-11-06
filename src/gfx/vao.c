#include "common.h"

void setupBuffers(){
    // Set the VAO id as a VAO
    glGenVertexArrays(1, &window.vao);

    // Set the VBO id as a VBO
    glGenBuffers(1, &window.vbo);
    // Set the EBO id as an EBO
    glGenBuffers(1, &window.ebo);
}

void bufferData(float verticies[], unsigned int verticiesSize, unsigned int indicies[], unsigned int indiciesSize){
    // INSTRUCTIONS: bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s).
    // Make VAO the current Vertex Array
    glBindVertexArray(window.vao);

    // Make VBO current Vertex Buffer
    glBindBuffer(GL_ARRAY_BUFFER, window.vbo);
    // Add the verticies array to the Vertex Buffer
    glBufferData(GL_ARRAY_BUFFER, verticiesSize, verticies, GL_STATIC_DRAW);

    // Make EBO current Element Buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, window.ebo);
    // Add the indicies to the Element Buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiciesSize, indicies, GL_STATIC_DRAW);

    // Specify how the Vertex Data is stored
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // Enable the Vertex Attribute
    glEnableVertexAttribArray(0);
}