#include "common.h"

struct windowStruct window;

static void _init(){
    // Called at program creation
    // Sets up GLFW, GLAD, and the window

    // Initalize GLFW and the window
    initGLFW();

    // Set inital window size
    window.size.width = 1280;
    window.size.height = 720;

    // Create window
    window.handle = glfwCreateWindow(window.size.width, window.size.height, "test", NULL, NULL);
    // Ensure window was created
    if (!window.handle){
        fprintf(stderr, "ERROR::GLFW::FAILED_WINDOW_CREATION\n%s\n", strerror(errno));
    }

    // Set window as the current openGL context
    glfwMakeContextCurrent(window.handle);

    // Set the callback functions
    registerCallbacks();

    // Log Creation
    printf("GLFW Window Initalized\n");

    // Initalize GLAD
    initGLAD();

    enableOpenGLErrorReporting();
}

static void _update(){
    // Called every frame
    // Gets events, clears the screen, and swaps buffers

    // Get events
    glfwPollEvents();

    // Clear the window
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Call program defined update function
    window.functions.update();

    // Swap buffers
    glfwSwapBuffers(window.handle);
}

static void _close(){
    // Called at end of program
    // Terminates GLFW

    // Call program defined close function
    window.functions.close();
    
    // Terminate the glfw instance
    glfwTerminate();
}

void setWindowFunctions(windowFunction init, windowFunction update, windowFunction close){
    // Sets the relevant functions

    window.functions.init = init;
    window.functions.update = update;
    window.functions.close = close;
}

void windowInit(){
    _init();
    window.functions.init();
}

void windowLoop(){
    while(!glfwWindowShouldClose(window.handle)){
        _update();
    }
    _close();
}