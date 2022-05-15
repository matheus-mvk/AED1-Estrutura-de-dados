#include <stdio.h>
#include <math.h>

int main() {
    int x,y;
    float dist;
    printf("Digite a cooerdenada x:\n");
    scanf("%d", &x);
    printf("Digite a cooerdenada y:\n");
    scanf("%d", &y);

    dist = sqrt(pow(0-x,2)+pow(0-y,2));
    printf("A distancia e: %.2f", dist);
    return 0;
}