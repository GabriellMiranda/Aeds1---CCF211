#ifndef AEDS_TRABALHOP1_LCOMPROMISSO_H
#define AEDS_TRABALHOP1_LCOMPROMISSO_H

#include "compromisso.h"
#include "hora.h"
#include "data.h"

typedef struct c_compromisso {
    Tcompromisso* c;
    struct c_compromisso *prox;
}celula_compromisso;

typedef struct l_compromisso {
    celula_compromisso* Primeiro;
    celula_compromisso* Ultimo;
} TLcompromisso;

void inicializaLCompromisso(TLcompromisso *Lcompromisso);//inicializando uma lista de compromissos
int insereLCompromisso(TLcompromisso *Lcompromisso, Tcompromisso *compromisso);//inserindo compromisso na lista compromisso
int LCompromissoEhVazia(TLcompromisso *Lcompromisso);// verifica se a lista compromisso esta vazia
celula_compromisso procuraCompromisso(TLcompromisso *compro,int id);// ao passar um id o usuario acha um determinado compromisso na lista de compromissos
int removeLCompromisso(TLcompromisso *Lcompromisso, int id);//remove um determinado compromisso
void imprimeLCompromisso(TLcompromisso *Lcompromisso);//imprime a lista de compromissos

#endif //AEDS_TRABALHOP1_LCOMPROMISSO_H
