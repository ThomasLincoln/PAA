#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void print_Aux(int array[], int N, int vet[]) {
  int confirma = 1;
    for(int i = 0; i< N; i++){
      if(vet[i] != 0 && vet[i] != array[i]+1){
        // printf("\n\o %i e igual ao %i\n\n",vet[i], array[i]+1);
        confirma = 0; 
        break;
      }
    }
  if(confirma == 1){
    for (int i = 0; i < N; i++) {
      printf("%i ", array[i]+1);
    }
    printf("\n");
  }
}


void print_Aux2(int array[], int N) {
  int verifica = 1;

  if (verifica == 1) {
    for (int i = 0; i < N; i++) {
      printf("%i ", array[i]);
    }
    printf("\n");
  }
}

void construir_candidatos(int parcial[], int inicio, int candidatos[], int * n_candidatos, int N, int vet[]){
  int in_perm[N];
  memset(in_perm, 0, sizeof in_perm);
  *n_candidatos = 0;

  for(int i = 0; i< inicio; ++i){
    in_perm[parcial[i]] = 1;
  }

  for(int i = 0; i< N; ++i){ 
    if(in_perm[i] != 1){
      candidatos[*n_candidatos] = i;
      * n_candidatos +=1;
    }
  }
}

void backtracking(int parcial[], int inicio, int N, int vet[]){
  if (inicio == N){
    //imprimir
    print_Aux(parcial, N, vet);
  }else{
    //senão construir candidatos
    int n_candidatos;
    int candidatos[N]; 
    construir_candidatos(parcial, inicio, candidatos, &n_candidatos, N,vet);
    for(int i = 0; i < n_candidatos; ++i){
      parcial[inicio] = candidatos[i];
      backtracking(parcial, inicio + 1, N, vet);
    }
    
  }
}


int main() {
  int N, M, x_aux, y_aux;
  int vet[3] = {2,0,0};
  // tamanho da matriz
  // printf("Insira o N: ");
  scanf("%i %i", &N, &M);
  int vetor[N];

  int candidatos[N];
  for (int i = 0; i < N; i++) {
    candidatos[i] = 0;
  }

  for (int i = 0; i < M; i++) {
    scanf("%i %i", &x_aux, &y_aux);
    candidatos[y_aux -1] = x_aux;
  }
  // print_Aux2(candidatos, N);
  // printf("\n\n");
  backtracking(vetor, 0, N, candidatos);
  // 
  
}

/*
5 3
1 1
2 2
3 4

1 2 4 3 5
1 2 5 3 4

*/