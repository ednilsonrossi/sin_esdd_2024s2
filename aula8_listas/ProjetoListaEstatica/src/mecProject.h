#include <stdlib.h>

typedef struct mec_project* Project;

Project create(int number, double value);

double getProjectValue(Project project);

char* toString(Project project);