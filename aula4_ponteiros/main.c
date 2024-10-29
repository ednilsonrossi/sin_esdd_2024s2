#include <stdlib.h>
#include <stdio.h>

int main(){
    
    while(1) {
        int* p = malloc(sizeof(int));
        printf("%p \n", p);
    }

    return 0;
}
