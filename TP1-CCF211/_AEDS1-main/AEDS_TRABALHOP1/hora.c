#include <stdio.h>
#include <stdlib.h>

#include "hora.h"

hora *inicializaHora(int horas, int minutos, int duracao) {
    hora *h = (hora*) malloc(sizeof(hora));
    h->horas = horas;
    h->minutos = minutos;
    h->duracao = duracao;
    return h;
}

int comparaHoras(hora *a, hora *b) {
    if (a->horas > b->horas) {
        return -1;
    } else if (a->horas < b->horas) {
        return 1;
    } else {
        if (a->minutos > b->minutos) {
            return -1;
        } else if (a->minutos < b->minutos) {
            return 1;
        } else {
            return 0;
        }
    }
}

int transformaHora(hora *h) {
    int horasEmMinutos = h->horas * 60;
    return (horasEmMinutos + h->minutos + h->duracao);
}

int horasTemConflito(hora *a, hora *b) {
    int compara = comparaHoras(a, b);
    if (compara < 0) {
        if (transformaHora(b) >= (a->horas + a->minutos)) {
            return 1;
        } else {
            return 0;
        }
    } else if (compara > 0) {
        if (transformaHora(a) >= (b->horas + b->minutos)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

void imprimeHora(hora *h){

    printf("|horas: %d:%d\n", h->horas, h->minutos);
    printf("|duracao: %d\n", h->duracao);
}
