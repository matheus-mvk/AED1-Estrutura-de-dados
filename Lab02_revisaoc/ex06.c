#include <stdio.h>

int main() 
{
    int *num;
    int n, par = 0, impar = 0;

    printf("Informe o número de produtos: ");
    scanf("%d", &n);
    num = (int *) malloc(n*sizeof(double));
    for(int i = 0; i < n; i++){
        printf("Digite um inteiro [%d]º: ", i+1);
        scanf("%ld", &num[i]);
    }

    for(int i = 0; i < n; i++){
        printf("%dº Inteiro: %ld\n",i+1 , num[i]);
    }
    for(int i = 0; i < n; i++){
        if(num[i]%2==0){
            par++;
        }else
            impar++;
            
    }
    printf("Sao pares: %d dos %d inteiros lidos\n", par, n);
    printf("Sao impares: %d dos %d inteiros lidos\n", impar, n);
    
    free(num);
    return 0;
}