#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int bin[4];
    int dec = 0;
    
    for(int i = 0; i<4; i++){
        printf("Digite o %do. bit: ", i+1);
        scanf("%d", &bin[i]);
    }
    for(int i = 3; i>-1; i--){
        if(bin[i] ==  1 || bin[i] == 0){
            dec = dec + (pow(2, i) *bin[i]);
            //erro n localizado
        }
    }
    printf("\nO numero binario ");
    for(int i = 0; i<4; i++){
        printf("%d",bin[i]);
    }
    printf(" corresponde ao numero decimal %d", dec);
    return 0;
}