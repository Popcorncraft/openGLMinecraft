#include "common.h"





/*
struct modelStruct loadModel(char *path){
    struct modelStruct model;

    model.iCount = 0;
    model.vCount = 0;

    FILE *file = fopen(path, "r");

    char line[256];
    char *token;

    if (file != NULL){
        //while (fgets(line, sizeof(line), file)){
            //switch (line[0]){
                //case 'v':
                    //model.vCount += 3;
                    //break;
                //case 'f':
                    //model.iCount += 3;
                    //break;
            //}
        //}

        //int (*iptr)[model.iCount] = malloc(model.iCount * sizeof(int));
        //float (*vptr)[model.vCount] = malloc(model.vCount * sizeof(float));

        //model.i = iptr;
        //model.v = vptr;
        model.iCount = 0;
        model.vCount = 0;
        while (fgets(line, sizeof(line), file)){
            switch (line[0]){
                case 'v':
                    model.vCount += 3;
                    token = strtok(line, " ");
                    for (int i = 0; i < 4; i++){
                        if (i != 0){
                            model.v[model.vCount - 4 + i] = strtof(token, NULL);
                        }
                        token = strtok(NULL, " ");
                    }

                    break;
                case 'f':
                    model.iCount += 3;
                    token = strtok(line, " ");
                    for (int i = 0; i < 4; i++){
                        if (i != 0){
                            model.i[model.iCount - 4 + i] = (int)strtol(token, NULL, 10);
                        }
                        token = strtok(NULL, " ");
                    }
                    break;
            }
        }
    }
    else {
        fprintf(stderr, "Unable to open file\n");
    }

    return model;
}*/