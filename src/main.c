#include "common.h"

int main(){
    init();
    while(!glfwWindowShouldClose(window.handle)){
        update();
    }
    closeProgram();
}