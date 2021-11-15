#ifndef TUPLA_H
#define TUPLA_H
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int var; // variavel de 1 até n
    int VF; //  1 - negada, 2 - nao negada
}Ttupla;

void inicializaTupla(Ttupla *tupla, int n); // Inicializa uma tupla

void imprimeTupla(Ttupla *tupla); // imprime tuplas

#endif //Tupla