#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int *num;
    int n;

    printf("Informe o número de produtos: ");
    scanf("%d", &n);
    num = (int *) malloc(n*sizeof(double));
    for(int i = 0; i < n; i++){
        printf("Digite um numero no espaço [%d] alocado: ", i+1);
        scanf("%ld", &num[i]);
    }

    for(int i = 0; i < n; i++){
        printf("Numeros: %ld\n", num[i]);
    }
    return 0;
}