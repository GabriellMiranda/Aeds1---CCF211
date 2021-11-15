#include "tupla.h"


void inicializaTupla(Ttupla *tupla, int n){
  for(int i = 0; i< 3; i++){
      printf("\n");
      printf("Digite a Variavel da Tupla %d:\n",i+1);
      scanf("%d",&tupla[i].var);
      while(tupla[i].var > n){
              printf("Variavel maior que N = %d!!\n",n);
              printf("Digite o valor da variavel novamente:\n");
              scanf("%d",&tupla[i].var);
      }
      printf("|---------------------------|\n");
      printf("|    [1] - Negado           |\n");
      printf("|    [2] - Nao Negado       |\n");
      printf("|---------------------------|\n");
      scanf("%d",&tupla[i].VF); 

      while ((tupla[i].VF > 2) || (tupla[i].VF < 0)) {
         printf("Valor de Negacao Incorreto!!\n");
         printf("Digite Novamente:\n");
         scanf("%d",&tupla[i].VF);
      }
      
  }
}
      
void imprimeTupla(Ttupla *tupla){
    for (int i = 0; i < 3; i++){
      if(i < 2){
         printf("(%d, %d), ",tupla[i].var, tupla[i].VF);
      }else{
         printf("(%d, %d)",tupla[i].var, tupla[i].VF); 
      } 
    }
}
