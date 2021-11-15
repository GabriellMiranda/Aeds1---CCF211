#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LeituraArquivo.h"

void Inicializa_Arquivo(TLagenda *L_agenda){

    FILE *arquivo;
    Tagenda *AUx_agenda;
    int tratador;
    int i,j;
    TleituraArquivo dado;
    char nome_arquivo[40];
    Tcompromisso *compro;
    TLcompromisso lcompromisso;
    data *d;
    hora *h;

    printf("Digite o nome do arquivo que voce quer inserir na lista Agenda:\n");
    setbuf(stdin, 0);
    gets(nome_arquivo);
    arquivo = fopen(nome_arquivo,"r");

    if(arquivo == NULL){
        printf("O arquivo nao existe!!\n");
    }
    else{
        fgets(dado.qnt_professores, 20, arquivo);
        dado.qnt_profs = atoi(dado.qnt_professores);
        printf("%d \n", dado.qnt_profs);
        for (i=0;i<dado.qnt_profs;i++){

            fgets(dado.qnt_compromissos, 20, arquivo);
            dado.qnt_compro = atoi(dado.qnt_compromissos);
            printf("%d \n", dado.qnt_compro);

            fgets(dado.id_prof, 20, arquivo);
            dado.id_prof[(int)strlen(dado.id_prof)-1] = '\0';
            printf("%s \n", dado.id_prof);


            fgets(dado.nome, 50, arquivo);
            dado.nome[(int)strlen(dado.nome)-1] = '\0';
            printf("%s \n", dado.nome);

            fgets(dado.ano_agenda, 20, arquivo);
            dado.ano = atoi(dado.ano_agenda);
            printf("%d \n", dado.ano);

            AUx_agenda = criaAgenda(dado.id_prof, dado.nome, dado.ano);

            Insere_LAgenda(L_agenda, AUx_agenda);

            for (j=0;j<dado.qnt_compro;j++){

                fgets(dado.prioridade_compro, 20, arquivo);
                dado.prioridade = atoi(dado.prioridade_compro);
                printf("%d \n", dado.prioridade);
                fgets(dado.dia_compro, 20, arquivo);

                dado.data_compromisso.dia = atoi(dado.dia_compro);
                printf("%d \n", dado.data_compromisso.dia);
                fgets(dado.mes_compro, 20, arquivo);

                dado.data_compromisso.mes = atoi(dado.mes_compro);
                printf("%d \n", dado.data_compromisso.mes);
                fgets(dado.ano_compro, 20, arquivo);

                dado.data_compromisso.ano = atoi(dado.ano_compro);
                printf("%d \n", dado.data_compromisso.ano);
                fgets(dado.hora_compro, 20, arquivo);

                dado.horas_compromisso.horas = atoi(dado.hora_compro);
                printf("%d \n", dado.horas_compromisso.horas);
                fgets(dado.minuto_compro, 20, arquivo);

                dado.horas_compromisso.minutos = atoi(dado.minuto_compro);
                printf("%d \n", dado.horas_compromisso.minutos);
                fgets(dado.duracao_compro, 20, arquivo);

                dado.duracao_min_compromisso = atoi(dado.duracao_compro);
                printf("%d \n", dado.duracao_min_compromisso);

                fgets(dado.descricao_compromisso, 100, arquivo);
                dado.descricao_compromisso[(int)strlen(dado.descricao_compromisso)-1] = '\0';
                printf("%s \n", dado.descricao_compromisso);

                d = inicializaData(dado.data_compromisso.dia,dado.data_compromisso.mes,dado.data_compromisso.ano  );

                h = inicializaHora(dado.horas_compromisso.horas,dado.horas_compromisso.minutos, dado.duracao_min_compromisso );

                compro = inicializaCompromisso(dado.prioridade, d, h, dado.duracao_min_compromisso, dado.descricao_compromisso);

                tratador = insereCompromisso(L_agenda->ultimo->Agenda, compro);
            }
        }
    }
    fclose(arquivo);
}
