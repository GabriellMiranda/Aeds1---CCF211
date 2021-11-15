//
// Created by MARIANA on 19/03/2021.
//

#ifndef AEDS_TRABALHOP1_AGENDA_H
#define AEDS_TRABALHOP1_AGENDA_H

#include "LCompromisso.h"
#include "Professor.h"
#define NOME_MAX 50

typedef struct agenda {
    char idProf[NOME_MAX];
    char nomeProf[NOME_MAX];
    int ano;
    Tprofessor *professor;
    TLcompromisso *compromissos;
}Tagenda;

Tagenda *criaAgenda(char *idpro, char* nomeprof, int ano);  // retorna uma agenda já aloocada
void recupera_Agenda(Tagenda *agenda, data *data); // mostra agenda apos uma certa data
int insereCompromisso(Tagenda* Agenda, Tcompromisso *compro); // Inserindo compromisso ordenado
int removeCompromisso(Tagenda* Agenda, int id); // procura um compromisso passando um id, e depois remove
void imprimeAgenda(Tagenda* Agenda); //imprime
int retornaNCompromissos(Tagenda* agenda); // retorna a quantidade de compromisso de um agenda

#endif //AEDS_TRABALHOP1_AGENDA_H
