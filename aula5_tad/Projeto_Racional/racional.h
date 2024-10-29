#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct racional* T_Racional;



T_Racional criarRacional(int numerador, int denominador);

void destroiRacional(T_Racional racionalPtr);

T_Racional somaRacional(T_Racional racionalAPtr, T_Racional racionalBPtr);

T_Racional multiplicaRacional(T_Racional racionalAPtr, T_Racional racionalBPtr);

void imprimeRacional(T_Racional racionapPtr);

T_Racional entradaRacional();

void simplificarRacional(T_Racional racionalPtr);

bool ehValidoRacional(T_Racional racionalPtr);

int mdc(int a, int b);





