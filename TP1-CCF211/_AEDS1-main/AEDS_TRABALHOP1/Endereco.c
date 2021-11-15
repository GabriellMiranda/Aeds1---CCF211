#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Endereco.h"

Tendereco *inicializaEndereco(){
    Tendereco *endereco = (Tendereco*)malloc(sizeof (Tendereco));
    printf("Digite seu Estado:\n");
    setbuf(stdin, 0);
    gets(endereco->estado);

    printf("Digite sua Cidade:\n");
    setbuf(stdin, 0);
    gets(endereco->cidade);

    printf("Digite seu bairro:\n");
    setbuf(stdin, 0);
    gets(endereco->estado);

    printf("Digite sua rua:\n");
    setbuf(stdin, 0);
    gets(endereco->rua);

    printf("Digite seu CEP:\n");
    setbuf(stdin, 0);
    gets(endereco->cep);

    return endereco;
}

void imprimeEndereco(Tendereco *endereco){

    printf("|Estado:%s\n", endereco->estado);
    printf("|Cidade:%s\n", endereco->cidade);
    printf("|Bairro:%s\n", endereco->bairro);
    printf("|Rua:%s\n", endereco->rua);
    printf("|CEP:%d\n", endereco->cep);

}

