#include "Recordsort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Tregister *InicializaRegistro(int n)
{
   Tregister *reg = (Tregister *)malloc(n * sizeof(Tregister));
   for(int k = 0; k<n; k++){
       reg[k].itens = (Titem*) malloc(10 * sizeof(Titem));
   }
   for (int i = 0; i < n; i++){
      reg[i].Chave = rand() % n;
   }

   return reg;
}

void imprimeChavesAleatorias(Tregister *reg, int n)
{
   printf("[");
   for (int i = 0; i < n; i++)
   {
      printf("%d ", reg[i].Chave);
   }
   printf("]");
}

void imprimeChave(Tregister *reg, int n, double *move, double *cont_if, double *time_spend)
{
   printf("Vetor ordenado => ");
   printf("[");
   for (int i = 0; i < n; i++)
   {
      printf("%d ", reg[i].Chave);
   }
   printf("]");
   printf("\n");
   printf("Vetor de registro ordenado! \n");

   printf("\n");
   printf("Tempo de execucao => %.5lf\n", *time_spend);
   printf("Quantidade de movimentacoes => %.2lf\n", *move);
   printf("Quantidade de comparacoes => %.2lf\n", *cont_if);
   printf("\n");

   *time_spend = 0;
   *move = 0;
   *cont_if = 0;
}

void Bubblesort(Tregister *reg, int n, double *cont_if, double *cont_move)
{
   int i, j;
   Tregister aux;
   for (i = 0; i < n - 1; i++)
   {
      for (j = 1; j < n - i; j++)
      {
         (*cont_if)++;
         if (reg[j].Chave < reg[j - 1].Chave)
         {
            (*cont_move)++;
            aux = reg[j];
            reg[j] = reg[j - 1];
            reg[j - 1] = aux;
         }
      }
   }
}

void Selectionsort(Tregister *reg, int n, double *cont_if, double *cont_move)
{
   int i, j, min;
   Tregister aux;
   for (i = 0; i < n - 1; i++)
   {
      min = i;
      for (j = i + 1; j < n; j++)
      {
         (*cont_if)++;
         if (reg[j].Chave < reg[min].Chave)
         {
            min = j;
         }
      }
      if (i != min)
      {
         (*cont_move)++;
         aux = reg[i];
         reg[i] = reg[min];
         reg[min] = aux;
      }
   }
}

void Insertionsort(Tregister *reg, int n, double *cont_if, double *cont_move)
{
   int i, j;
   Tregister aux;
   for (i = 0; i < n; i++)
   {
      aux = reg[i];

      for (j = i; (j > 0) && (aux.Chave < reg[j - 1].Chave); j--)
      {
         (*cont_if)++;
         reg[j] = reg[j - 1];
         (*cont_move)++;
      }
      if (j > 0)
      {
         (*cont_if)++;
      }
      reg[j] = aux;
   }
}

void Shellsort(Tregister *reg, int n, double *cont_if, double *cont_move)
{
   int i, j;
   int h = 1;
   Tregister aux;
   do
      h = h * 3 + 1;
   while (h < n);
   do
   {
      h = h / 3;
      for (i = h; i < n; i++)
      {
         aux = reg[i];
         j = i;
         (*cont_if)++;
         while (reg[j - h].Chave > aux.Chave)
         {

            reg[j] = reg[j - h];
            j -= h;
            (*cont_move)++;
            if (j < h)
               break;
         }
         reg[j] = aux;
      }
   } while (h != 1);
}

void Ordena(int Esq, int Dir, Tregister *reg, double *cont_if, double *cont_move)
{
   int i, j;
   Particao(Esq, Dir, &i, &j, reg, cont_if, cont_move);
   if (Esq < j)
   {
      Ordena(Esq, j, reg, cont_if, cont_move);
   }
   if (i < Dir)
   {
      Ordena(i, Dir, reg, cont_if, cont_move);
   }
}
void Quicksort(Tregister *reg, int n, double *cont_if, double *cont_move)
{
   Ordena(0, n - 1, reg, cont_if, cont_move);
   //printf("dentro da funcao: if= %d\n", *cont_if);
   //printf("move = %d\n", *cont_move);
}
void Particao(int Esq, int Dir, int *i, int *j, Tregister *reg, double *cont_if, double *cont_move)
{
   Tregister pivo, aux;
   *i = Esq;
   *j = Dir;
   pivo = reg[(*i + *j) / 2]; //Obtendo o pivo
   do
   {
      (*cont_if)++;
      while (pivo.Chave > reg[*i].Chave)
      {
         // cont_if++;
         (*i)++;
      }
      (*cont_if)++;
      while (pivo.Chave < reg[*j].Chave)
      {
         //   cont_if++;
         (*j)--;
      }
      if (*i <= *j)
      {
         (*cont_move)++;
         aux = reg[*i];
         reg[*i] = reg[*j];
         reg[*j] = aux;
         (*i)++;
         (*j)--;
      }
   } while (*i <= *j);
}

void Refaz(Tregister *reg, int i, int f, double *cont_if, double *cont_move)
{
   Tregister aux = reg[i];
   int j = i * 2 + 1;
   while (j <= f)
   {
      if ((j < f) && (reg[j].Chave < reg[j + 1].Chave))
      {
         (*cont_if)++;
         j++;
      }
      if (j < f)
      {
         (*cont_if)++;
      }
      (*cont_if)++;
      if (aux.Chave < reg[j].Chave)
      {
         (*cont_move)++;
         reg[i] = reg[j];
         i = j;
         j = 2 * i + 1;
      }
      else
      {
         j = f + 1;
      }
   }
   reg[i] = aux;
}
void Heapsort(Tregister *reg, int n, double *cont_if, double *cont_move)
{
   int i;
   Tregister aux;
   for (i = (n - 1) / 2; i >= 0; i--)
   {
      Refaz(reg, i, n - 1, cont_if, cont_move);
   }
   for (i = n - 1; i >= 1; i--)
   {
      (*cont_move)++;
      aux = reg[0];
      reg[0] = reg[i];
      reg[i] = aux;
      Refaz(reg, 0, i - 1, cont_if, cont_move);
   }
}

void Merge(Tregister *v, int p, int q, int r, double *cont_if, double *cont_move)
{
   // A funcao recebe vetores crescentes v[p..q-1]
   // e v[q..r-1] e rearranja v[p..r-1] em ordem
   // crescente.

   Tregister *w;                            //  1
   w = malloc((r - p) * sizeof(Tregister)); //  2
   int i = p, j = q;                        //  3
   int k = 0;                               //  4

   while (i < q && j < r)
   { //  5
      if (v[i].Chave <= v[j].Chave)
         w[k++] = v[i++]; //  6
      else
      {
         w[k++] = v[j++];
         (*cont_move)++;
      } //  7
      (*cont_if)++;
   } //  8
   while (i < q)
      w[k++] = v[i++]; //  9
   while (j < r)
      w[k++] = v[j++]; // 10
   for (i = p; i < r; ++i)
      v[i] = w[i - p]; // 11
   free(w);
}

void Mergesort(Tregister *v, int p, int r, double *cont_if, double *cont_move)
{
   // A funcao mergesort rearranja o vetor
   // v[p..r-1] em ordem crescente.
   if (p < r - 1)
   {                                          // 1
      int q = (p + r) / 2;                    // 2
      Mergesort(v, p, q, cont_if, cont_move); // 3
      Mergesort(v, q, r, cont_if, cont_move); // 4
      Merge(v, p, q, r, cont_if, cont_move);  // 5
   }
}

void Radixsort(Tregister *reg, int n, double *cont_if, double *cont_move)
{ //cont_if do Radix sort eh sempre 0

   int i, exp = 1, m = 0, bucket[n], auxcont;
   Tregister temp[n];
 /*  temp = (Tregister*)malloc((n) * sizeof(Tregister));
   for(int i = 0; i<n; i++){
      temp[i].itens = (Titem*) malloc(10 * sizeof(Titem));
   }*/
   Tverifica_radix v[n];
  /* v = (Tverifica_radix*)malloc((n) * sizeof(Tverifica_radix));*/

   for (i = 0; i < n; i++)
   {
      v[i].Verificado = i;
   }

   for (i = 0; i < n; i++)
   {
      if (reg[i].Chave > m)
      {
         m = reg[i].Chave;
      }
   }
   while ((m / exp) > 0)
   {
      for (i = 0; i < n; i++)
      {
         bucket[i] = 0;
      }
      for (i = 0; i < n; i++)
      {
         bucket[(reg[i].Chave / exp) % 10]++;
      }
      for (i = 1; i < n; i++)
      {
         bucket[i] += bucket[i - 1];
      }
      for (i = (n - 1); i >= 0; i--)
      {
         temp[--bucket[(reg[i].Chave / exp) % 10]] = reg[i];
         v[bucket[(reg[i].Chave / exp) % 10]].Verificador = v[i].Verificado;
      }
      for (i = 0; i < n; i++)
      {
         if (v[i].Verificado != v[i].Verificador)
         {
            (*cont_move)++;
         }
         reg[i] = temp[i];
      }
      exp *= 10;
   }
   auxcont = *cont_move;
   *cont_move = auxcont / 2;
}
void ArquivoTesteRapido(FILE *arquivo, double som_if, double som_move, double som_time, double teste)
{
   fprintf(arquivo, "Media de Movimentacoes:%.2lf\n", som_move / teste);
   fprintf(arquivo, "Media de Comparacoes:%.2lf\n", som_if / teste);
   fprintf(arquivo, "Media de tempo:%.5lf\n", som_time / teste);
   fprintf(arquivo, " \n");
}

void TesteRapidoRegistro(Tregister *reg, int n, double teste)
{
   FILE *arquivo;
   double som_if = 0;
   double som_move = 0;
   double cont_if = 0, cont_move = 0;
   double som_time = 0;
   clock_t begin, end;
   printf("Preenchendo Arquivo de Registro...\n");
   arquivo = fopen("TesteRapido_Registro.txt", "w");
   fprintf(arquivo, "Tamanho do Vetor:%d\n", n);
   fprintf(arquivo, "Medias:%.2lf\n", teste);

   for (int i = 0; i < teste; i++)
   {
      reg = InicializaRegistro(n);
      begin = clock();
      Bubblesort(reg, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(reg);
   }

   fprintf(arquivo, "Bubblesort:\n");
   ArquivoTesteRapido(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      reg = InicializaRegistro(n);
      begin = clock();
      Selectionsort(reg, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(reg);
   }

   fprintf(arquivo, "Selectionsort:\n");
   ArquivoTesteRapido(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      reg = InicializaRegistro(n);
      begin = clock();
      Insertionsort(reg, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(reg);
   }

   fprintf(arquivo, "Insertionsort:\n");
   ArquivoTesteRapido(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      reg = InicializaRegistro(n);
      begin = clock();
      Shellsort(reg, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(reg);
   }

   fprintf(arquivo, "Shellsort:\n");
   ArquivoTesteRapido(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      reg = InicializaRegistro(n);
      begin = clock();
      Quicksort(reg, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(reg);
   }

   fprintf(arquivo, "Quicksort:\n");
   ArquivoTesteRapido(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      reg = InicializaRegistro(n);
      begin = clock();
      Heapsort(reg, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(reg);
   }

   fprintf(arquivo, "Heapsort:\n");
   ArquivoTesteRapido(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      reg = InicializaRegistro(n);
      begin = clock();
      Mergesort(reg, 0, n-1, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(reg);
   }

   fprintf(arquivo, "Mergesort:\n");
   ArquivoTesteRapido(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      reg = InicializaRegistro(n);
      begin = clock();
      Radixsort(reg, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(reg);
   }

   printf("Inseriu no arquivo Registro!");
   fprintf(arquivo, "Radixsort:\n");
   ArquivoTesteRapido(arquivo, som_if, som_move, som_time, teste);
   fclose(arquivo);
}
