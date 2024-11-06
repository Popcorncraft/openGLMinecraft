#ifndef WINDOW_H
#define WINDOW_H

#include "common.h"

#pragma region Window Type
typedef void (*windowFunction)();
typedef void (*windowCallback)();

typedef union windowSize{
    struct{ unsigned int raw[2];};
    struct{ unsigned int x; unsigned int y; };
    struct{ unsigned int width; unsigned int height; };
}windowSize;

typedef struct windowFunctions{
    windowFunction init, close, update;
}windowFunctions;

struct windowStruct{
    GLFWwindow *handle;
    windowSize size;

    windowFunctions functions;

    unsigned int shader;

    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;

    vec4 modelScale;
    vec4 modelRotation;
    vec4 modelTranslation;

    vec4 cameraRotation;
    vec4 cameraPosition;

    bool keyboard[MAX_KEYBOARD_KEY_NUM];
    bool mouse[MAX_MOUSE_BUTTON_NUM];
    bool cursorLocked;
    float cursorx;
    float cursory;
};
#pragma endregion

#pragma region Functions

void setWindowFunctions(windowFunction init, windowFunction update, windowFunction close);
void windowInit();
void windowLoop();

#pragma endregion

#endif