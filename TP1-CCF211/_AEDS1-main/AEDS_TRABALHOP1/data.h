#ifndef AEDS_TRABALHOP1_DATA_H
#define AEDS_TRABALHOP1_DATA_H

typedef struct data {
    int dia;
    int mes;
    int ano;
} data;

data *inicializaData(int dia, int mes, int ano);// retorna uma data alocada 
int comparaDatas(data *a, data *b);//verifica se as datas tem conflito 
void imprimeData(data*);//imprime as datas

#endif //AEDS_TRABALHOP1_DATA_H
