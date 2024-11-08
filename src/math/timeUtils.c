#include "common.h"

double convertTime(struct timespec timeS){
    return ((double)timeS.tv_sec + (double)timeS.tv_nsec / (double)1000000000);
}