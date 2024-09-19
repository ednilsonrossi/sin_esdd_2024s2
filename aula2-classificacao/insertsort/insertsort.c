/**
 * Autor..: Ednilson Rossi
 * Contato: ednilsonrossi@ifsp.edu.br
*/

/* Implementação do método de ordenação InsertSort */

#include <stdio.h>
#include "uteis.h"

#define TAM 8

void insert_sort(int[], int);


void main(){
	int arquivo[] = {10, 8, 7, 5, 6, 50, 40, 32};
	
	//carrega_vetor_aleatorio(arquivo, TAM, 3);
	imprime_vetor(arquivo, TAM);
	insert_sort(arquivo, TAM);
	imprime_vetor(arquivo, TAM);
}

void insert_sort(int colecao[], int tamanho){
	
	int i, j, elemento_auxiliar;
	for(i=1; i<tamanho; i++){
		elemento_auxiliar = colecao[i];
		
		for(j = i-1; j >= 0 && colecao[j] > elemento_auxiliar; j--){
			colecao[j+1] = colecao[j];
		}
		colecao[j+1] = elemento_auxiliar;
	}
}
