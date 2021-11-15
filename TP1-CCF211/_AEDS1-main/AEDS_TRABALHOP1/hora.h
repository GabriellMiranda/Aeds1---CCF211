#ifndef AEDS_TRABALHOP1_HORA_H
#define AEDS_TRABALHOP1_HORA_H

typedef struct hora {
    int horas;
    int minutos;
    int duracao;
} hora;

hora *inicializaHora(int horas, int minutos, int duracao);// retorna a hora
int comparaHoras(hora* a, hora* b);// compara o horario
int transformaHora(hora* horas);//transforma horas em minutos
int horasTemConflito(hora* a, hora* b);// verifica se tem conflito nas horas
void imprimeHora(hora* horas);// imprime as horas

#endif //AEDS_TRABALHOP1_HORA_H
