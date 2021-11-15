#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "Recordsort.h"
#include "Arraysort.h"

//Executavel:
//gcc main.c Recordsort.c Arraysort.c -o e
int main()
{
    clock_t t; //variavel para armazenar tempo
    double som_if = 0, som_M = 0;
    double som_Time = 0;
    int contador = 0;
    double cont_if = 0, move = 0;
    double media_if, media_move;
    int opcao0, opcao1, opcao2, opcao3, opcao4, opcao5;
    bool op_0 = true, op_1 = true, op_2 = true, op_3 = true, op_4 = true, op_5 = true;
    Tregister *reg;
    int *Array;
    int n;
    double teste;
    double time;
    clock_t end, begin;

    printf("|---------------------------------------------------|\n");
    printf("|    - Trabalho Pratico 3 - Aeds 1                  |\n");
    printf("|    - Gabriel Miranda - 3857                       |\n");
    printf("|    - Mariana Souza - 3898                         |\n");
    printf("|    - Felipe Dias - 3888                           |\n");
    printf("|---------------------------------------------------|\n");


    while (op_0 = true)
    {

        printf("\n");
        printf("|---------------------------------------------------|\n");
        printf("|     [1] - Cenario 1 => Array                      |\n");
        printf("|     [2] - Cenario 2 => Registro                   |\n");
        printf("|     [3] - Cenario 3 => Arquivo                    |\n");
        printf("|     [4] - Encerrar Programa                       |\n");
        printf("|---------------------------------------------------|\n");
        printf("Opcao: ");
        scanf("%d", &opcao0);

        if (opcao0 == 1)
        { //Vetores
            while (op_1 = true)
            {
                printf("\n");
                printf("|---------------------------------------------------|\n");
                printf("|    [0] - Inicializar Vetor => Array               |\n");
                printf("|    [1] - Selecionar o algoritmo de ordenacao      |\n");
                printf("|    [2] - Retornar aos Cenarios                    |\n");
                printf("|---------------------------------------------------|\n");
                printf("Opcao: ");
                scanf("%d", &opcao1);
                printf("\n");

                if (opcao1 == 0)
                { //inicializar com o tamnaho do vetor(n)
                    printf("\n");
                    printf("|---------------------------------------------------|\n");
                    printf("|   Digite o tamanho do Vetor => Array              |\n");
                    printf("|---------------------------------------------------|\n");
                    printf("Opcao: ");
                    scanf("%d", &n);
                    printf("\n");
                    free(Array);
                    Array = InicializaArray(n);
                    printf("Vetor aleatorio gerado => ");
                    imprimeAleatorio(Array, n);
                    printf("\n");
                }

                if (opcao1 == 1)
                { //Selecionar o algoritmo de ordenação
                    while (op_3 = true)
                    {
                        printf("\n");
                        printf("|---------------------------------------------------|\n");
                        printf("|    [1] - Bubblesort                               |\n");
                        printf("|    [2] - Selectsort                               |\n");
                        printf("|    [3] - Insertionsort                            |\n");
                        printf("|    [4] - Shellsort                                |\n");
                        printf("|    [5] - Quicksort                                |\n");
                        printf("|    [6] - Heapsort                                 |\n");
                        printf("|    [7] - Mergesort                                |\n");
                        printf("|    [8] - Radixsort                                |\n");
                        printf("|    [9] - Imprimir Array                           |\n");
                        printf("|    [10] - Retornar                                |\n");
                        printf("|---------------------------------------------------|\n");
                        printf("Opcao: ");
                        scanf("%d", &opcao3);
                        printf("\n");

                        if (opcao3 == 1) //bubble sort array
                        {
                            begin = clock();
                            Bubblesort_A(Array, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeArray(Array, n, &move, &cont_if, &time_spent);
                            printf("Vetor de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Bubblesort <=\n");
                        }

                        if (opcao3 == 2) //selection sort array
                        {
                            begin = clock();
                            Selectionsort_A(Array, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeArray(Array, n, &move, &cont_if, &time_spent);
                            printf("Vetor de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Selectionsort <=\n");
                        }

                        if (opcao3 == 3) //insertion sort array
                        {
                            begin = clock();
                            Insertionsort_A(Array, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeArray(Array, n, &move, &cont_if, &time_spent);
                            printf("Vetor de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Insertionsort <=\n");
                        }

                        if (opcao3 == 4) // shell sort array
                        {
                            begin = clock();
                            Shellsort_A(Array, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeArray(Array, n, &move, &cont_if, &time_spent);
                            printf("Vetor de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Shellsort <=\n");
                        }

                        if (opcao3 == 5) // quick sort array
                        {
                            begin = clock();
                            Quicksort_A(Array, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeArray(Array, n, &move, &cont_if, &time_spent);
                            printf("Vetor de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Quicksort <=\n");
                        }

                        if (opcao3 == 6) //heap sort array
                        {
                            begin = clock();
                            Heapsort_A(Array, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeArray(Array, n, &move, &cont_if, &time_spent);
                            printf("Vetor de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Heapsort <=\n");
                        }

                        if (opcao3 == 7) //Merge sort array
                        {
                            begin = clock();
                            Mergesort_A(Array, 0, n - 1, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeArray(Array, n, &move, &cont_if, &time_spent);
                            printf("Vetor de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Mergesort <=\n");
                        }
                        if (opcao3 == 8) //Radix sort array
                        {
                            begin = clock();
                            Radixsort_A(Array, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeArray(Array, n, &move, &cont_if, &time_spent);
                            printf("Vetor de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Radixsort <=\n");
                        }

                        if (opcao3 == 9) //imprimir array
                        {
                            imprimeAleatorio(Array, n);
                        }

                        if (opcao3 == 10) //retornar
                        {
                            op_3 = false;
                            break;
                        }
                    }
                }

                if (opcao1 == 2) //retornar ao cenario
                {
                    op_1 = false;
                    break;
                }
            }
        }

        if (opcao0 == 2) //registro
        {
            while (op_2 = true)
            {
                printf("\n");
                printf("|---------------------------------------------------|\n");
                printf("|    [0] - Inicializar vetor => Registro            |\n");
                printf("|    [1] - Selecionar o algoritmo de ordenacao      |\n");
                printf("|    [2] - Imprimir Registros                       |\n");
                printf("|    [3] - Retornar aos Cenarios                    |\n");
                printf("|---------------------------------------------------|\n");
                printf("Opcao: ");
                scanf("%d", &opcao2);
                printf("\n");

                if (opcao2 == 0) //tamanho do vetor registro
                {
                    printf("\n");
                    printf("|---------------------------------------------------|\n");
                    printf("|   Digite o tamanho do Vetor => Registros          |\n");
                    printf("|---------------------------------------------------|\n");
                    printf("Opcao: ");
                    scanf("%d", &n);
                    printf("\n");
                    free(reg);
                    reg = InicializaRegistro(n);
                    printf("Vetor de registro aleatorio gerado => ");
                    imprimeChavesAleatorias(reg, n);
                    printf("\n");
                }
                if (opcao2 == 1) //selecionar o algoritmo de ordenacao (registro)
                {
                    while (op_4 = true)
                    {
                        printf("\n");
                        printf("|---------------------------------------------------|\n");
                        printf("|    [1] - Bubblesort                               |\n");
                        printf("|    [2] - Selectsort                               |\n");
                        printf("|    [3] - Insertionsort                            |\n");
                        printf("|    [4] - Shellsort                                |\n");
                        printf("|    [5] - Quicksort                                |\n");
                        printf("|    [6] - Heapsort                                 |\n");
                        printf("|    [7] - Mergesort                                |\n");
                        printf("|    [8] - Radixsort                                |\n");
                        printf("|    [9] - Imprimir Chave registro                  |\n");
                        printf("|    [10] - Retornar                                |\n");
                        printf("|---------------------------------------------------|\n");
                        printf("Opcao: ");
                        scanf("%d", &opcao4);
                        printf("\n");

                        if (opcao4 == 1) //bubble sort registro
                        {
                            begin = clock();
                            Bubblesort(reg, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeChave(reg, n, &move, &cont_if, &time_spent);
                            printf("Registro de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Bubblesort <=\n");
                        }

                        if (opcao4 == 2) //selection sort registro
                        {
                            begin = clock();
                            Selectionsort(reg, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeChave(reg, n, &move, &cont_if, &time_spent);
                            printf("Registro de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Selectionsort <=\n");
                        }

                        if (opcao4 == 3) //insertion sort registro
                        {
                            begin = clock();
                            Insertionsort(reg, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeChave(reg, n, &move, &cont_if, &time_spent);
                            printf("Registro de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Insertionsort <=\n");
                        }

                        if (opcao4 == 4) //shell sort registro
                        {
                            begin = clock();
                            Shellsort(reg, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeChave(reg, n, &move, &cont_if, &time_spent);
                            printf("Registro de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Shellsort <=\n");
                        }

                        if (opcao4 == 5) //quick sort registro
                        {
                            begin = clock();
                            Quicksort(reg, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeChave(reg, n, &move, &cont_if, &time_spent);
                            printf("Registro de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Quicksort <=\n");
                        }

                        if (opcao4 == 6) //heap sort registro
                        {
                            begin = clock();
                            Heapsort(reg, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeChave(reg, n, &move, &cont_if, &time_spent);
                            printf("Registro de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Heapsort <=\n");
                        }

                        if (opcao4 == 7) //merge sort registro
                        {
                            begin = clock();
                            Mergesort(reg, 0, n-1, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeChave(reg, n, &move, &cont_if, &time_spent);
                            printf("Registro de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Mergepsort <=\n");
                        }

                        if (opcao4 == 8)//radix sort registro
                        {
                            begin = clock();
                            Radixsort(reg, n, &cont_if, &move);
                            end = clock();
                            double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
                            imprimeChave(reg, n, &move, &cont_if, &time_spent);
                            printf("Registro de tamanho:%d\n",n);
                            printf("\n=> Ordenado Pelo Radixpsort <=\n");
                        }

                        if (opcao4 == 9)//imprime registro
                        {
                            imprimeChavesAleatorias(reg, n);
                        }

                        if (opcao4 == 10)
                        { //retorna
                            op_4 = false;
                            break;
                        }
                    }
                }
                if (opcao2 == 2)//imprime registro
                {
                    imprimeChavesAleatorias(reg, n);
                }

                if (opcao2 == 3)
                { //retorna cenario
                    op_2 = false;
                    break;
                }
            }
        }
        if (opcao0 == 3)
        {
            while (op_5 = true)
            {
                printf("\n");
                printf("|---------------------------------------------------|\n");
                printf("|   [1] - Array                                     |\n");
                printf("|   [2] - Registro                                  |\n");
                printf("|   [3] - Retornar                                  |\n");
                printf("|---------------------------------------------------|\n");
                printf("Opcao: ");
                scanf("%d", &opcao5);

                if (opcao5 == 1)
                {
                    printf("|---------------------------------------------------|\n");
                    printf("|   Digite o tamanho do vetor:                      |\n");
                    printf("|---------------------------------------------------|\n");
                    printf("Opcao: ");
                    scanf("%d", &n);
                    printf("|---------------------------------------------------|\n");
                    printf("|   Digite os testes para esse vetor:               |\n");
                    printf("|---------------------------------------------------|\n");
                    printf("Opcao: ");
                    scanf("%lf", &teste);
                    TesteRapidoArray(Array, n, teste);
                }
                if (opcao5 == 2)
                {
                    printf("|---------------------------------------------------|\n");
                    printf("|   Digite o tamanho dos Registros:                 |\n");
                    printf("|---------------------------------------------------|\n");
                    printf("Opcao: ");
                    scanf("%d", &n);
                    printf("|---------------------------------------------------|\n");
                    printf("|   Digite os testes para esse registro:             |\n");
                    printf("|---------------------------------------------------|\n");
                    printf("Opcao: ");
                    scanf("%lf", &teste);
                    TesteRapidoRegistro(reg, n, teste);
                }
                if (opcao5 == 3)
                {
                    op_5 = false;
                    break;
                }
            }
        }
        if (opcao0 == 4)
        {
            op_0 = false;
            break;
        }
    }
    return 0;
}
