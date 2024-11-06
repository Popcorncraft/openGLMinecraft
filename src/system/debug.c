#include "common.h"

void printStats(){
    printf("\033[H\033[2J");

    printf("window size: %d, %d\n", window.size.height, window.size.width);
    printf("cursor position: %f, %f\n\n", window.cursorx, window.cursory);

    printf("model scale: %f, %f, %f, %f\n", window.modelScale.x, window.modelScale.y, window.modelScale.z, window.modelScale.w);
    printf("model rotation: %f, %f, %f, %f\n", window.modelRotation.x, window.modelRotation.y, window.modelRotation.z, window.modelRotation.w);
    printf("model translation: %f, %f, %f, %f\n\n", window.modelTranslation.x, window.modelTranslation.y, window.modelTranslation.z, window.modelTranslation.w);

    printf("camera rotation: %f, %f, %f, %f\n", window.cameraRotation.x, window.cameraRotation.y, window.cameraRotation.z, window.cameraRotation.w);
    printf("camera position: %f, %f, %f, %f\n\n", window.cameraPosition.x, window.cameraPosition.y, window.cameraPosition.z, window.cameraPosition.w);
}