/**
 * Autor..: Ednilson Rossi
 * Contato: ednilsonrossi@ifsp.edu.br
*/

/* Implementação do método de ordenação por quicksort*/

#include <stdio.h>
#include "uteis.h"

#define TAM 10

void quicksort(int x[], int lb, int ub);
void partition(int x[], int lb, int ub, int *j);


void main(){
	int arquivo[TAM];
	
	carrega_vetor_aleatorio(arquivo, TAM, 3);
	imprime_vetor(arquivo, TAM);
	quicksort(arquivo, 0, TAM-1);
	imprime_vetor(arquivo, TAM);
}


void quicksort(int x[], int lb, int ub){

    int j = -1;

    if(lb >= ub)
        return;                     /* Vetor está classificado */

    partition(x, lb, ub, &j);       /* Particiona os elementos do subvetor
                                     * de modo que um dos elementos seja alocado
                                     * em sua posição correta. A variável j é a
                                     * posição onde este elemento foi alocada
                                     */

    quicksort(x, lb, j-1);          /* Classifica de forma recursiva o subvetor
                                     * entre a posição lb e j-1
                                     */

    quicksort(x, j+1, ub);          /* Classifica de forma recursiva o subvetor
                                     * entre a posição j+1 e ub
                                     */

}


void partition(int x[], int lb, int ub, int *j){

    int a, down, up, temp;
    
    /*
     * a é o elemento cuja posição 
     * final é procurada (pivô)
     */
    a = x[lb];

    /*
     * Inicialização dos ponteiros
     */
    up = ub;
    down = lb;

    while(down < up){
        while(x[down] <= a && down < ub){
            /*
             * Sobe no vetor
             */
            down++;
        }
        while(x[up] > a){
            /*
             * Desce no vetor
             */
            up--;
        }
        if(down < up){
            temp = x[down];
            x[down] = x[up];
            x[up] = temp;
        }
    }
    x[lb] = x[up];
    x[up] = a;
    *j = up;
}
