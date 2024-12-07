#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <cglm/cglm.h>

#include <stdio.h>

#include "fileio.h"

unsigned int SCR_WIDTH = 800;
unsigned int SCR_HEIGHT = 600;

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void framebuffer_callback(GLFWwindow* window, int width, int height){
    SCR_HEIGHT = height;
    SCR_WIDTH = width;
    glViewport(0, 0, width, height);
}

int main(){
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()){
        printf("ERROR::FAILED TO INIT GLFW\n");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "test", NULL, NULL);
    if (window == NULL){
        printf("ERROR::FAILED TO CREATE GLFW WINDOW\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL(glfwGetProcAddress)){
        printf("ERROR::FAILED TO INIT GLAD\n");
        return -1;
    }

    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    unsigned int shader3D = glCreateProgram();
    addShader(shader3D, "./shaders/vertex3D.vert", VERTEX);
    addShader(shader3D, "./shaders/fragment3D.frag", FRAGMENT);

    while (!glfwWindowShouldClose(window)){
        double time = glfwGetTime();
        glfwPollEvents();


        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}