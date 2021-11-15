#include "Arraysort.h"
#include "Recordsort.h"
#include <time.h>

int *InicializaArray(int n)
{
   int *Array = (int *)malloc(n * sizeof(int));
   for (int i = 0; i < n; i++)
   {
      Array[i] = rand() % n;
   }
   return Array;
}
void imprimeAleatorio(int *Array, int n)
{
   printf("[");
   for (int i = 0; i < n; i++)
   {
      printf("%d ", Array[i]);
   }
   printf("]");
}

void imprimeArray(int *Array, int n, double *move, double *cont_if, double *time_spend)
{
   printf("Vetor ordenado => ");
   printf("[");
   for (int i = 0; i < n; i++)
   {
      printf("%d ", Array[i]);
   }
   printf("]");
   printf("\n");
   printf("Vetor ordenado! \n");

   printf("\n");
   printf("Tempo de execucao => %.5lf\n", *time_spend);
   printf("Quantidade de movimentacoes => %.2lf\n", *move);
   printf("Quantidade de comparacoes => %.2lf\n", *cont_if);
   printf("\n");

   *time_spend = 0;
   *move = 0;
   *cont_if = 0;
}

void Bubblesort_A(int *Array, int n, double *cont_if, double *cont_move)
{
   int i, j;
   int aux;
   for (i = 0; i < n - 1; i++)
   {
      for (j = 1; j < n - i; j++)
      {
         (*cont_if)++;
         if (Array[j] < Array[j - 1])
         {
            (*cont_move)++;
            aux = Array[j];
            Array[j] = Array[j - 1];
            Array[j - 1] = aux;
         }
      }
   }
}

void Selectionsort_A(int *Array, int n, double *cont_if, double *cont_move)
{
   int i, j, min;
   int aux;
   for (i = 0; i < n - 1; i++)
   {
      min = i;
      for (j = i + 1; j < n; j++)
      {
         (*cont_if)++;
         if (Array[j] < Array[min])
         {
            min = j;
         }
      }
      if (i != min)
      {
         (*cont_move)++;
         aux = Array[i];
         Array[i] = Array[min];
         Array[min] = aux;
      }
   }
}

void Insertionsort_A(int *Array, int n, double *cont_if, double *cont_move)
{
   int i, j;
   int aux;
   for (i = 0; i < n; i++)
   {
      aux = Array[i];
      (*cont_if)++;
      for (j = i; (j > 0) && (aux < Array[j - 1]); j--)
      {
         Array[j] = Array[j - 1];
         (*cont_move)++;
      }
      if (j > 0)
      {
         (*cont_if)++;
      }
      Array[j] = aux;
   }
}

void Shellsort_A(int *Array, int n, double *cont_if, double *cont_move)
{
   int i, j;
   int h = 1;
   int aux;
   do
      h = h * 3 + 1;
   while (h < n);
   do
   {
      h = h / 3;
      for (i = h; i < n; i++)
      {
         aux = Array[i];
         j = i;
         (*cont_if)++;
         while (Array[j - h] > aux)
         {
            (*cont_if)++;
            Array[j] = Array[j - h];
            j -= h;
            (*cont_move)++;
            if (j < h)
               break;
         }
         Array[j] = aux;
      }
   } while (h != 1);
}

void Ordena_A(int Esq, int Dir, int *Array, double *cont_if, double *cont_move)
{
   int i, j;
   Particao_A(Esq, Dir, &i, &j, Array, cont_if, cont_move);
   if (Esq < j)
   {
      Ordena_A(Esq, j, Array, cont_if, cont_move);
   }
   if (i < Dir)
   {
      Ordena_A(i, Dir, Array, cont_if, cont_move);
   }
}
void Quicksort_A(int *Array, int n, double *cont_if, double *cont_move)
{
   Ordena_A(0, n - 1, Array, cont_if, cont_move);
}
void Particao_A(int Esq, int Dir, int *i, int *j, int *Array, double *cont_if, double *cont_move)
{
   int pivo, aux;
   *i = Esq;
   *j = Dir;
   pivo = Array[(*i + *j) / 2]; //Obtendo o pivo
   do
   {
      (*cont_if)++;
      while (pivo > Array[*i])
      {
         (*cont_if)++;
         (*i)++;
      }
      (*cont_if)++;
      while (pivo < Array[*j])
      {
         // cont_if++;
         (*j)--;
      }
      if (*i <= *j)
      {
         (*cont_move)++;
         aux = Array[*i];
         Array[*i] = Array[*j];
         Array[*j] = aux;
         (*i)++;
         (*j)--;
      }
   } while (*i <= *j);
}

void Refaz_A(int *Array, int i, int f, double *cont_if, double *cont_move)
{
   int aux = Array[i];
   int j = i * 2 + 1;
   while (j <= f)
   {
      if ((j < f) && (Array[j] < Array[j + 1]))
      {
         (*cont_if)++;
         j++;
      }
      if (j < f)
      {
         (*cont_if)++;
      }
      (*cont_if)++;
      if (aux < Array[j])
      {
         (*cont_move)++;
         Array[i] = Array[j];
         i = j;
         j = 2 * i + 1;
      }
      else
      {
         j = f + 1;
      }
   }
   Array[i] = aux;
}
void Heapsort_A(int *Array, int n, double *cont_if, double *cont_move)
{
   int i, aux;
   int n2 = (n - 1) / 2;
   for (i = n2; i >= 0; i--)
   {
      Refaz_A(Array, i, n - 1, cont_if, cont_move);
   }
   for (i = n - 1; i >= 1; i--)
   {
      (*cont_move)++;
      aux = Array[0];
      Array[0] = Array[i];
      Array[i] = aux;
      Refaz_A(Array, 0, i - 1, cont_if, cont_move);
   }
}

void Merge_A(int *Array, int inicio, int meio, int fim, double *cont_if, double *cont_move)
{
   int *temp, p1, p2, tamanho, i, j, k;
   int fim1 = 0, fim2 = 0;
   tamanho = fim - inicio + 1;
   p1 = inicio;
   p2 = meio + 1;
   temp = (int *)malloc(tamanho * sizeof(int));
   if (temp != NULL)
   {
      for (i = 0; i < tamanho; i++)
      {
         if (!fim1 && !fim2)
         {
            if (Array[p1] < Array[p2])
            {
               temp[i] = Array[p1++];
            }
            else
            {
               temp[i] = Array[p2++];
               (*cont_move)++;
            }
            (*cont_if)++;
            if (p1 > meio)
            {
               fim1 = 1;
            }
            if (p2 > fim)
            {
               fim2 = 1;
            }
         }
         else
         {
            if (!fim1)
            {
               temp[i] = Array[p1++];
            }
            else
            {
               temp[i] = Array[p2++];
            }
         }
      }
      for (j = 0, k = inicio; j < tamanho; j++, k++)
      {
         Array[k] = temp[j];
      }
      free(temp);
   }
}
void Mergesort_A(int *Array, int inicio, int fim, double *cont_if, double *cont_move)
{
   int meio;
   if (inicio < fim)
   {
      meio = floor((inicio + fim) / 2);
      Mergesort_A(Array, inicio, meio, cont_if, cont_move);
      Mergesort_A(Array, meio + 1, fim, cont_if, cont_move);
      Merge_A(Array, inicio, meio, fim, cont_if, cont_move);
   }
}

void Radixsort_A(int *Array, int n, double *cont_if, double *cont_move)
{ //cont_if do Radix sort eh sempre 0

   int i, exp = 1, m = 0, bucket[n], temp[n], auxcont;
   Tverifica_radix *v;
   v = (Tverifica_radix *) malloc((n) * sizeof(Tverifica_radix));

   for (i = 0; i < n; i++)
   {
      v[i].Verificado = i;
   }

   for (i = 0; i < n; i++)
   {
      if (Array[i] > m)
      {
         m = Array[i];
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
         bucket[(Array[i] / exp) % 10]++;
      }
      for (i = 1; i < n; i++)
      {
         bucket[i] += bucket[i - 1];
      }
      for (i = (n - 1); i >= 0; i--)
      {
         temp[--bucket[(Array[i] / exp) % 10]] = Array[i];
         v[bucket[(Array[i] / exp) % 10]].Verificador = v[i].Verificado;
      }
      for (i = 0; i < n; i++)
      {
         if (v[i].Verificado != v[i].Verificador)
         {
            (*cont_move)++;
         }
         Array[i] = temp[i];
      }
      exp *= 10;
   }
   auxcont = *cont_move;
   *cont_move = auxcont / 2;
}

void tacanoarquivo(FILE *arquivo, double som_if, double som_move, double som_time, double teste)
{
   fprintf(arquivo, "Media de Movimentacoes:%.2lf\n", som_move / teste);
   fprintf(arquivo, "Media de Comparacoes:%.2lf\n", som_if / teste);
   fprintf(arquivo, "Media de tempo:%.5lf\n", som_time / teste);
   fprintf(arquivo, " \n");
}

void TesteRapidoArray(int *Array, int n, double teste)
{
   FILE *arquivo;
   double som_if = 0;
   double som_move = 0;
   double cont_if = 0, cont_move = 0;
   double som_time = 0;
   clock_t end, begin;
   printf("Preenchendo Arquivo do Array...\n");
   arquivo = fopen("TesteRapido_Array.txt", "w");
   fprintf(arquivo, "Tamanho do Vetor:%d\n", n);
   fprintf(arquivo, "Medias:%.2lf\n", teste);

   for (int i = 0; i < teste; i++)
   {
      Array = InicializaArray(n);
      begin = clock();
      Bubblesort_A(Array, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(Array);
   }

   fprintf(arquivo, "Bubblesort:\n");
   tacanoarquivo(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      Array = InicializaArray(n);
      begin = clock();
      Selectionsort_A(Array, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(Array);
   }

   fprintf(arquivo, "Selectionsort:\n");
   tacanoarquivo(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      Array = InicializaArray(n);
      begin = clock();
      Insertionsort_A(Array, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(Array);
   }

   fprintf(arquivo, "Insertionsort:\n");
   tacanoarquivo(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      Array = InicializaArray(n);
      begin = clock();
      Shellsort_A(Array, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(Array);
   }

   fprintf(arquivo, "Shellsort:\n");
   tacanoarquivo(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      Array = InicializaArray(n);
      begin = clock();
      Quicksort_A(Array, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(Array);
   }

   fprintf(arquivo, "Quicksort:\n");
   tacanoarquivo(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      Array = InicializaArray(n);
      begin = clock();
      Heapsort_A(Array, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(Array);
   }

   fprintf(arquivo, "Heapsort:\n");
   tacanoarquivo(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      Array = InicializaArray(n);
      begin = clock();
      Mergesort_A(Array, 0, n - 1, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(Array);
   }

   fprintf(arquivo, "Mergesort:\n");
   tacanoarquivo(arquivo, som_if, som_move, som_time, teste);
   som_if = 0;
   som_if = 0;
   som_time = 0;

   for (int i = 0; i < teste; i++)
   {
      Array = InicializaArray(n);
      begin = clock();
      Radixsort_A(Array, n, &cont_if, &cont_move);
      end = clock();
      double time_spent = (double)(end - begin) / ((CLOCKS_PER_SEC));
      som_if = som_if + cont_if;
      som_move = som_move + cont_move;
      som_time = som_time + time_spent;
      cont_if = 0;
      cont_move = 0;
      time_spent = 0;
      free(Array);
   }

   printf("Inseriu no arquivo Array!\n");

   fprintf(arquivo, "Radixsort:\n");
   tacanoarquivo(arquivo, som_if, som_move, som_time, teste);
   fclose(arquivo);
}
