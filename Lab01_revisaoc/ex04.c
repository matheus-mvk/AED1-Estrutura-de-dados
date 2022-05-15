#include <stdio.h>

int main() {
    float massa, altura, imc;
    printf("Digite seu peso: \n");
    scanf("%f", &massa);
    printf("Digite sua altura: \n");
    scanf("%f", &altura);

    imc = massa/(altura*altura);
    printf("Classificação do IMC: \n");
    if(imc < 18.5)
        printf("Magreza!\n");
    else if (imc < 24.9)
        printf("Saudavel!\n");
    else if (imc < 29.9)
        printf("Sobrepeso!\n");
    else if (imc < 34.9)
        printf("Obesidaede Grau I!\n");
    else if (imc < 39.9)
        printf("Obesidade Grau II!\n");
    else
        printf("Obesidade Grau III!\n");
    return 0;
}