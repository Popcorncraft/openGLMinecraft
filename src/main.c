#include "common.h"

int main(){
    setWindowFunctions(init, update, close);
    windowInit();
    windowLoop();
}