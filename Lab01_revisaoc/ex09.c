#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[10];
    printf("Digite um nome: ");
    for(int i = 0; i < 10 || nome[i] != '\0'; i++){
        scanf("%[^\n]", &nome[i]);
    }
    for(int i = 0; i < 10 || nome[i] != '\0'; i++){
         printf("%c", nome[i]-32);
    }
   
    return 0;
}