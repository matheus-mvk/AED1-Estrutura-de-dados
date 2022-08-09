#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    Fila f;
    int ativo = 0;
    int i;
    int elem;

    while (ativo != 6){
        printf("\n----------------Menu---------------\n");
        printf("\nDigite [1] para criar a fila\n");
        printf("Digite [2] para inserir um elemento na fila\n");
        printf("Digite [3] para remover um elemento da fila\n");
        printf("Digite [4] para imprimir a fila\n");
        printf("Digite [5] para ler o final da fila\n");
        printf("Digite [6] para sair\n");

        printf(" Opcao: ");
        scanf("%d", &i);
        setbuf(stdin, NULL);

        switch(i){
            case 1:
                f = cria_fila();
                printf("Fila criada!\n");
            break;

            case 2:
                scanf("%d", &elem);
                insere_fim(f, elem);
                printf("Elemento inserido!\n");
                if(f == NULL)
                printf("Erro ao inserir elemento\n");
            break;

            case 3:
                remove_ini(f, &elem);
                printf("Elemento removido!\n");
                if(f == NULL)
                printf("Erro ao remover elemento\n");
            break;

        case 4:
                printf("\n--------------------------\n");
                imprime_fila(f);
                printf("\n--------------------------\n");
        break;

        case 5:
            le_final(f, elem);
            printf("O ultimo elemento da fila eh: %d", elem);
            printf("\n");
        break;

        case 6:
            ativo = 6;
        break;

        default:
            printf("Opcao invalida, digite uma opcao de 1 a 6\n");
        }
    }

    return 0;
}