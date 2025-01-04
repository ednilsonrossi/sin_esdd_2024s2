#include <stdio.h>

#include "mecProject.h"
#include "setOfProjects.h"

int main(int argc, char const *argv[]) {
    
    Set projetos = init();

    insert(projetos, create(123, 1000.0));
    insert(projetos, create(234, 2000.0));
    insert(projetos, create(345, 1500.0));
    insert(projetos, create(456, 1900.0));
    insert(projetos, create(567, 3000.0));
    insert(projetos, create(678, 5000.0));
    insert(projetos, create(890, 8000.0));
    insert(projetos, create(901, 1000.0));
    insert(projetos, create(923, 10000.0));

    for (int i = 0; i < size(projetos); i++) {
        printf("%s \n", toString(getAt(projetos, i)));
    }

    return 0;
}
