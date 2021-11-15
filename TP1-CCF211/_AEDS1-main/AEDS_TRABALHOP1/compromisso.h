//
// Created by MARIANA on 19/03/2021.
//

#ifndef AEDS_TRABALHOP1_COMPROMISSO_H
#define AEDS_TRABALHOP1_COMPROMISSO_H

#include "data.h"
#include "hora.h"

#define M 100

#define PRIORI_MIN 1
#define PRIORI_MAX 5

typedef struct compromisso {
    int id;
    data *data;
    hora *hora;
    int prioridade;
    char descricao[M];
}Tcompromisso;

Tcompromisso *inicializaCompromisso(int prioridade, data*, hora*, int duracao, char* descricao);// retorna um compromisso alocado
void alteraPrioridade(Tcompromisso* compromisso, int prioridade);//altera a prioridade de um compromisso 
int retornaPrioridade(Tcompromisso* compromisso);//retorna a prioridade de compromisso 
int temConflito(Tcompromisso* a, Tcompromisso* b);// verifica se o horario e data de um compromisso tem conflito 
void imprimeCompromisso(Tcompromisso* compromisso);//imprime o compromisso


#endif //AEDS_TRABALHOP1_COMPROMISSO_H
