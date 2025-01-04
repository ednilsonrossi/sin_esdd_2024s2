#include <stdlib.h>
#include <stdbool.h>
#include "mecProject.h"
#define DEFAULT_SET_SIZE 5

typedef struct setOfProjects* Set;

typedef Project Info;

Set init();

bool insert(Set mySet, Info element);

Info getAt(Set mySet, int position);

int size(Set mySet);