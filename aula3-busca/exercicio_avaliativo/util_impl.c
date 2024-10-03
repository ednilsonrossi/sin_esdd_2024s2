#include "utilitario.h"

void load_file_classified(int array[], int size){
    srand( (unsigned) time(NULL) );

    array[0] = rand() % 1000;
    for(int i = 1; i != size; i++){
        array[i] = array[i-1] + ( rand() % 100 );
    }

}

void print_file(int array[], int size){
    for(int i = 0; i != size; i += 1){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}
