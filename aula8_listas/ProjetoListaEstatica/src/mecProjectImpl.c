#include "mecProject.h"
#include <stdio.h>
#define DEFAULT_STRING_SIZE 90

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
    string = malloc(sizeof(char) * DEFAULT_STRING_SIZE);
    snprintf(string, DEFAULT_STRING_SIZE, "Projeto [numero : %d, valor : %.2f]", project->number, project->value);
    return string;
}