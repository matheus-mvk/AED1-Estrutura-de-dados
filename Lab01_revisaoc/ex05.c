#include <stdio.h>

int main() {
    int n, cont = 0;
    printf("Digite um inteiro positivo: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= i; j++){
            cont++;
            printf("%d ",cont);
        }
        printf("\n");
    }
    return 0;
}