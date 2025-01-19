#include "mecProject.h"
#include <stdio.h>

#define DEFAUL_STRING_SIZE 90

struct mec_project {
    int number;
    double value;
};

Project create(int number, double value) {
    Project pj;
    pj = malloc(sizeof(struct mec_project));
    if (pj != NULL) {
        pj->number = number;
        pj->value = value;
    }
    return pj;
}

double getProjectValue(Project project) {
    return project->value;
}

char* toString(Project project) {
    char* string;
    string = malloc(sizeof(char) * DEFAUL_STRING_SIZE);
    snprintf(string, 
        DEFAUL_STRING_SIZE, 
        "Projeto [número : %d, valor : %.2f]", 
        project->number, 
        project->value
    );
    return string;
}