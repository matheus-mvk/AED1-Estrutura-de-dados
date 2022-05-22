#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int a = 40;

    int *p;

    p = &a;

    printf("Endereço de A: %d\n", &a);
    printf("Endereço de A por P: %d\n", p);

    printf("Altere valor de A: ");
    scanf("%d", p);

    printf("Valor novo de A: %d\n", a);
    return 0;
}