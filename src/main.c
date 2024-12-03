#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

unsigned int SCR_WIDTH = 800;
unsigned int SCR_HEIGHT = 600;

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
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

    return 0;
}