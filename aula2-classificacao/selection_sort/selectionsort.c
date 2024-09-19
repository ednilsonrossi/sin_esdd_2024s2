/**
 * Autor..: Ednilson Rossi
 * Contato: ednilsonrossi@ifsp.edu.br
*/


/* Implementação do método de ordenação Selection Sort */
#include <stdio.h>
#include "uteis.h"

#define TAM 12

void selection_sort(int[], int);


int main(int argc, char const *argv[]){
	int arquivo[TAM];
	
	carrega_vetor_aleatorio(arquivo, TAM, 3);
	imprime_vetor(arquivo, TAM);
	selection_sort(arquivo, TAM);
	imprime_vetor(arquivo, TAM);
	
    return 0;
}


/*método de classificação*/
void selection_sort(int colecao[], int tamanho){
	int i, j, pos_menor, elemento_auxiliar;
	
	for(i=0; i<tamanho; i++){
		pos_menor = i;
		for(j=i+1; j<tamanho; j++){
			if(colecao[j] < colecao[pos_menor]){
				pos_menor = j;
			}
		}
		elemento_auxiliar = colecao[i];
		colecao[i] = colecao[pos_menor];
		colecao[pos_menor] = elemento_auxiliar;
	}
}
