//
// Created by MARIANA on 19/03/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compromisso.h"

int auto_generated_id = 0;

Tcompromisso *inicializaCompromisso(int prioridade, data *d, hora *h, int duracao, char *descricao) {
    Tcompromisso *c = (Tcompromisso *) malloc(sizeof(Tcompromisso));
    c->id = ++auto_generated_id;
    alteraPrioridade(c, prioridade);
    c->data = inicializaData(d->dia, d->mes, d->ano);
    c->hora = inicializaHora(h->horas, h->minutos, duracao);
    strcpy(c->descricao, descricao);
    return c;
}


void alteraPrioridade(Tcompromisso *c, int priori) {
    if (priori >= PRIORI_MIN && priori <= PRIORI_MAX) {
        c->prioridade = priori;
    } else {
        printf("Prioridade invalida: %d. Favor preencher com valor sugerido em intervalo [%d - %d].\n", priori, PRIORI_MIN, PRIORI_MAX);
        printf("Preenchendo com %d.\n", PRIORI_MIN);
        c->prioridade = PRIORI_MIN;
    }
}

int retornaPrioridade(Tcompromisso *c) {
    return c->prioridade;
}

int temConflito(Tcompromisso *a, Tcompromisso *b) {
    if (comparaDatas(a->data, b->data)) {
        if (horasTemConflito(a->hora, b->hora) != 0) {
            printf("Compromissos conflitantes. Por favor verificar dados referentes ao novo compromisso.\n");
            return 1;
        }
    }
    return 0;
}

void imprimeCompromisso(Tcompromisso *c) {
    printf("|----------------------------------|\n");
    printf("|Id: %d\n", c->id);
    printf("|Prioridade: %d\n", c->prioridade);
    imprimeData(c->data);
    imprimeHora(c->hora);
    printf("|Descricao do compromisso: %s\n", c->descricao);
    printf("|----------------------------------|\n");
}
