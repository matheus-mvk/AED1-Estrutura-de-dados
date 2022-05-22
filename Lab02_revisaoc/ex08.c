#include <stdio.h>
#include <stdlib.h>

struct cords {
    int x;
    int y;
};
typedef struct cords cords;

int calc_area(struct cords p1, struct cords p2){
    int auxx = 0, auxy = 0;
    auxx = p1.x - p2.x;
    if(auxx < 0)
        auxx = auxx * -1;
    
    auxy = p1.y - p2.y;
    if(auxy < 0)
        auxy = auxy * -1;
    
    return auxx * auxy;
}
int main() 
{
    cords *ponto;
    int area = 0;
    ponto = (cords *) malloc(2*sizeof(cords));

    for(int i = 0; i < 2; i++){
        printf("Entre com a coordenada X do ponto %d:", i+1);
        scanf("%d", &ponto[i].x);
        printf("Entre com a coordenada Y do ponto %d:", i+1);
        scanf("%d", &ponto[i].y);
    }
    area = calc_area(ponto[0], ponto[1]);
    printf("Area do retangulo definido por (%d,%d) e (%d,%d) eh: %d", ponto[0].x, ponto[0].y, ponto[1].x, ponto[1].y, area);

    free(ponto);
    return 0;
}