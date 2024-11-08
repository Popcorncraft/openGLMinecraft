#include "common.h"

struct timespec lastTime;

void update(){
    // Called every frame
    // Gets events, clears the screen, and swaps buffers
    glEnable(GL_DEPTH_TEST);

    // Get events
    glfwPollEvents();

    // Clear the window
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    handleInput();

    for (int i = 0; i < window.modelCount; i++){
        // INSTRUCTIONS: bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attribute(s).
        // Make VAO the current Vertex Array
        glBindVertexArray(window.vao);

        // Make VBO current Vertex Buffer
        glBindBuffer(GL_ARRAY_BUFFER, window.vbo);
        // Add the verticies array to the Vertex Buffer
        glBufferData(GL_ARRAY_BUFFER, window.models[i].vCount * sizeof(float), window.models[i].v, GL_STATIC_DRAW);

        // Make EBO current Element Buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, window.ebo);
        // Add the indicies to the Element Buffer
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, window.models[i].iCount * sizeof(int), window.models[i].i, GL_STATIC_DRAW);

        // Specify how the Vertex Data is stored
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        // Enable the Vertex Attribute
        glEnableVertexAttribArray(0);

        // Specify how the Vertex Data is stored
        //glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4 * sizeof(float)));
        // Enable the Vertex Attribute
        //glEnableVertexAttribArray(1);

        glUseProgram(window.shader);

        registerUniformMat4(makeScaleMatrix(window.models[i].scale), "modelScaleMatrix", window.shader);
        registerUniformMat4(makeRotationMatrix(window.models[i].rotation), "modelRotationMatrix", window.shader);
        registerUniformMat4(makeTranslationMatrix(window.models[i].position), "modelTranslationMatrix", window.shader);

        registerUniformMat4(makeRotationMatrix(window.cameraRotation), "cameraRotationMatrix", window.shader);
        registerUniformMat4(makeTranslationMatrix((vec4){-window.cameraPosition.x, -window.cameraPosition.y, -window.cameraPosition.z, window.cameraPosition.w}), "cameraTranslationMatrix", window.shader);
        
        registerUniformMat4(makeProjectionMatrix(90, 0.1, 1000), "projectionMatrix", window.shader);

        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // Activate VAO
        glBindVertexArray(window.vao);

        // Draw the elements
        glDrawElements(GL_TRIANGLES, window.models[i].iCount, GL_UNSIGNED_INT, 0);
    }

    // Swap buffers
    glfwSwapBuffers(window.handle);
    //glfwSetWindowShouldClose(window.handle, 1);
}