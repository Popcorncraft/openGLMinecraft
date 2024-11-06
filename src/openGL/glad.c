#include "common.h"

void initGLAD(){
    // Initalize glad
    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0){
        fprintf(stderr, "ERROR::GLAD::FAILED_OPENGL_CONTEXT_INIT\n%s\n", strerror(errno));
    }

    // Report opengl version
    printf("GLAD Initalized\nGL version %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));
}