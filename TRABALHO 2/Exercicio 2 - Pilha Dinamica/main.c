#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int main(){
    Pilha p;
    int ativo = 0;
    int i;
    int elem;
    int top;
    char vet;
    
    while(ativo != 10){
        printf("\n----------------Menu---------------\n");
        printf("\nDigite [1] para criar a pilha\n");
        printf("Digite [2] para empilhar um elemento na pilha\n");
        printf("Digite [3] para desempilhar um elemento da pilha \n");
        printf("Digite [4] para imprimir a pilha\n");
        printf("Digite [5] para ler elemento do topo da pilha\n");
        printf("Digite [6] para verificar se uma string de entrada é uma palíndromo\n");
        printf("Digite [7] para liberar a pilha\n");
        printf("Digite [8] para imprimir a pilha por impares e pares separadamente\n");
        printf("Digite [9] para eliminar um elemento da pilha\n");
        printf("Digite [10] para sair\n");
    
        printf(" Opcao: ");
        scanf("%d", &i);
        setbuf(stdin, NULL);

    switch(i){
        case 1:
            p = cria_pilha();
            printf("Pilha criada!\n");
        break;
            
        case 2:
            scanf("%d", &elem);
            if(push(&p, elem) == 1);
                printf("Elemento empilhado!\n");
            if(p == NULL)
                printf("Erro ao empilhar elemento\n");
            break;
            

        case 3:
            if(pop(&p, &elem) == 1);
                printf("Elemento desempilhado!\n");
            break;

        case 4:
                printf("\n--------------------------\n");
                imprime_pilha(p);
                printf("\n--------------------------\n");
        break;

        case 5:
            if(le_topo(&p, &elem) == 1);
            printf("O topo da pilha eh: %d", elem);
            printf("\n");
        break;

        case 6:
            if(eh_palindromo(&vet) == 1)
                printf("A string de entrada eh palindromo\n");
            else
                printf("A string de entrada NAO eh palindromo\n");
        break;

        case 7:
            libera_pilha(&p);
        break;

        case 8:
            pares_impares(p);
        break;
        
        case 9:
            scanf("%d", &elem);
            if(elimina(&p, elem) == 1)
                printf("Elemento desejado removido!");
            else
                printf("Erro ao remover elemento!");
        break;
            
        case 10:
            ativo = 10;
        break;

        default:
            printf("Opcao invalida, digite uma opcao de 1 a 11\n");
    }
    }


    return 0;
}