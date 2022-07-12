#include <stdio.h>
#include <stdlib.h>
#include "lista_ord_din.h"


int main()
{
    int op, op2, elem;
    Lista lst1, lst2;

    
    do{
        do{
            system("clear");
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Verificar se as listas são iguais\n");
            printf(" 4. Tamanho da lista\n");
            printf(" 5. Inserir elemento ordenado\n");
            printf(" 6. Media aritimetica simples\n");
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
                do{
                    do{
                        printf("Qual lista deseja criar:\n");
                        printf("1. Lista 1\n");
                        printf("2. Lista 2\n");
                        printf("3. Lista 3\n");
                        printf("4. Cancelar\n");
                        printf("Opcao:");
                        scanf("%d", &op2);
                        if((op2 < 1) || (op2 > 4)) {
                            printf("\n\n Opcao Invalida! Tente novamente...\n");
                        }
                    }while((op2 < 1) || (op2 > 4));
                        switch(op2){
                            case 1:
                                system("clear");
                                lst1 = criar_lista();
                                printf("Lista 1 criada!\n");
                                break;
                            case 2:
                                system("clear");
                                lst2 = criar_lista();
                                printf("Lista 2 criada!\n");
                                break;
                            case 3:
                                system("clear");
                                break;
                            default:
                                break;
                        }
                }while(op2 != 4);
                break;

            case 2:
                system("clear");
                do{
                    do{
                        printf("Qual lista deseja verificar:\n");
                        printf("1. Lista 1\n");
                        printf("2. Lista 2\n");
                        printf("3. Lista 3\n");
                        printf("4. Cancelar\n");
                        printf("Opcao:");
                        scanf("%d", &op2);
                        if((op2 < 1) || (op2 > 4)) {
                            printf("\n\n Opcao Invalida! Tente novamente...\n");
                        }
                    }while((op2 < 1) || (op2 > 4));
                        switch(op2){
                            case 1:
                                system("clear");
                                if(lista_vazia(lst1) == 1)
                                    printf("Lista Vazia!\n");
                                else
                                    printf("Lista NAO Vazia!\n");
                                break;
                            case 2:
                                system("clear");
                                if(lista_vazia(lst2) == 1)
                                    printf("Lista Vazia!\n");
                                else
                                    printf("Lista NAO Vazia!\n");
                                break;
                            case 3:
                                system("clear");
                                break;
                            default:
                                break;
                        }
                }while(op2 != 4);
                
                break;

            case 3:
                system("clear");
                do{
                    do{
                        printf("Qual lista deseja verificar:\n");
                        printf("1. Lista 1 e Lista 2\n");
                        printf("2. -----------------\n");
                        printf("3. -----------------\n");
                        printf("4. Cancelar\n");
                        printf("Opcao:");
                        scanf("%d", &op2);
                        if((op2 < 1) || (op2 > 4)) {
                            printf("\n\n Opcao Invalida! Tente novamente...\n");
                        }
                    }while((op < 1) || (op > 4));
                        switch(op2){
                            case 1:
                                system("clear");
                                if(iguais(lst1, lst2) != 0)
                                    printf("Listas iguais!\n");
                                else
                                    printf("Lista não iguais!\n");
                                break;
                            case 2:
                                system("clear");
                                break;
                            case 3:
                                system("clear");
                                break;
                            default:
                                break;
                        }
                }while(op2 != 4);
                break;

            case 4:
                system("clear");
                do{
                    do{
                        printf("Qual lista deseja verificar:\n");
                        printf("1. Lista 1\n");
                        printf("2. Lista 2\n");
                        printf("3. Lista 3\n");
                        printf("4. Cancelar\n");
                        printf("Opcao:");
                        scanf("%d", &op2);
                        if((op2 < 1) || (op2 > 4)) {
                            printf("\n\n Opcao Invalida! Tente novamente...\n");
                        }
                    }while((op2 < 1) || (op2 > 4));
                        switch(op2){
                            case 1:
                                system("clear");
                                printf("Tamanho: %d\n", tamanho(lst1));
                                break;
                            case 2:
                                system("clear");
                                printf("Tamanho: %d\n", tamanho(lst2));
                                break;
                            case 3:
                                system("clear");
                                break;
                            default:
                                break;
                        }
                }while(op2 != 4);
                
                break;
            
            case 5:
                system("clear");
                do{
                    do{
                        printf("Qual lista deseja inserir:\n");
                        printf("1. Lista 1\n");
                        printf("2. Lista 2\n");
                        printf("3. Lista 3\n");
                        printf("4. Cancelar\n");
                        printf("Opcao:");
                        scanf("%d", &op2);
                        if((op2 < 1) || (op2 > 4)) {
                            printf("\n\n Opcao Invalida! Tente novamente...\n");
                        }
                    }while((op2 < 1) || (op2 > 4));
                        switch(op2){
                            case 1:
                                system("clear");
                                printf("Digite o elemento a ser inserido:");
                                scanf("%d",&elem);
                                if(insere_elem_ord(&lst1, elem) == 1)
                                    printf("Elemento Inserido!\n");
                                else
                                    printf("Elemento NAO Inserido\n");
                                break;
                            case 2:
                                system("clear");
                                printf("Digite o elemento a ser inserido:");
                                scanf("%d",&elem);
                                if(insere_elem_ord(&lst2, elem) == 1)
                                    printf("Elemento Inserido!\n");
                                else
                                    printf("Elemento NAO Inserido\n");
                                break;
                            case 3:
                                system("clear");
                                break;
                            default:
                                break;
                        }
                }while(op2 != 4);
                
                break;

            case 6:
                system("clear");
                do{
                    do{
                        printf("Qual lista deseja verificar:\n");
                        printf("1. Lista 1\n");
                        printf("2. Lista 2\n");
                        printf("3. Lista 3\n");
                        printf("4. Cancelar\n");
                        printf("Opcao:");
                        scanf("%d", &op2);
                        if((op2 < 1) || (op2 > 4)) {
                            printf("\n\n Opcao Invalida! Tente novamente...\n");
                        }
                    }while((op2 < 1) || (op2 > 4));
                        switch(op2){
                            case 1:
                                system("clear");
                                printf(" %f\n", media(lst1));
                                if(media(lst1) != 0)
                                    printf("Media: %f \n", media(lst1));
                                else
                                    printf("Erro ao calcular medeia!\n");
                                break;
                            case 2:
                                printf(" %f\n", media(lst1));
                                if(media(lst2) != 0)
                                    printf("Media: %f.2\n", media(lst2));
                                else
                                    printf("Erro ao calcular medeia!\n");
                                break;
                            case 3:
                                system("clear");
                                break;
                            default:
                                break;
                        }
                }while(op2 != 4);
                
                break;

            case 7:
                system("clear");
                do{
                    do{
                        printf("Qual lista deseja verificar:\n");
                        printf("1. Lista 1\n");
                        printf("2. Lista 2\n");
                        printf("3. Lista 3\n");
                        printf("4. Cancelar\n");
                        printf("Opcao:");
                        scanf("%d", &op2);
                        if((op2 < 1) || (op2 > 4)) {
                            printf("\n\n Opcao Invalida! Tente novamente...\n");
                        }
                    }while((op2 < 1) || (op2 > 4));
                        switch(op2){
                            case 1:
                                system("clear");
                                printf("Digite o elemento a ser removido:");
                                scanf("%d",&elem);
                                
                                if(remove_elem_ord(&lst1,elem) == 1)
                                    printf("Elemento Removido!\n");
                                else
                                    printf("Elemento NAO Removido\n");
                                break;
                            case 2:
                                system("clear");
                                printf("Digite o elemento a ser removido:");
                                scanf("%d",&elem);
                                
                                if(remove_elem_ord(&lst2,elem) == 1)
                                    printf("Elemento Removido!\n");
                                else
                                    printf("Elemento NAO Removido\n");
                                break;
                            case 3:
                                system("clear");
                                break;
                            default:
                                break;
                        }
                }while(op2 != 4);
                
               
                break;
            
            case 8:
                system("clear");
                do{
                    do{
                        printf("Qual lista deseja imprimir:\n");
                        printf("1. Lista 1\n");
                        printf("2. Lista 2\n");
                        printf("3. Lista 3\n");
                        printf("4. Cancelar\n");
                        printf("Opcao:");
                        scanf("%d", &op2);
                        if((op2 < 1) || (op2 > 4)) {
                            printf("\n\n Opcao Invalida! Tente novamente...\n");
                        }
                    }while((op2 < 1) || (op2 > 4));
                        switch(op2){
                            case 1:
                                system("clear");
                                obtem_valor_elem(&lst1);
                                break;
                            case 2:
                                system("clear");
                                obtem_valor_elem(&lst2);
                                break;
                            case 3:
                                system("clear");
                                break;
                            default:
                                break;
                        }
                }while(op2 != 4);
                
                break;
            
            default:
				break;
        }
    } while(op != 9);

    return 0;
}