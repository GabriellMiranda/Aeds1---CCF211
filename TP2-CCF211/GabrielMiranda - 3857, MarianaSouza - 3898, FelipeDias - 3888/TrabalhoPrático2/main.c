#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "sat.h"
#include "tupla.h"
// gcc main.c tupla.c sat.c -o e
int main() {

   clock_t t; //variável para armazenar tempo
   bool op_1 = true, op_2 = true;
   int opcao1, opcao2;
   int N;
   int Nteste; // Testar se o algoritmo de combinação funciona
   int nclaus; // Numero de Clausulas
   Tclausula *Clausula;// Variável que contem uma equacao de clausulas
   int **Matriz;

    printf("|---------------------------------------------------|\n");
    printf("|    - Trabalho Pratico 2 - Aeds 1                  |\n");
    printf("|    - Gabriel Miranda - 3857                       |\n");
    printf("|    - Mariana Souza - 3898                         |\n");
    printf("|    - Felipe Dias - 3888                           |\n");
    printf("|---------------------------------------------------|\n");
   
   while (op_1 == true)
   {
            printf("\n");
            printf("|---------------------------------------------------|\n");
            printf("|    [1] - Modo Interativo                          |\n");
            printf("|    [2] - Modo Automatico                          |\n");
            printf("|    [3] - Combinacoes para N                       |\n");
            printf("|    [4] - Imprime Equacao                          |\n");
            printf("|    [5] - Sair                                     |\n");
            printf("|---------------------------------------------------|\n");
            printf("Opcao: ");
            scanf("%d", &opcao1);
            printf("\n");
       switch (opcao1)
       {
       case 1: //modo interativo
                
           printf("Digite o Numero de Clausulas:\n");
           scanf("%d", &nclaus);
           printf("Digite o valor de N:\n");
           scanf("%d", &N);
           Clausula = inicializaClausula(N, nclaus);
           combinacao(N, Clausula, nclaus);
           break;

       case 2: //modo automático
         op_2 = true;
            while (op_2){
                    printf("\n");
                    printf("|---------------------------------------------------|\n");
                    printf("|   [1] - Combinacoes que satifacam a EQ. Aleatoria |\n");
                    printf("|   [2] - Imprime Matriz Aleatoria                  |\n");
                    printf("|   [3] - Imprime Equacao Aleatoria                 |\n");
                    printf("|   [4] - Sair                                      |\n");
                    printf("|---------------------------------------------------|\n");
                    printf("Opcao: ");
                    scanf("%d", &opcao2);
                    printf("\n");
            
                switch (opcao2)
                {
                case 1: //Preenche uma matriz com valores aleatorios
                    printf("Digite o valor de N:");
                    scanf("%d", &N);
                    nclaus = (N/3)*2;
                    printf("Numero de Clausulas:%d\n", nclaus);
                    Matriz = PreenchaMatrizClausula(Clausula, nclaus, N);  
                    Clausula = randClausula(Matriz, N, nclaus);  
                    t = clock(); //armazena tempo
                    combinacao(N, Clausula, nclaus);
                    t = clock() - t; //tempo final - tempo inicial
                    //imprime o tempo na tela*/
                    printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC))); //conversão para double
                    break;

                case 2:// imprime a matriz aleatoria
                    imprimeMatriz(Matriz, nclaus, N);
                    break;

                case 3:// imprime clausula aleatoria
                    imprimeClausulas(Clausula, nclaus); 
                    printf("\n");
                    break;

                case 4: // sai do submenu
                    free(Clausula);
                    Clausula = NULL;
                    free(Matriz);
                    Matriz = NULL;
                    op_2 = false;
                    break;

                default:
                printf("Opcao Invalida!!\n");
                    break;
                }
            }

       case 3: // Testa o algoritmo de combinação para ver se ele está funcionando
        if(opcao1 == 3){
         Clausula = NULL;
         printf("Digite o valor de N:\n");
         scanf("%d",&Nteste);
         combinacao(Nteste, Clausula, nclaus);
        }
        break;

       case 4: // imprime clausulas
       if(Clausula == NULL){
           printf("Error\n");
           printf("Nenhuma Clausula foi preenchida no modo Interativo!!\n");
           break;
       }
        if(opcao1 == 4){
           imprimeClausulas(Clausula, nclaus);
           printf("\n");
        } 
           break;

       case 5:
           op_1 = false;
           break;

       default:
           printf("Opcao Invalida!!\n");
           break;
       }
   }
   

    return 0 ;
}