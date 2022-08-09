#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(){
    int op=0,continua;
    char elem[tam];
    Deque deque1;

    while(1){
        if(op==8)
            break;
        printf("\n---------------Menu---------------\n");
        printf("\n     O que deseja fazer?\n");
        printf("[1]: Criar um deque;\n");
        printf("[2]: Encerrar o programa.\n");
        scanf("%d",&op);
        if(op==2)
            break;

        if(op==1){
            deque1=cria_deque();
            if(deque1==NULL)
                printf("\nNao foi possivel criar o deque.");
            else{
                printf("\nO deque foi criada!");
                continua=1;
            }
        }
        else
            printf("Insira 1 ou 2 para as operações.");

        while (1){
            printf("\n---------------Menu---------------\n");
            printf("\n     O que deseja fazer?\n");
            printf("[1]: Inserir um elemento no inicio;\n");
            printf("[2]: Inserir um elemento no final;\n");
            printf("[3]: Remover um elemento no inicio;\n");
            printf("[4]: Remover um elemento no fim;\n");
            printf("[5]: Mostrar o deque;\n");
            printf("[6]: Excluir o deque;\n");
            printf("[7]: Apagar o deque;\n");
            printf("[8]: Encerrar o programa.\n");
            printf("\tInsira a operacao: ");
            scanf("%d",&op);
            printf("\n----------------------------------\n");
            if(op==8)
                break;
            switch(op){
                case 1:
                    printf("\nInsira o elemento que deseja inserir no inicio: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]%*c",elem);
                    if(insere_ini(deque1,elem))
                        printf("\nO elemento foi inserido com sucesso!");
                    else
                        printf("\nNao foi possivel inserir o elemento.");
                    break;
                case 2:
                    printf("\nInsira o elemento que deseja inserir no fim: ");
                    setbuf(stdin, NULL);
                    scanf("%[^\n]%*c",elem);
                    if(insere_fim(deque1,elem))
                        printf("\nO elemento foi inserido com sucesso!");
                    else
                        printf("\nNao foi possivel inserir o elemento.");
                    break;
                case 3:
                    if(remove_ini(deque1,elem))
                        printf("\nO elemento (%s) foi removido do inicio do deque!",elem);
                    else
                        printf("\nNao foi possivel remover o elemento.");
                    break;
                case 4:
                    if(remove_fim(deque1,elem))
                        printf("\nO elemento (%s) foi removido do fim do deque!",elem);
                    else
                        printf("\nNao foi possivel remover o elemento.");
                    break;
                case 5:
                    mostra_deque(deque1);
                    break;
                case 6:
                    exclui_deque(&deque1);
                    if(deque1==NULL){
                        printf("\nO deque foi excluido com sucesso!");
                        continua=0;
                    }
                    else
                        printf("\nO deque nao foi excluido.");
                    break;
                case 7:
                    deque1=apaga_deque(&deque1);
                    if(deque1!=NULL)
                        printf("\nO deque foi apagado e criado novamente!");
                    else
                        printf("\nNao foi possivel apagar O deque e cria-lo novamente.");
                    break;
                default:
                    fprintf(stderr,"\n\t\t\t Insira os numeros de 1 a 8 para as operacoes.\n");
                    break;
            }
            if(continua==0)
                break;
        }
    }

    printf("\nObrigado!\n");

    return 1;
}
