#ifndef AEDS_TRABALHOP1_ENDERECO_H
#define AEDS_TRABALHOP1_ENDERECO_H

#define max 30
typedef struct{
    char estado[max];
    char cidade[max];
    char bairro[max];
    char rua[max];
    char cep[max];
}Tendereco;

Tendereco *inicializaEndereco();//retorna um endereco
void imprimeEndereco();//imprime o endereco

#endif //AEDS_TRABALHOP1_ENDERECO_H
