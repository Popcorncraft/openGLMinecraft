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

static int vCount = 24;

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

static int iCount = 36;

void update(){
    // Called every frame
    // Gets events, clears the screen, and swaps buffers

    // Get events
    glfwPollEvents();

    // Clear the window
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    handleInput();

    float *wverticies = verticies;
    int *windicies = indicies;

    bufferData(wverticies, sizeof(float) * vCount, windicies, sizeof(int) * iCount);

    //printStats();

    float time = (float)clock() / CLOCKS_PER_SEC;

    // (sin(time) + 1) / 2 * 45

    window.modelRotation.x = time * 45;



    registerUniformMat4(makeScaleMatrix(window.modelScale), "modelScaleMatrix", window.shader);
    registerUniformMat4(makeRotationMatrix(window.modelRotation), "modelRotationMatrix", window.shader);
    registerUniformMat4(makeTranslationMatrix(window.modelTranslation), "modelTranslationMatrix", window.shader);

    registerUniformMat4(makeRotationMatrix(window.cameraRotation), "cameraRotationMatrix", window.shader);
    registerUniformMat4(makeTranslationMatrix((vec4){-window.cameraPosition.x, -window.cameraPosition.y, -window.cameraPosition.z, window.cameraPosition.w}), "cameraTranslationMatrix", window.shader);

    registerUniformMat4(makeProjectionMatrix(90, 0.1, 1000), "projectionMatrix", window.shader);

    glUseProgram(window.shader);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Activate VAO
    glBindVertexArray(window.vao);

    // Draw the elements
    glDrawElements(GL_TRIANGLES, SIZE_OF_ARRAY(indicies), GL_UNSIGNED_INT, 0);

    // Swap buffers
    glfwSwapBuffers(window.handle);
}