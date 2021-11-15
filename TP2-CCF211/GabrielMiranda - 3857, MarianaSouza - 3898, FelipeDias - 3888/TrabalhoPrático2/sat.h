#ifndef SAT_H
#define SAT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tupla.h"
/* Tamanho máximo da string de entrada Para a combinação. */
#define MAX 250

typedef struct{
    Ttupla tupla[3];
}Tclausula;

Tclausula* inicializaClausula(int n, int nclaus);// funcao que inicializa clausulas interativas

void TransfomarTrue(Tclausula *clausula, int nclaus, char *combinacao); // funcao que verificar combinações que satisfacao a equacao para que a mesma se torne verdadeira

Tclausula* randClausula(int **matriz, int n, int nclaus); // retonar uma equacao com valores aleatorios de 1 ate n

void combinacao(int r, Tclausula *clausula, int nclaus); // funcao de combinacao para n casos

int** PreenchaMatrizClausula(Tclausula *clausula, int nclaus, int N);// Preenche a matriz com valores aleatorios

void imprimeMatriz(int **matriz, int nclaus, int N);//imprime a matriz

void imprimeClausulas(Tclausula *clausula, int nclaus); // funcao que imprime clausulas-(equacao)

#endif // sat
