/**
 * Autor..: Ednilson Rossi
 * Contato: ednilsonrossi@ifsp.edu.br
*/

/* Implementação do método de ordenação por interpolação*/

#include <stdio.h>
#include "uteis.h"

#define TAM 10

void merge(int[], int, int);
void intercala(int[], int, int, int);

void main(){
	int arquivo[TAM];
	
	carrega_vetor_aleatorio(arquivo, TAM, 3);
	imprime_vetor(arquivo, TAM);
	merge(arquivo, 0, TAM-1);
	imprime_vetor(arquivo, TAM);
}

void merge(int colecao[], int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = (inicio + fim) / 2;
		merge(colecao, inicio, meio);
		merge(colecao, meio+1, fim);
		intercala(colecao, inicio, fim, meio);
	}
}

void intercala(int colecao[], int inicio, int fim, int meio){
	int pos_livre, inicio_arquivo1, inicio_arquivo2, i;
	int arquivo_aux[TAM];
	inicio_arquivo1 = inicio;
	inicio_arquivo2 = meio + 1;
	pos_livre = inicio;
	while(inicio_arquivo1 <= meio && inicio_arquivo2 <= fim){
		if(colecao[inicio_arquivo1] <= colecao[inicio_arquivo2]){
			arquivo_aux[pos_livre] = colecao[inicio_arquivo1];
			inicio_arquivo1 += 1;
		} 
		else
		{
			arquivo_aux[pos_livre] = colecao[inicio_arquivo2];
			inicio_arquivo2 += 1;
		}
		pos_livre += 1;
	}
	for(i=inicio_arquivo1; i<= meio; i++, pos_livre++){
		arquivo_aux[pos_livre] = colecao[i];
	}
	for(i=inicio_arquivo2; i<= fim; i++, pos_livre++){
		arquivo_aux[pos_livre] = colecao[i];
	}
	for(i=inicio; i <= fim; i++){
		colecao[i] = arquivo_aux[i];
	}
}
