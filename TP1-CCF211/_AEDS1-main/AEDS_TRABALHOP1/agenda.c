#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "agenda.h"

Tagenda *criaAgenda(char *idProf, char *nomeProf, int ano){
    Tagenda *a = (Tagenda*) malloc(sizeof(Tagenda));
    strcpy(a->idProf, idProf);
    strcpy(a->nomeProf, nomeProf);
    a->ano = ano;
    a->professor = NULL;
    a->compromissos = (TLcompromisso*) malloc(sizeof(TLcompromisso));
    inicializaLCompromisso(a->compromissos);
    return a;
}

void recupera_Agenda(Tagenda *agenda, data *data){

    int conta_compromisso = 0;
    int flag = 0;
    celula_compromisso *pAux;
    pAux = agenda->compromissos->Primeiro->prox;
    while (pAux != NULL ){
        
        if(pAux->c->data->ano > data->ano){
            flag = 1;
        }
        if(pAux->c->data->ano == data->ano){
            if(pAux->c->data->mes > data->mes){
                flag = 1;
            }
            if(pAux->c->data->mes == data->mes){
                if(pAux->c->data->dia > data->dia){
                    flag = 1;
                }
            }
        }
        if(flag == 1){
            conta_compromisso ++;
        }
        pAux = pAux->prox;
    }
    printf("Seu Nome: %s\n", agenda->nomeProf);
    printf("Ano da agenda: %d\n", agenda->ano);
    printf("Quantidade de compromissos: %d\n", conta_compromisso);

}


int insereCompromisso(Tagenda *agenda, Tcompromisso *compro) {
    int tratador;

    tratador = insereLCompromisso(agenda->compromissos, compro);

    return tratador;
}

int removeCompromisso(Tagenda *agenda, int idCompromisso) {
    int tratador;
    tratador = removeLCompromisso(agenda->compromissos, idCompromisso);
    return tratador;
}

void imprimeAgenda(Tagenda *agenda) {
    printf("\n");
    printf("|--------------------------------------------------------------------|\n");
    printf("|Identificador:%s\n",agenda->idProf);
    printf("|Ano:%d\n", agenda->ano);
     if(agenda->professor != NULL) {
        imprimeProfessor(agenda->professor);
    }
     if(agenda->compromissos->Primeiro->prox != NULL){
        printf("|Compromissos do professor:%s\n",agenda->nomeProf);
        printf("\n");
        printf("|LISTA DE COMPROMISSOS\n");
        imprimeLCompromisso(agenda->compromissos);
     }
    printf("|--------------------------------------------------------------------|\n");
    printf("\n\n");
}

int retornaNCompromissos(Tagenda *agenda) {
    int cont = 0;
    celula_compromisso *pAux;
    pAux = agenda->compromissos->Primeiro->prox;
    while (pAux != NULL){
        cont++;
        pAux = pAux->prox;

    }
    return cont;
}

