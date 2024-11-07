#include "common.h"

void loadModel(char *path, struct modelStruct *model){

    FILE *file = fopen(path, "r");

    char line[256];
    char *token;

    if (file != NULL){
        model->iCount = 0;
        model->vCount = 0;

        model->i = malloc(1);
        model->v = malloc(1);

        while (fgets(line, sizeof(line), file)){
            switch (line[0]){

                case 'v':
                    model->vCount += 3;
                    model->v = realloc(model->v, model->vCount * sizeof(float));
                    token = strtok(line, " ");
                    for (int i = 0; i < 4; i++){
                        if (i != 0){
                            model->v[model->vCount - 4 + i] = strtof(token, NULL);
                        }
                        token = strtok(NULL, " ");
                    }

                    break;

                case 'f':
                    model->iCount += 3;
                    model->i = realloc(model->i, model->iCount * sizeof(int));
                    token = strtok(line, " ");
                    for (int i = 0; i < 4; i++){
                        if (i != 0){
                            model->i[model->iCount - 4 + i] = (int)strtol(token, NULL, 10);
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
}

void registerModel(char *path, vec4 position, vec4 rotation, vec4 scale){
    struct modelStruct *model = (struct modelStruct*)malloc(sizeof(struct modelStruct));
    loadModel(path, model);
    model->position = position;
    model->rotation = rotation;
    model->scale = scale;
    for (int i = 0; i < model->iCount; i++){
        model->i[i]--;
    }
    window.modelCount++;
    window.models = realloc(window.models, sizeof(struct modelStruct) * window.modelCount);
    window.models[window.modelCount - 1] = *model;
}