#include "sat.h"

Tclausula* inicializaClausula(int n, int nclaus){
   Tclausula *clausula = (Tclausula*) malloc(nclaus * sizeof(Tclausula));
   
   for (int i = 0; i < nclaus; i++){
      printf("\n");
      printf("|---------------------------|\n");
      printf("|  Preencha a Clausula %d:\n",i+1);
      printf("|---------------------------|\n");
      printf("\n");
      inicializaTupla(clausula[i].tupla, n);
      printf("\n");
   }

    return clausula;
}

Tclausula* randClausula(int **matriz, int n, int nclaus){
    Tclausula *clausula = (Tclausula*) malloc(nclaus * sizeof(Tclausula));
     int k;
      for (int i = 0; i < nclaus; i++){
         k = 0;
         for (int j = 0; j < n; j++){
             if(matriz[i][j] == 1 || matriz[i][j] == 2){
                  clausula[i].tupla[k].var = j+1;
                  clausula[i].tupla[k].VF = matriz[i][j];
                  k++;
             }
         }
         
     }

    return clausula;
}

void TransfomarTrue(Tclausula *clausula, int nclaus, char *combinacao){
     int fazTrue = 0;   
     int i,j = 0;
     int valor;
     char verifica;
     bool op = true;

     for(i = 0; i < nclaus; i++){   
         op = true;                       
         j = 0;
         while((op == true) && (j<3) ){              // se n = 2 -- combinacao[0,1]-2 caracteres - valor vai de de 1 ate N que nesse caso é 2; entao (valor = 1 -> combinacao[0, ou valor-1])
             valor = clausula[i].tupla[j].var;       //recebendo posicao se valor = 1; na combinacao[0] - combinacao[valor-1]
                if(clausula[i].tupla[j].VF == 1){    //se é negado
                    if(combinacao[valor-1] == 'V'){  //    se for negado a combi[i] = V;
                        verifica = 'F';              //        verifica = F;
                    }else{                           //    senao
                        verifica = 'V';              //       verifica = V
                    } 
                }else{                               //se nao é negado  
                    if(combinacao[valor-1] = 'V'){   //    se combinacao[i] = V
                        verifica = 'V';              //        verifica = V
                    }else{                           //     senao
                        verifica = 'F';              //         verifica = F
                    }
                }
                if(verifica == 'V'){
                     fazTrue++; // na hora que achar pelo menos um valor V na clausula, para o programa
                     op = false;   
                }
             j++; 
         }
     }
     if(fazTrue == nclaus){ //se a quantidade de verdadeios em cada clausula for igual ao Nº clausulas - condicao verdadeira
         printf("Essa solucao resolve a Equacao:%s\n", combinacao);
     }
}

void combinacao(int r, Tclausula *clausula, int nclaus){
     /* Nosso número na base n. Ele é um vetor
     * de n+1 posições representando um número
     * na base n.
     */
   // int contador = 0;
    int *num ;
    /* input é a string de entrada, e str
     * receberá cada permutação.
     */ 
    char input[MAX] = "VF" , str[MAX];
    int n, i, j, k ; //retirei o r

    //printf("Entre com o conjunto inicial: ") ;
    //scanf("%s", input) ;

    /*printf("Entre com o N: ") ;
    scanf("%d", &r) ;*/

    /* Aqui elimina-se caracteres repetidos na entrada.
     * Esse procedimento não faz parte do algoritmo, e
     * só é feito por questões práticas.
     */
    n = strlen(input) ;
    j = 0;
    str[0] = 0 ;
    for ( i = 0; i < n; i++ ) {
        if ( strchr(str, input[i]) == NULL ) {
            str[j] = input[i] ;
            j++ ;
            str[j] = 0 ;
        }
    }
    strcpy(input, str) ;
    n = strlen(input) ;

    /* Cria o nosso número. Ele é um vetor de
     * r+1 posições, sendo que a última é 
     * reservada para indicar quando todos os
     * números de tamanho r foram gerados. */
    num = (int *) calloc( (r+1), sizeof(int)) ;
    if ( num == NULL ) {
        perror("calloc") ;
      //  return -1;  // acho que nao precisa
    }

    /* Termina quando a última posição do vetor
     * for 1. */
    while ( num[r] == 0 ) {
        for ( i = 0; i < n; i++ ) {
            /* processo de mapeamento. */
            for ( j = 0, k = r-1; j < r; j++ ) {
                str[k] = input[num[j]] ;
                k-- ;
            }
            /* Mostra o resultado. */
            str[r] = 0 ;
         //  contador++;
         //  printf("%d\n",contador);
            if(clausula == NULL){
                printf("%s\n", str);
            }else{
                 TransfomarTrue(clausula, nclaus, str);
            }
            

            /* incrementa o algarismo menos significativo. */
            num[0]++ ;
        }

        /* Muda de "casa" e lança os vai uns. */ 
        for ( i = 0; i < r; i++ ) {
            if ( num[i] == n ) {
                num[i] = 0 ;
                num[i+1]++ ;
            }
        }
    }
}


int** PreenchaMatrizClausula(Tclausula *clausula, int nclaus, int N){
    int i,j;
    int **matriz = (int**)malloc(nclaus * sizeof(int));
   
    for (i = 0; i < nclaus; i++){ 
        matriz[i] = (int*) malloc(N * sizeof(int)); 
        for (j = 0; j < N; j++){ //Percorre o Vetor de Inteiros atual.
             matriz[i][j] = 0; //Inicializa com 0.
        }
    }

  int ale1,ale2,ale3;
  bool op;
  for(i = 0; i<nclaus; i++){
          op = true;
          ale1 = rand() % N;
          matriz[i][ale1] = 1 + rand() % 2; // gerando numeros de 0 a n
          while (op == true){
              ale2 = rand() % N;
              if (ale1 != ale2){
                   matriz[i][ale2] = 1 + rand() % 2;
                   op = false;
              }   
          }
          op = true;
          while (op == true){
            ale3 = rand() % N;
            if(ale2 != ale3 && ale1 != ale3){
              matriz[i][ale3] = 1 + rand() % 2;
              op = false;
            } 
         }       
  } 

   return matriz; //Retorna o Ponteiro para a Matriz Alocada

} 

void imprimeMatriz(int **matriz, int nclaus, int N){
    int i,j;
    for (i = 0; i < nclaus; i++){ 
        for (j = 0; j < N; j++){
            printf("%d ",matriz[i][j]); 
        }
        printf("\n");
    }
}

void imprimeClausulas(Tclausula *clausula, int n){
    int i;
    for(i = 0; i<n; i++){
        printf("{");
        imprimeTupla(clausula[i].tupla);
        printf("} ");
    }
    
}