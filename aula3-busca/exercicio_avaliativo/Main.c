#include "utilitario.h"
#define SIZE 100

int main(int argc, char const *argv[]){
    
    int arquivo[SIZE];

    load_file_classified(arquivo, SIZE);

    print_file(arquivo, SIZE);

    return 0;
}
