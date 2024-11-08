#ifndef WINDOW_H
#define WINDOW_H

#include "common.h"

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

    vec4 cameraRotation;
    vec4 cameraPosition;

    bool keyboard[MAX_KEYBOARD_KEY_NUM];
    bool mouse[MAX_MOUSE_BUTTON_NUM];
    bool cursorLocked;
    float cursorx;
    float cursory;

    int modelCount;
    struct modelStruct *models;

    double time;
    double startTime;
    double lastTime;
    double deltaTime;
    double upTime;
    
    double fpsCalc[10000];
    double fpsAverage;

};

void setWindowFunctions(windowFunction init, windowFunction update, windowFunction close);
void windowInit();
void windowLoop();

#endif