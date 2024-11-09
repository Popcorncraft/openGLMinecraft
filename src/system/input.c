#include "common.h"

void toggleKey(int key){
    if (window.keyboard[key] == 1){
        window.keyboard[key] = 0;
    }
    else{
        window.keyboard[key] = 1;
    }
}

void handleInput(){

    float speed = 0.005;

    // Movement
    if (window.keyboard[GLFW_KEY_SPACE] == 1){
        window.cameraPosition = addVec(window.cameraPosition, scaleVec(window.cameraUp, speed));
    }
    if (window.keyboard[GLFW_KEY_LEFT_SHIFT] == 1){
       window.cameraPosition = addVec(window.cameraPosition, scaleVec(window.cameraUp, -speed));
    }
    if (window.keyboard[GLFW_KEY_A] == 1){
        window.cameraPosition = addVec(window.cameraPosition, scaleVec(window.cameraRight, speed));
    }
    if (window.keyboard[GLFW_KEY_D] == 1){
        window.cameraPosition = addVec(window.cameraPosition, scaleVec(window.cameraRight, -speed));
    }
    if (window.keyboard[GLFW_KEY_W] == 1){
        window.cameraPosition = addVec(window.cameraPosition, scaleVec(window.cameraFront, speed));
    }
    if (window.keyboard[GLFW_KEY_S] == 1){
        window.cameraPosition = addVec(window.cameraPosition, scaleVec(window.cameraFront, -speed));
    }

    // Mouse
    if (window.mouse[GLFW_MOUSE_BUTTON_LEFT] == 1){
        window.mouse[GLFW_MOUSE_BUTTON_LEFT] = 0;
        glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        window.cursorLocked = 1;
    }
    if (window.keyboard[GLFW_KEY_ESCAPE] == 1){
        window.keyboard[GLFW_KEY_ESCAPE] = 0;
        glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        window.cursorLocked = 0;
    }
    if (window.cursorLocked == 1){
        double x, y;
        glfwGetCursorPos(window.handle, &y, &x);
        window.cursorx = x;
        window.cursory = y;
        glfwSetCursorPos(window.handle, 0, 0);
        window.cameraRotation.x = fmaxf(-90, fminf(90, window.cameraRotation.x + x * 0.1));
        window.cameraRotation.y += y * 0.1;
    }
}