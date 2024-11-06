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

void init(){
    for (int i = 0; i < MAX_KEYBOARD_KEY_NUM; i++){
        window.keyboard[i] = 0;
    }

    window.modelScale = (vec4){1, 1, 1, 1};
    window.modelRotation = (vec4){0, 0, 0, 0};
    window.modelTranslation = (vec4){0, 0, 3, 0};

    window.cameraPosition = (vec4){0, 0, 0, 0};
    window.cameraRotation = (vec4){0, 0, 0, 0};

    setupBuffers();

    for (int i = 0; i < SIZE_OF_ARRAY(indicies); i++){
        indicies[i]--;
    }

    bufferData(verticies, sizeof(verticies), indicies, sizeof(indicies));

    window.shader = createShaderProgram("shaders/vertex.vs", "shaders/fragment.fs");

    // Configure shader variables
    glBindAttribLocation(window.shader, 0, "in_Position");
    // Link shader
    glLinkProgram(window.shader);
}