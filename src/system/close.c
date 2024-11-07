#include "common.h"

void closeProgram(){
    // Called at end of program
    // Terminates GLFW

    // Call program defined close function
    //window.functions.close();
    
    // Terminate the glfw instance
    glfwTerminate();
}