#include "common.h"

char* filetobuf(char *file){
    // File "id"
    FILE *fd;
    // Length of file
    long length;
    // Output
    char *buffer;

    // Create file descriptor
    fd = fopen(file, "rb");
    // Ensure fd was properly opened
    if (!fd){
        return NULL;
    }

    // Set "cursor" to end of file
    fseek(fd, 0, SEEK_END);
    // Read position of "cursor"
    length = ftell(fd);

    // Allocate a buffer of length + 1
    buffer = (char*)malloc(length+1);

    // Set "cursor" to begining
    fseek(fd, 0, SEEK_SET);

    // Read file to buffer
    fread(buffer, length, 1, fd);
    // Add null termination
    buffer[length] = 0;

    // Close file
    fclose(fd);

    // Return the file buffer
    return buffer;
}