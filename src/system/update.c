#include "common.h"

static float verticies[] = {
     1.000000, -1.000000, -1.000000, 1.000000,          1.000000, 1.000000, 1.000000, 1.000000,
     1.000000, -1.000000,  1.000000, 1.000000,          1.000000, 1.000000, 1.000000, 1.000000,
    -1.000000, -1.000000,  1.000000, 1.000000,          1.000000, 1.000000, 1.000000, 1.000000,
    -1.000000, -1.000000, -1.000000, 1.000000,          1.000000, 1.000000, 1.000000, 1.000000,
     1.000000,  1.000000, -1.000000, 1.000000,          1.000000, 1.000000, 1.000000, 1.000000,
     1.000000,  1.000000,  1.000000, 1.000000,          1.000000, 1.000000, 1.000000, 1.000000,
    -1.000000,  1.000000,  1.000000, 1.000000,          1.000000, 1.000000, 1.000000, 1.000000,
    -1.000000,  1.000000, -1.000000, 1.000000,          1.000000, 1.000000, 1.000000, 1.000000
};

static vec4 normals[] = {
     0.000000, -1.000000,  0.000000, 1.000000,
     0.000000,  1.000000,  0.000000, 1.000000,
     1.000000,  0.000000,  0.000000, 1.000000,
    -0.000000,  0.000000,  1.000000, 1.000000,
    -1.000000, -0.000000, -0.000000, 1.000000,
     0.000000,  0.000000, -1.000000, 1.000000
};

static int indicies[] = {
    1, 2, 3,
    7, 6, 5,
    4, 5, 1,
    5, 6, 2,
    2, 6, 7,
    0, 3, 7,
    0, 1, 3,
    4, 7, 5,
    0, 4, 1,
    1, 5, 2,
    3, 2, 7,
    4, 0, 7
};

struct modelStruct cube1 = {SIZE_OF_ARRAY(verticies), verticies, SIZE_OF_ARRAY(indicies), indicies, (vec4){-1.5, 0, 3, 0}, (vec4){0, 0, 0, 0}, (vec4){1, 1, 1, 1}};
struct modelStruct cube2 = {SIZE_OF_ARRAY(verticies), verticies, SIZE_OF_ARRAY(indicies), indicies, (vec4){1.5, 0, 3, 0}, (vec4){0, 0, 0, 0}, (vec4){1, 1, 1, 1}};

double lastTime = 0;


void update(){
    // Called every frame
    // Gets events, clears the screen, and swaps buffers
    glEnable(GL_DEPTH_TEST);

    struct modelStruct modelList[] = {cube1, cube2};

    // Get events
    glfwPollEvents();

    // Clear the window
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    handleInput();

    double time = (double)clock() / CLOCKS_PER_SEC;
    double deltaTime = time - lastTime;
    lastTime = time;

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

        registerUniformMat4(makeScaleMatrix(window.models[i].scale), "modelScaleMatrix", window.shader);
        registerUniformMat4(makeRotationMatrix(window.models[i].rotation), "modelRotationMatrix", window.shader);
        registerUniformMat4(makeTranslationMatrix(window.models[i].position), "modelTranslationMatrix", window.shader);

        registerUniformMat4(makeRotationMatrix(window.cameraRotation), "cameraRotationMatrix", window.shader);
        registerUniformMat4(makeTranslationMatrix((vec4){-window.cameraPosition.x, -window.cameraPosition.y, -window.cameraPosition.z, window.cameraPosition.w}), "cameraTranslationMatrix", window.shader);
        
        registerUniformMat4(makeProjectionMatrix(90, 0.1, 1000), "projectionMatrix", window.shader);

        glUseProgram(window.shader);

        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // Activate VAO
        glBindVertexArray(window.vao);

        // Draw the elements
        glDrawElements(GL_TRIANGLES, window.models[i].iCount, GL_UNSIGNED_INT, 0);
    }

    // Swap buffers
    glfwSwapBuffers(window.handle);
}