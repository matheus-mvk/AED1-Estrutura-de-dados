#include <stdio.h>
#include <math.h>

int main() {
    int vet[5];
    float media = 0;
    double desvio = 0;

    for(int i = 0; i < 5; i++){
        printf("Digite o valor %d: \n", i+1);
        scanf("%d", &vet[i]);
    }
    for(int i = 0; i < 5; i++){
        media = media + vet[i];
    }
    media = media/5;
    for(int i = 0; i < 5; i++){
        desvio = desvio + pow(vet[i] - media,2);
        
    }
    desvio = sqrt(desvio/4);
    printf("%f\n",desvio);
    printf("A media e %.1f e o desvio padrao e %f", media, desvio);
    return 0;
}