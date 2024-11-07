#include "common.h"

static float verticies[] = {
    1.000000, -1.000000, -1.000000,
    1.000000, -1.000000, 1.000000,
    -1.000000, -1.000000, 1.000000,
    -1.000000, -1.000000, -1.000000,
    1.000000, 1.000000, -1.000000,
    1.000000, 1.000000, 1.000000,
    -1.000000, 1.000000, 1.000000,
    -1.000000, 1.000000, -1.000000
};

static const int vCount = 24;

static int indicies[] = {
    1, 2, 3,
    7, 6, 5,
    4, 5, 1,
    5, 6, 2,
    2, 6, 7,
    0, 3, 5,
    0, 1, 3,
    4, 7, 5,
    0, 4, 1,
    1, 5, 2,
    3, 2, 7,
    4, 0, 7
};

static const int iCount = 36;

struct modelStruct cube1 = {vCount, verticies, iCount, indicies, (vec4){-1.5, 0, 3, 0}, (vec4){0, 0, 0, 0}, (vec4){1, 1, 1, 1}};
struct modelStruct cube2 = {vCount, verticies, iCount, indicies, (vec4){1.5, 0, 3, 0}, (vec4){0, 0, 0, 0}, (vec4){1, 1, 1, 1}};

double lastTime = 0;


void update(){
    // Called every frame
    // Gets events, clears the screen, and swaps buffers

    struct modelStruct modelList[] = {cube1, cube2};

    // Get events
    glfwPollEvents();

    // Clear the window
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    handleInput();

    double time = (double)clock() / CLOCKS_PER_SEC;
    double deltaTime = time - lastTime;
    lastTime = time;

    for (int i = 0; i < SIZE_OF_ARRAY(modelList); i++){
        bufferData(modelList[i].v, modelList[i].vCount * sizeof(float), modelList[i].i, modelList[i].iCount * sizeof(int));

        registerUniformMat4(makeScaleMatrix(modelList[i].scale), "modelScaleMatrix", window.shader);
        registerUniformMat4(makeRotationMatrix(modelList[i].rotation), "modelRotationMatrix", window.shader);
        registerUniformMat4(makeTranslationMatrix(modelList[i].position), "modelTranslationMatrix", window.shader);

        registerUniformMat4(makeRotationMatrix(window.cameraRotation), "cameraRotationMatrix", window.shader);
        registerUniformMat4(makeTranslationMatrix((vec4){-window.cameraPosition.x, -window.cameraPosition.y, -window.cameraPosition.z, window.cameraPosition.w}), "cameraTranslationMatrix", window.shader);
        
        registerUniformMat4(makeProjectionMatrix(90, 0.1, 1000), "projectionMatrix", window.shader);

        glUseProgram(window.shader);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // Activate VAO
        glBindVertexArray(window.vao);

        // Draw the elements
        glDrawElements(GL_TRIANGLES, modelList[i].iCount, GL_UNSIGNED_INT, 0);
    }

    // Swap buffers
    glfwSwapBuffers(window.handle);
}