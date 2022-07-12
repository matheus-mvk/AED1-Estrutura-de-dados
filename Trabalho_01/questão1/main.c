#include <stdio.h>
#include <stdlib.h>
#include "lista_estat.h"


int main()
{
    int op, elem;
    lista *lst1, *lst2, *lst3;

    
    do{
        
        do{
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Verificar lista cheia\n");
            printf(" 4. Inserir elemento\n");
            printf(" 5. Ordena Lista\n");
            printf(" 6. Excluir elemento\n");
            printf(" 7. Menor elemento\n");
            printf(" 8. Imprimir lista\n");
            printf(" 9. Remove Impares\n");
            printf(" 10. Tamanho\n");
            printf(" 11. Concatena Listas\n");
            printf(" 12. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if((op < 1) || (op > 12)) {

                printf("\n\n Opcao Invalida! Tente       novamente...\n");
                
            }
        } while((op < 1) || (op > 12));

        switch(op)
        {   
            case 1:
                system("clear");
                
                lst1 = criar_lista();
                printf("Lista criada!\n");
                break;

            case 2:
                system("clear");
                if(lista_vazia(lst1) == 1)
                    printf("Lista Vazia!\n");
                else
                    printf("Lista NAO Vazia!\n");
                break;

            case 3:
                system("clear");
                if(lista_cheia(lst1) == 1)
                    printf("Lista Cheia!\n");
                else
                    printf("Lista NAO Cheia\n");
                break;

            case 4:
                system("clear");
                printf("Digite o elemento a ser inserido:");
                scanf("%d",&elem);
                if(insere_elem(lst1, elem) == 1)
                    printf("Elemento Inserido!\n");
                else
                    printf("Elemento NAO Inserido\n");
                break;
            
            case 5:
                system("clear");
                if(ordena_lista(lst1) == 1)
                    printf("Elementos ordenados\n");
                else
                    printf("Erro ao ordenar");
                break;

            case 6:
                system("clear");
                printf("Digite o elemento a ser removido:");
                scanf("%d",&elem);
                
                if(remove_elem(lst1,elem) == 1)
                    printf("Elemento Removido!\n");
                else
                    printf("Elemento NAO Removido\n");
                break;

            case 7:
                system("clear");
                
                
                if(devolve_menor(lst1, &elem) == 1)
                    printf("Menor elemento: %d\n", elem);
                else
                    printf("A lista não contem elementos\n");
                break;
            
            case 8:
                system("clear");
                obtem_valor_elem(lst1);
                break;
            
            case 9:
                system("clear");
                if(remove_impares(lst1) == 1)
                    printf("Elemento Removido!\n");
                else
                    printf("Elemento NAO Removido\n");
                break;
            case 10:
                system("clear");
                if(tamanho(lst1) == 0)
                    printf("Lista não existe!\n");
                else
                    printf("Tamanho: %d\n", tamanho(lst1));
                break;
            case 11:
                system("clear");
                lst3 = concatena(lst1, lst2);
                if(lst3 == NULL)
                    printf("Não foo possivel concatenar\n");
                else
                    printf("Lista concatenada: ");
                    obtem_valor_elem(lst3);
            default:
				break;
        }
    } while(op != 12);
    return 0;
}