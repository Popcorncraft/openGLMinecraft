#include "common.h"

void initGLFW(){
    registerErrorCallback();

    if (!glfwInit()){
        fprintf(stderr, "ERROR::GLFW::FAILED_INIT\n%s\n", strerror(errno));
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);  
}