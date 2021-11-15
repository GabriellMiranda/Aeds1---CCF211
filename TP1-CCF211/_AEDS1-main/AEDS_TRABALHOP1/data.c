#include <stdio.h>
#include <stdlib.h>

#include "data.h"

data *inicializaData(int dia, int mes, int ano) {
    data *d = (data*) malloc(sizeof(data));
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
    return d;
}

void imprimeData(data *d) {
    printf("|%d/%d/%d\n", d->dia, d->mes, d->ano);
}

int comparaDatas(data *a, data *b) {
    if (a->dia == b->dia) {
        if(a->mes == b->mes) {
            if (a->ano == b->ano) {
                return 1;
            }
        }
    }
    return 0;
}


