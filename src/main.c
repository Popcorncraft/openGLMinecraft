#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

int main(){
    if(!glfwInit()){
        printf("error");
    }
    return 0;
}