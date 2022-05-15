#include <stdio.h>

int main() {
    float aposta1, aposta2, aposta3, premio;
    
    printf("Bolao jogador 1: \n");
    scanf("%f", &aposta1);
    printf("Bolao jogador 2: \n");
    scanf("%f", &aposta2);
    printf("Bolao jogador 3: \n");
    scanf("%f", &aposta3);
      
    printf("Informe o valor do premio: \n");
    scanf("%f", &premio);

    printf("Jogador 1 receberá: %.2f\n", (aposta1/10)*premio);
    printf("Jogador 2 receberá: %.2f\n", (aposta2/10)*premio);
    printf("Jogador 3 receberá: %.2f\n", (aposta3/10)*premio);
    
  return 0;
}