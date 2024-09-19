/**
 * Autor..: Ednilson Rossi
 * Contato: ednilsonrossi@ifsp.edu.br
*/

/* Implementação do método de ordenação BubbleSort */

#include <stdio.h>
#include "uteis.h"

#define TAM 10

void bubble_sort(int[], int);


void main(){
	int arquivo[TAM];
	
	carrega_vetor_aleatorio(arquivo, TAM, 3);
	imprime_vetor(arquivo, TAM);
	bubble_sort(arquivo, TAM);
	imprime_vetor(arquivo, TAM);
}

void bubble_sort(int colecao[], int tamanho){
	int i, j, elemento_auxiliar;
	int trocou = TRUE;
	
	for(i=0; i<tamanho && trocou; i++){
		trocou = FALSE;
		for(j=0; j < tamanho-(1+i); j++){
			if(colecao[j] > colecao[j+1]){
				elemento_auxiliar = colecao[j];
				colecao[j] = colecao[j+1];
				colecao[j+1] = elemento_auxiliar;
				trocou = TRUE;
			}
		}		
	}
}
