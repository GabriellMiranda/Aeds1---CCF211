#ifndef RECORDSORT_H
#define RECORDSORT_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef int Tipochave;

typedef struct {
    char caracters[200];
    float real[4];
}Titem;

typedef struct {
    Tipochave Chave;
    Titem *itens;
}Tregister;

typedef struct {
    Tipochave Verificado;
    Tipochave Verificador;
}Tverifica_radix;

Tregister* InicializaRegistro(int n);

void imprimeChavesAleatorias(Tregister *reg, int n); // imprime apenas as chaves dos registros

void imprimeChave(Tregister *reg, int n, double *move, double *cont_if, double *time_spend); // imprime as chave dos registros e as informa��es do algoritmo

void Bubblesort(Tregister *reg, int n, double *cont_if, double *cont_move);//Algoritmo de ordena��o lento

void Selectionsort(Tregister *reg, int n, double *cont_if, double *cont_move);//

void Insertionsort(Tregister *reg, int n, double *cont_if, double *cont_move);

void Shellsort(Tregister *reg, int n, double *cont_if, double *cont_move);

void Ordena(int Esq, int Dir, Tregister *reg, double *cont_if, double *cont_move);
void Quicksort(Tregister *reg, int n, double *cont_if, double *cont_move);
void Particao(int Esq, int Dir, int *i, int *j, Tregister *reg, double *cont_if, double *cont_move);

void Refaz(Tregister *reg, int i, int f, double *cont_if, double *cont_move);
void Heapsort(Tregister *reg, int n, double *cont_if, double *cont_move);

void Merge(Tregister *v, int p,int q, int r, double *cont_if, double *cont_move);
void Mergesort(Tregister *v, int p, int r, double *cont_if, double *cont_move);

void Radixsort(Tregister *reg, int n, double *cont_if, double *cont_move);

void ArquivoTesteRapido(FILE *arquivo, double som_if, double som_move, double som_time, double teste);

void TesteRapidoRegistro(Tregister *reg, int n, double teste);
#endif //RECORDSORT_H
