#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main()
{
    int op, elem;
    lista *lst;

    
    do{
        
        do{
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Verificar lista cheia\n");
            printf(" 4. Inserir elemento\n");
            printf(" 5. Inserir elemento ordenado\n");
            printf(" 6. Excluir elemento\n");
            printf(" 7. Excluir elemento ordenado\n");
            printf(" 8. Imprimir lista\n");
            printf(" 9. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 9)) {

                printf("\n\n Opcao Invalida! Tente novamente...\n");
                
            }
        } while((op < 1) || (op > 9));

        switch(op)
        {   
            case 1:
                system("clear");
                lst = criar_lista();
                printf("Lista criada!\n");
                break;

            case 2:
                system("clear");
                if(lista_vazia(lst) == 1)
                    printf("Lista Vazia!\n");
                else
                    printf("Lista NAO Vazia!\n");
                break;

            case 3:
                system("clear");
                if(lista_cheia(lst) == 1)
                    printf("Lista Cheia!\n");
                else
                    printf("Lista NAO Cheia\n");
                break;

            case 4:
                system("clear");
                printf("Digite o elemento a ser inserido:");
                scanf("%d",&elem);
                if(insere_elem(lst, elem) == 1)
                    printf("Elemento Inserido!\n");
                else
                    printf("Elemento NAO Inserido\n");
                break;
            
            case 5:
                system("clear");
                break;

            case 6:
                system("clear");
                printf("Digite o elemento a ser removido:");
                scanf("%d",&elem);
                
                if(remove_elem(lst,elem) == 1)
                    printf("Elemento Removido!\n");
                else
                    printf("Elemento NAO Removido\n");
                break;

            case 7:
                system("clear");
                break;
            
            case 8:
                system("clear");
                obtem_valor_elem(lst);
                break;
            
            default:
				break;
        }
    } while(op != 9);

    return 0;
}