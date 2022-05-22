#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct coordenadas{
    int x;
    int y;
};
typedef struct coordenadas Cords;
int main() 
{
    Cords *cords;
    int n;

    printf("Quantos pontos deseja digitar: ");
    scanf("%d", &n);
    
    cords = (Cords *) malloc(n * sizeof(Cords));
    
    for(int i = 0; i < n; i++){
        printf("Entre com a coordenada X do ponto %d:", i+1);
        scanf("%d", &cords[i].x);
        printf("Entre com a coordenada Y do ponto %d:", i+1);
        scanf("%d", &cords[i].y);
    }
    printf("Pontos digitados: ");
    for(int i = 0; i < n; i++){
        printf("(%d,%d)", cords[i].x, cords[i].y);
    }
    free(cords);
    return 0;
}