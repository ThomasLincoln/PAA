#include <math.h>
#include <stdio.h>
#include <stdlib.h>

      int size = 0;
      
      struct ponto{
        double valor;
        int indice;
      }ponto;
      
      int quem_e_o_pai(int i){
        return (i - 1) / 2;
      }
      
      void heapify(struct ponto array[], int i)
      {
        if (size == 1)
        {
          printf("Single element in the heap");
        }
        else
        {
          int menor = i;
          int l = 2 * i + 1;
          int r = 2 * i + 2;
          if (l < size && array[l].valor < array[menor].valor)
            menor = l;
          if (r < size && array[r].valor < array[menor].valor)
            menor = r;
          if (menor != i)
          {
            struct ponto temp = array[i];
            array[i] = array[menor];
            array[menor] = temp;
            heapify(array, menor);
          }
        }
      }
      void insert(struct ponto array[], struct ponto novo)
      {
        size++;
        array[size-1] = novo;
        int atual = size - 1;
        struct ponto aux;
        struct ponto temp;

        while(atual > 0 && array[quem_e_o_pai(atual)].valor > array[atual].valor){
          
          temp = array[quem_e_o_pai(atual)];
          array[quem_e_o_pai(atual)] = array[atual];
          array[atual] = temp;
      
          atual = quem_e_o_pai(atual);
        }
      
      }
      void deleteRoot(struct ponto array[])
      {
      
        struct ponto ultimo_elemento = array[size -1];
      
        array[0] = ultimo_elemento;
        size--;
      
        heapify(array, 0);
      }
      void printArray(struct ponto array[], int size)
      {
        for (int i = 0; i < size; ++i)
          printf("%0.f ", array[i].valor);
        printf("\n");
      }
      
      double somador(struct ponto array[], int size)
      {
        double soma = 0;
        int aux;
        for (int i = 0; i < size; ++i){
          aux = (array[i].valor);
          soma += aux;
        }
          // printf("%d ", array[i].valor);
        // printf("\n");
        return soma;
      }
      
      int main()
      {
        int k, in, aux;
        struct ponto ponto_aux;
        double b;
      
        // printf("insira o k: ");
        scanf("%i", &k);
        // printf("insira o i: ");
        scanf("%i", &in);
        int tamanho[k];
        int array_primeiro[k];
        struct ponto array_heap[k];
      
        int **mat;
        mat = malloc(k * sizeof(int *));
      
          for (int l = 0; l < k; l++) {
      
          scanf("%d", &tamanho[l]);
          mat[l] = malloc(tamanho[l] * sizeof(double));
          array_primeiro[l] = 0;
      
          for (int j = 0; j < tamanho[l]; j++) {
            scanf("%d", &aux);
            b = ((double)l/10000);
            b += aux;
            mat[l][j] = b;
            if(j == 0  && tamanho[l] > 0){
              ponto_aux.valor = b;
              ponto_aux.indice = l;
              insert(array_heap, ponto_aux);
            }
          }
        }
      
      
          for(int i = 1; i < in; i++){
            int indice_menor = array_heap[0].indice;
            deleteRoot(array_heap);

            array_primeiro[indice_menor]++;
      
            if(mat[indice_menor][array_primeiro[indice_menor]]!= 0){
              ponto_aux.valor = mat[indice_menor][array_primeiro[indice_menor]];
              ponto_aux.indice = indice_menor;
              insert(array_heap, ponto_aux);
            }
      
          }
      
        // printf("Max-Heap array: ");
        // printArray(array_heap, size);
      
      
        double resultado = somador(array_heap, size);
        printf("%.0f", resultado);
      
        // printArray(array_heap, size);
      }