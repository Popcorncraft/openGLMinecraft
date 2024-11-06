#include "common.h"

#pragma region Callback Definitions
static void errorCallback(int error, const char* description){
    fprintf(stderr, "Error: %s\n", description);
}

static void framebufferSizeCallback(GLFWwindow* selectedWindow, int width, int height){
    glViewport(0, 0, width, height);
    window.size.width = width;
    window.size.height = height;
}

static void keyCallback(GLFWwindow* doNotUse, int key, int scancode, int action, int mods){
    if (action == GLFW_PRESS){
        window.keyboard[key] = 1;
    }
    if (action == GLFW_RELEASE){
        window.keyboard[key] = 0;
    }
}

static void mouseCallback(GLFWwindow* doNotUse, int button, int action, int mods)
{
    if (action == GLFW_PRESS){
        window.mouse[button] = 1;
    }
    if (action == GLFW_RELEASE){
        window.mouse[button] = 0;
    }
}
#pragma endregion

#pragma region Callback Registers
void registerErrorCallback(){
    glfwSetErrorCallback(errorCallback);
}

void registerCallbacks(){
    glfwSetKeyCallback(window.handle, keyCallback);
    glfwSetMouseButtonCallback(window.handle, mouseCallback);
    glfwSetFramebufferSizeCallback(window.handle, framebufferSizeCallback);
}
#pragma endregion