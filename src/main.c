#include "common.h"

int main(){
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);
    window.startTime = convertTime(time);
    window.time = convertTime(time);

    init();

    while(!glfwWindowShouldClose(window.handle)){
        char title[50];
        clock_gettime(CLOCK_MONOTONIC, &time);
        window.time = convertTime(time);
        window.deltaTime = window.time - window.lastTime;
        window.lastTime = window.time;
        window.upTime = window.time - window.startTime;

        window.fpsAverage = 0;
        for (int i = SIZE_OF_ARRAY(window.fpsCalc) - 1; i >= 0; i--){
            if (i == 0){
                window.fpsCalc[i] = 1 / window.deltaTime;
            }
            else {
                window.fpsCalc[i] = window.fpsCalc[i - 1];
            }
            window.fpsAverage += window.fpsCalc[i];
        }
        window.fpsAverage /= SIZE_OF_ARRAY(window.fpsCalc);

        sprintf(title, "time: %f upTime: %f deltaTime: %f fpsCalc: %011f fpsAverage: %011f", window.time, window.upTime, window.deltaTime, window.fpsCalc[0], window.fpsAverage);
        glfwSetWindowTitle(window.handle, title);

        update();
    }
    closeProgram();
}