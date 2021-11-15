#ifndef AEDS_TRABALHOP1_LAGENDA_H
#define AEDS_TRABALHOP1_LAGENDA_H

#include "agenda.h"

typedef struct Celula_Agenda{
    Tagenda *Agenda;
    struct Celula_Agenda* prox;
}Tcelula_Agenda;

typedef struct {
    Tcelula_Agenda* primeiro;
    Tcelula_Agenda* ultimo;
}TLagenda;

void FLvazia_LAgenda(TLagenda *lagenda);//cria uma lista
int LEhVazia_LAgenda(TLagenda *lagenda);//verifica se a lista esta vazia
void Insere_LAgenda(TLagenda *lagenda, Tagenda *aux_agenda);//insere uma agenda
Tcelula_Agenda Procura_agenda_professor(TLagenda *lagenda, char *id_professor);
/*Essa funcao faz login na agenda de determinado professor,o pAux variavel auxiliar,
  retorna pra funcao principal com o endereco de memoria da celula agenda cujo o id foi passado*/

void Imprime_LAgenda(TLagenda *agenda); // imprime a lista de agendas, todas as agendas

#endif //AEDS_TRABALHOP1_LAGENDA_H
