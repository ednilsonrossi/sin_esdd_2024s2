#include <stdio.h>
#define MAXSIZE 100

void interseccao(int A[], int B[], int C[]);

int main(int argc, char const *argv[]){
    
    int array_a[MAXSIZE];
    int array_b[MAXSIZE]; 
    int array_inter[MAXSIZE];
    int n, index;

    do{
        printf("Informe quantidade de conjuntos:\n");
        scanf("%d", &n);
    }while(n < 2);

    /*Leitura do conjunto de dados 1*/
    printf("Tamanho: ");
    scanf("%d", &array_a[0]);
    for(index=1; index <= array_a[0]; index++){
        printf("Array[%d]: ", index);
        scanf("%d", &array_a[index]);
    }

    /*Repete a quantidade de conjuntos que devem ser lidos*/
    for(int control = 1; control != n; control++){
        
        printf("Tamanho: ");
        scanf("%d", &array_b[0]);
        for(index=1; index <= array_b[0]; index++){
            printf("Array[%d]: ", index);
            scanf("%d", &array_b[index]);
        }

        interseccao(array_a, array_b, array_inter);

        /*copia o array_inter para array_a*/
        for(index = 0; index <= array_inter[0]; index++){
            array_a[index] = array_inter[index];
        }
    }

    /*Imprime o array_inter*/
    printf("INTER = {");
    for(index=1; index < array_inter[0]; index+=1){
        printf("%d, ", array_inter[index]);
    }
    printf("%d}\n\n", array_inter[index]);

    return 0;
}


void interseccao(int A[], int B[], int C[]){
    int position_a, position_b;
    int achou; //flag
    C[0] = 0;

    position_a = 1;
    while (position_a <= A[0]){
        achou = 0;
        position_b = 1;
        while(position_b <= B[0] && achou == 0){
            if(A[position_a] == B[position_b]){
                achou = 1;
            }
            position_b += 1;
        }
        if(achou == 1){
            C[0] += 1;
            C[C[0]] = A[position_a];
        }
        position_a += 1;
    }
}