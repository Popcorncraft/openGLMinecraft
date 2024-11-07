#include "common.h"

void init(){

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
    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0){
        fprintf(stderr, "ERROR::GLAD::FAILED_OPENGL_CONTEXT_INIT\n%s\n", strerror(errno));
    }

    // Report opengl version
    printf("GLAD Initalized\nGL version %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));

    enableOpenGLErrorReporting();

    for (int i = 0; i < MAX_KEYBOARD_KEY_NUM; i++){
        window.keyboard[i] = 0;
    }

    window.cameraPosition = (vec4){0, 0, 0, 0};
    window.cameraRotation = (vec4){0, 0, 0, 0};

    // Set the VAO id as a VAO
    glGenVertexArrays(1, &window.vao);

    // Set the VBO id as a VBO
    glGenBuffers(1, &window.vbo);
    // Set the EBO id as an EBO
    glGenBuffers(1, &window.ebo);

    window.shader = createShaderProgram("shaders/vertex.vs", "shaders/fragment.fs");

    // Configure shader variables
    glBindAttribLocation(window.shader, 0, "in_Position");
    // Link shader
    glLinkProgram(window.shader);

    window.models = (struct modelStruct*)malloc(sizeof(struct modelStruct));

    registerModel("./models/cube.obj");
}