#ifndef AEDS_TRABALHOP1_LEITURAARQUIVO_H
#define AEDS_TRABALHOP1_LEITURAARQUIVO_H

#include "compromisso.h"
#include "agenda.h"
#include "LAgenda.h"

typedef struct { //variaveis para a leitura do arquivo
    int ano;
    char nome[50]; 
    data data_compromisso;
    hora horas_compromisso;
    int duracao_min_compromisso;
    char descricao_compromisso[100];
    int prioridade;
    char nome_arquivo[40];
    char qnt_professores[20];
    int qnt_profs;
    char qnt_compromissos[20];
    int qnt_compro;
    char id_prof[20];
    char ano_agenda[4];
    char prioridade_compro[1];
    char dia_compro[2];
    char mes_compro[2];
    char ano_compro[4];
    char hora_compro[2];
    char minuto_compro[2];
    char duracao_compro[4];
    int insereIdentificador_compromisso;
}TleituraArquivo;

void Inicializa_Arquivo(TLagenda *Agenda_pro);//Leitura do arquivo

#endif //AEDS_TRABALHOP1_LEITURAARQUIVO_H
