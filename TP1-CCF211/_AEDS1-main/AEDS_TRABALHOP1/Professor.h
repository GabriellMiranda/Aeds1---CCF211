#ifndef AEDS_TRABALHOP1_PROFESSOR_H
#define AEDS_TRABALHOP1_PROFESSOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Endereco.h"

typedef struct{
    int idade;
    char CPF[20];
    char RG[20];
    char aniversario[30];
    char graduacao[50];
    Tendereco *endereco;
}Tprofessor;

Tprofessor *inicializaProfessor();//retorna um professor alocado 
void imprimeProfessor(Tprofessor *profe);//imprime os dados do professor

#endif //AEDS_TRABALHOP1_PROFESSOR_H
