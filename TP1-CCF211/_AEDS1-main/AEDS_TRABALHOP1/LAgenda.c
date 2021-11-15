#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "LAgenda.h"

void FLvazia_LAgenda(TLagenda *lagenda){
    lagenda->primeiro = (Tcelula_Agenda *) malloc(sizeof (Tcelula_Agenda));
    lagenda->ultimo = lagenda->primeiro;
    lagenda->primeiro->prox = NULL;
}

int LEhVazia_LAgenda(TLagenda *lagenda){
    return (lagenda->primeiro == lagenda->ultimo);
}

void Insere_LAgenda(TLagenda *lagenda, Tagenda *aux_agenda){

    lagenda->ultimo->prox = (Tcelula_Agenda *) malloc(sizeof (Tcelula_Agenda));
    lagenda->ultimo = lagenda->ultimo->prox;
    lagenda->ultimo->Agenda = aux_agenda;
    lagenda->ultimo->prox = NULL;
}

Tcelula_Agenda Procura_agenda_professor(TLagenda *lagenda, char *id_professor){
    Tcelula_Agenda *pAux;
    pAux = lagenda->primeiro->prox;
    while (pAux != NULL) {
        if(strcmp(pAux->Agenda->idProf, id_professor) == 0 ){
            return *pAux;
        }
        pAux = pAux->prox;
    }
}

void Imprime_LAgenda(TLagenda *lagenda){
    Tcelula_Agenda *pAux;
    pAux = lagenda->primeiro->prox;
    while (pAux != NULL){
        imprimeAgenda(pAux->Agenda);
        pAux = pAux->prox;
    }
}




