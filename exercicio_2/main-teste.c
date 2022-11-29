#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int k, in, aux, i, j;
  int menor = 0;
  int ponto = 0;
  int aux2 = 0;
  int soma = 0;

  // printf("insira o k: ");
  scanf("%i", &k);
  // printf("insira o i: ");
  scanf("%i", &in);
  int tamanho[k];
  int **mat;
  mat = malloc(k * sizeof(int *));
  int array_primeiro[k];

  for (int l = 0; l < k; l++) {
    scanf("%d", &tamanho[l]);
    mat[l] = malloc(tamanho[l] * sizeof(int));
    array_primeiro[l] = 0;
    for (int j = 0; j < tamanho[l]; j++) {
      scanf("%i", &aux);
      mat[l][j] = aux;
    }
  }
  for (int iterator = 0; iterator < in; iterator++) {
    menor = aux2 = ponto = 0;
    soma = 0;
    // printf("iteracao numero %i\n", iterator);
    for (j = 0; j < k; j++) {
      if (tamanho[j] == 0) {
        continue;
      }
      // pula arrays vazio
      if (array_primeiro[j] == tamanho[j]) {
        continue;
      }
      // printf("\n\nacessando o %i\n\n", mat[j][array_primeiro[j]]);
      // da o primeiro valor pro menor

      soma = soma + mat[j][array_primeiro[j]];
      if (menor == 0) {
        menor = mat[j][array_primeiro[j]];
        ponto = j;
        continue;
      }
      if (mat[j][array_primeiro[j]] < menor) {
        menor = mat[j][array_primeiro[j]];
        ponto = j;
        continue;
      }
    }

    array_primeiro[ponto]++;
    // printf("printar array\n");
    // for (int opa = 0; opa < k; opa++) {
    //   printf("%i ", array_primeiro[opa]);
    // }
  }
  printf("%i", soma);
}
  // inorder traversal of the tree
