#include <stdio.h>
#include <stdlib.h>
#include "LCompromisso.h"

void inicializaLCompromisso(TLcompromisso *l) {
    l->Primeiro = (celula_compromisso*) malloc(sizeof(celula_compromisso));
    l->Ultimo = l->Primeiro;
    l->Primeiro->prox = NULL;
}

int LCompromissoEhVazia(TLcompromisso *l) {
    return (l->Primeiro == l->Ultimo);
}

celula_compromisso procuraCompromisso(TLcompromisso *compro,int id){
    celula_compromisso *pAux = compro->Primeiro->prox;
    while (pAux != NULL){
        if(pAux->c->id == id) {
            return *pAux;
        }
        pAux = pAux->prox;
    }
}

int insereLCompromisso(TLcompromisso *l, Tcompromisso *c) {

    int prioridadeEntrada = retornaPrioridade(c);

    celula_compromisso* pAux = l->Primeiro->prox;

    celula_compromisso* pAnt = l->Primeiro;

    while (pAux != NULL && retornaPrioridade(pAux->c)>= prioridadeEntrada) {
        if (temConflito(pAux->c, c)) {
            return 0;
        }

        pAux = pAux->prox;
        pAnt = pAnt->prox;
    }

    if (pAux != NULL) {

        celula_compromisso *pNovo = (celula_compromisso*) malloc(sizeof(celula_compromisso));
        pNovo->c = c;
        pNovo->prox = pAux;
        pAnt->prox = pNovo;
        return c->id;
    }

    l->Ultimo->prox = (celula_compromisso*) malloc(sizeof(celula_compromisso));
    l->Ultimo = l->Ultimo->prox;
    l->Ultimo->c = c;
    l->Ultimo->prox = NULL;
    return c->id;
}

int removeLCompromisso(TLcompromisso *l, int idCompromisso) {
    celula_compromisso *pAux = l->Primeiro->prox;
    celula_compromisso *pAnt = l->Primeiro;

    while (pAux != NULL && pAux->c->id != idCompromisso) {
        pAux = pAux->prox;
        pAnt = pAnt->prox;
    }

    if (pAux != NULL) {
        pAnt->prox = pAux->prox;
        free(pAux);
    }

    return 1;
}

void imprimeLCompromisso(TLcompromisso *l) {
    celula_compromisso *pAux = l->Primeiro->prox;
    while (pAux != NULL) {
        imprimeCompromisso(pAux->c);
        pAux = pAux->prox;

    }
}

