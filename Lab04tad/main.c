#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() 
{
    int x,y;
    p *pto1, *pto2, *pto3;
    printf("Digite o ponto X:");
    scanf("%d",&x);
    printf("Digite o ponto Y:");
    scanf("%d",&y);

    pto1 = gera_pto();
    pto2 = gera_pto();
    pto3 = gera_pto();
    
    set_pto(&pto1, x, y);

    
    printf("Digite o segundo ponto X:");
    scanf("%d",&x);
    printf("Digite o segundo ponto Y:");
    scanf("%d",&y);

    

    
    set_pto(&pto2, x, y);

    distancia_pto(&pto1,&pto2, &pto3);

    get_ponto(&pto3, &x, &y);
    printf("Distancia entre os pontos: [%d,%d]", x,y);

    free(pto1);
    free(pto2);
    free(pto3);
    
    return 0;
}