#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//cada ponto terá essa carinha
// typedef struct{
//     int x;
//     int y;
//     int numeroPessoas;
// }Point;



// void registraPonto(int x, int y, int pessoas, Point mapa){
    
// }

int main(){
    // Point mapa[1024][1024];



    int distancia, tamanho;
    int x = 0; 
    int y = 0; 
    int pessoas = 0; 
    int mapa[1024][1024] = {0};


    printf("%i", mapa[0][0]);
    printf("Insira a distancia: ");
    scanf("%i", &distancia);
    //verificar se ta com o tamanho certo
    if(distancia< 1 || distancia > 50){exit;}
    printf("Insira o tamanho: ");
    scanf("%i", &tamanho);
    if(tamanho < 1 || tamanho > 25000){exit;}
    for(int i = 0; i<tamanho; i++){
        scanf("%i", &x);
        scanf("%i", &y);
        scanf("%i", &pessoas);
        if(pessoas >= 1 && pessoas <= 255){
            //registraPonto(x, y, pessoas, mapa);
            mapa[x][y] = pessoas;
        }
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            printf("%d ", mapa[i][j]);
        }
        printf("\n");
    }
}