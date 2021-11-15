#ifndef ARRAYSORT_H
#define ARRAYSORT_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int* InicializaArray(int n); //inicializa o vetor

void imprimeAleatorio(int *Array, int n);

void imprimeArray(int *Array, int n, double *move, double *cont_if, double *time_spend); //imprime vetor

void Bubblesort_A(int *Array, int n, double *cont_if, double *cont_move);

void Selectionsort_A(int *Array, int n, double *cont_if, double *cont_move);

void Insertionsort_A(int *Array, int n, double *cont_if, double *cont_move);

void Shellsort_A(int *Array, int n, double *cont_if, double *cont_move);

void Ordena_A(int Esq, int Dir, int *Array, double *cont_if, double *cont_move);
void Quicksort_A(int *Array, int n, double *cont_if, double *cont_move);
void Particao_A(int Esq, int Dir, int *i, int *j, int *Array, double *cont_if, double *cont_move);

void Refaz_A(int *Array, int i, int f, double *cont_if, double *cont_move);
void Heapsort_A(int *Array, int n, double *cont_if, double *cont_move);

void Merge_A(int *Array, int inicio,int meio, int fim, double *cont_if, double *cont_move);
void Mergesort_A(int *Array,int inicio, int fim, double *cont_if, double *cont_move);

void Radixsort_A(int* Array, int n, double *cont_if, double *cont_move);

void tacanoarquivo(FILE *arquivo, double som_if, double som_move, double som_time, double teste);

void TesteRapidoArray(int *Array, int n, double teste);

#endif //ARRAYSORT_H
