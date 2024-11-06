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

static int indicies[] = {
    2, 3, 4,
    8, 7, 6,
    5, 6, 2,
    6, 7, 3,
    3, 7, 8,
    1, 4, 6,
    1, 2, 4,
    5, 8, 6,
    1, 5, 2,
    2, 6, 3,
    4, 3, 8,
    5, 1, 8
};

void update(){
    handleInput();

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
}