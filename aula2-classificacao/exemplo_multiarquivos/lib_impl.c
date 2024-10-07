#include "lib.h"

void gerar_crescente(int arr[], int size) {
    srand(time(NULL));

    arr[0] = rand() % 100;
    for(int i = 1; i < size; i++) {
        arr[i] = arr[i-1] + (rand() % 9);
    }

}

void gerar_decrescente(int arr[], int size) {
    arr[0] = INT_MAX;
    for(int i = 1; i < size; i++) {
        arr[i] = arr[i-1] - 1;
    }
}