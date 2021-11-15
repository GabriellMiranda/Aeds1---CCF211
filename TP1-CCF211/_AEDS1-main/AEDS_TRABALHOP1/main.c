#include <stdio.h>
#include <stdlib.h>
#include <string.h>                                                 
#include <stdbool.h>
#include "compromisso.h"                                                                            
#include "agenda.h"
#include "LCompromisso.h"
#include "hora.h"
#include "data.h"                                                   
#include "LAgenda.h"
#include "LeituraArquivo.h"
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
int main(){                                                                                                                                                      

    TLagenda *Lista_Agenda = (TLagenda *) malloc(sizeof (TLagenda));
    Tcelula_Agenda CpAux_agenda;// recebe uma celula agenda
    Tagenda *TipoAgenda;
    Tcompromisso *compro;

    data *d;
    hora *h;
    celula_compromisso celulacompro; // recebe uma determinada celula de compromissos

    int escolhe;
    //Variaveis de inicializar uma Agenda:
    char idProf[20];
    char nomeProf[50];
    int tratador;
    int idcompro;
    int prioridade;

    //variaveis para inicializar um compromisso;
    int horas, minutos, duracao;
    int dia, mes, ano;
    char descricao[100];

    int opcao_1, opcao_2;
    bool op_1 = true;
    bool op_2 = true;

    printf("|---------------------------------------------------|\n");
    printf("|    - Trabalho Pratico 1 - Aeds 1                  |\n");
    printf("|    - Gabriel Miranda - 3857                       |\n");
    printf("|    - Mariana Souza - 3898                         |\n");
    printf("|    - Felipe Dias - 3888                           |\n");
    printf("|---------------------------------------------------|\n");

    FLvazia_LAgenda(Lista_Agenda);

    while(op_1 == true) {
        printf("\n");
        printf("|---------------------------------------------------|\n");
        printf("|  [1] - Criar Agenda:                              |\n");
        printf("|  [2] - Leia o arquivo:                            |\n");
        printf("|  [3] - Faca login:                                |\n");
        printf("|  [4] - Mostrar a agenda de todos os professores:  |\n");
        printf("|  [5] - Sair                                       |\n");
        printf("|---------------------------------------------------|\n");
        printf("Opcao: ");
        scanf("%d", &opcao_1);
        printf("\n");

        switch (opcao_1) {

            case 1: // Cria uma agenda;

                printf("Digite seu nome:\n");
                setbuf(stdin, 0);
                gets(nomeProf);

                printf("Digite o seu id de professor:\n");
                setbuf(stdin, 0);
                gets(idProf);

                printf("Digite o ano da Agenda:\n");
                scanf("%d", &ano);

                CpAux_agenda = Procura_agenda_professor(Lista_Agenda, idProf);

                TipoAgenda = criaAgenda(idProf, nomeProf, ano);
                printf("\n");
                printf("AGENDA CRIADA!\n");
                Insere_LAgenda(Lista_Agenda, TipoAgenda);

                    break;

            case 2: //Leitura de arquivo
                Inicializa_Arquivo(Lista_Agenda);
                printf("\n");

                break;

            case 3:  // Faz login no sistema

                printf("Digite o Identificador da sua Agenda:\n");
                setbuf(stdin, 0);
                gets(idProf);

                CpAux_agenda = Procura_agenda_professor(Lista_Agenda, idProf);

                if(strcmp(CpAux_agenda.Agenda->idProf, idProf) == 0){


                    while (op_2 == true) {

                        if(CpAux_agenda.Agenda->professor == NULL){
                            printf("\n");
                            printf("|--------------------------------------------------------|\n");
                            printf("|   Deseja inserir suas informacoes como professor!?     |\n");
                            printf("|   [1] - Sim                                            |\n");
                            printf("|   [2] - Nao                                            |\n");
                            printf("|--------------------------------------------------------|\n");
                            printf("opcao:");
                            scanf("%d",&escolhe);

                            if(escolhe == 1) {
                                CpAux_agenda.Agenda->professor = inicializaProfessor();
                                printf("\n");
                                printf("Informacoes adicionais inseridadas!!\n");
                            }
                        }
                        printf("\n");
                        printf("|-----------------------------------------|\n");
                        printf("|   [1] - Recuperar Agenda                |\n");
                        printf("|   [2] - Inserir Compromisso             |\n");
                        printf("|   [3] - Remover compromisso             |\n");
                        printf("|   [4] - Imprimir Compromissos           |\n");
                        printf("|   [5] - Imprimir Apenas um compromisso  |\n");
                        printf("|   [6] - Retornar qtd compromissos       |\n");
                        printf("|   [7] - Altera prioridade Compromisso   |\n");
                        printf("|   [8] - Sair                            |\n");
                        printf("|-----------------------------------------|\n");
                        printf("Opcao: ");
                        scanf("%d", &opcao_2);
                        printf("\n");


                        switch (opcao_2) {

                            case 1: // Essse case ira mostrar a quantidade de compromissos posteriores a data passada pelo dono da agenda
                                
                                printf("Digite o dia desse compromisso:\n");
                                scanf("%d", &dia);

                                printf("Digite o mes desse compromisso:\n");
                                scanf("%d", &mes);

                                printf("Digite o ano desse compromisso:\n");
                                scanf("%d", &ano);
            
                                d = inicializaData(dia, mes, ano);
                                recupera_Agenda(CpAux_agenda.Agenda, d);

                                
                                break;

                            case 2: //Inserir Compromisso na agenda;
                                
                                printf("Digite a prioridade desse compromisso:\n");
                                scanf("%d", &prioridade);

                                printf("Digite a descricao desse compromisso:\n");
                                setbuf(stdin, 0);
                                gets(descricao);

                                printf("Digite o dia desse compromisso:\n");
                                scanf("%d", &dia);

                                printf("Digite o mes desse compromisso:\n");
                                scanf("%d", &mes);

                                printf("Digite o ano desse compromisso:\n");
                                scanf("%d", &ano);

                                printf("Digite quantos minutos dura esse compromisso:\n");
                                scanf("%d", &duracao);

                                printf("Digite a hora (enter) e logo apos digite os minutos\n");
                                scanf("%d",&horas);
                                printf("Minutos:\n");
                        
                                scanf("%d",&minutos);


                                d = inicializaData(dia, mes, ano);

                                h = inicializaHora(horas, minutos, duracao);

                                compro = inicializaCompromisso(prioridade, d, h, duracao, descricao);

                                tratador = insereCompromisso(CpAux_agenda.Agenda, compro);

                                if (tratador != 0) {
                                    printf("\nCOMPROMISSO INSERIDO COM SUCESSO\n");
                                    printf("Seu id: %d\n", tratador);
                                } else {
                                    printf("\nSEU COMPROMISSO NAO FOI INSERIDO\n");
                                }

                                break;

                            case 3: // Remove Compromisso da agenda;

                                printf("Digite o id do compromisso que voce deseja remover:\n");
                                scanf("%d", &idcompro);
                                 tratador = removeCompromisso(CpAux_agenda.Agenda, idcompro);
                                if (tratador == 1) {
                                    printf("\n");
                                    printf("REMOCAO SUCEDIDA\n");
                                } else {
                                    printf("\nNAO FOI FEITA A REMOCAO\n");
                                }

                                break;

                            case 4: // Imprimir compromissos da agenda;
                                printf("\n");
                                imprimeLCompromisso(CpAux_agenda.Agenda->compromissos);
                                printf("\n");
                                break;

                            case 5: // imprimir um compromisso especifico da agenda;

                                printf("Digite o id do compromisso que voce quer encontrar:\n");
                                scanf("%d",&prioridade);
                                celulacompro = procuraCompromisso(CpAux_agenda.Agenda->compromissos, prioridade);
                                imprimeCompromisso(celulacompro.c);

                                break;

                            case 6: // Retorna quantidade de compromissos
                                tratador = retornaNCompromissos(CpAux_agenda.Agenda);
                                printf("Quantidade de compromissos:%d\n", tratador);
                                break;

                            case 7: // Altera a prioridade de um compromisso
                                printf("Digite o id do compromisso que voce quer encontrar:\n");
                                scanf("%d",&prioridade);
                                celulacompro = procuraCompromisso(CpAux_agenda.Agenda->compromissos, prioridade);
                                printf("Digite a nova prioridade desse compromisso:\n");
                                scanf("%d", &prioridade);
                                alteraPrioridade(celulacompro.c, prioridade);
                                printf("Prioridade ALterada para %d\n",prioridade);
                                break;

                            case 8: // sai do menu e retorna a outro menu;
                                op_2 = false;
                                break;

                            default:
                                printf("Opcao Invalida!!\n");
                                break;
                        }

                    }

                } else {
                    printf("seu id nao existe:\n");
                    break;
                }


            case 4: // Mostra a agenda de todos os professore com seu compromissso
                if(opcao_1 == 4) {
                    printf("\n");
                    Imprime_LAgenda(Lista_Agenda);
                    printf("\n");
                }
                break;

            case 5: // Sai do menu
                op_1 = false;
                break;

            default:
                printf("Opcao Invalida!!");
        }
    }

    return 0;
}





