#include <stdio.h>
#include "lista.h"

int
main()
{
    int op, flag = 0;
    Lista L;

    do{
        do{
            printf("\n------------------------\n");
            printf("[1]Criar um polinomio\n");
            printf("[2]Reinicializar polinonio\n");
            printf("[3]Calcular polinomio\n");
            printf("[4]Inserir um termo\n");
            printf("[5]Remover um termo\n");
            printf("[6]Imprimir polinomio\n");
            printf("[7]Sair\n");
            printf("\nDigite sua opção: ");
            scanf("%d", &op);
            getchar();

            if(op < 1 || op > 7)
                printf("Opção não válida\n");
        }while(op < 1 || op > 7);

        if(op == 7)
            break;
        else if(op != 1 && flag == 0){
            printf("\nA lista precisa ser criada!\n");
            continue;
        }
        switch (op){
            case 1: {      
                if(flag == 0){
                    L = cria_lista();
                    
                    printf("\nA lista %d foi criada com sucesso\n", flag+1);
                    flag = 1;
                }  
                break;
            }
            case 2: {
                if (esvazia_lista(&L) == 0){
                    printf("\nLista inexistente\n");
                }
                else{
                    printf("\n\nA lista %d foi esvaziada com sucesso\n", flag+1);
                    flag = 0;
                }
                
                break;
            }
            case 3: {
                int x;
                printf("\nDigite um valor de x para calcular o polinomio: ");
                scanf("%d", &x);

                if (calcula(L, x) == 0){
                    printf("\nLista vazia\n");
                }
                else
                    imprime_lista(L);
                    /*printf("Com x: %d\n", x);*/
                    printf("Resposta: %d\n", calcula(L, x));

                break;
            }
            case 4: {
                int elem_coef, elem_grau, valor;
                printf("\nDigite o coeficiente a ser inserido: ");
                scanf("%d", &elem_coef);
                printf("\nDigite o grau desse polinômio: ");
                scanf("%d", &elem_grau);

                valor = insere_ord(&L,  elem_coef, elem_grau);

                if(valor == 0){
                    printf("\nA lista já está cheia\n");
                    printf("\nNão foi possivel incluir o elemento %dx^%d \n",  elem_coef, elem_grau);
                }
                else if (valor == 3){
                    printf("\n %dx^%d somado ao já existente\n", elem_coef, elem_grau);
                }
                else{
                    printf("\nO elemento %dx^%d foi incluido com sucesso\n",  elem_coef, elem_grau);
                }
                break;
            }
            case 5: {
                int elem_coef, elem_grau, valor;

                printf("\nDigite o grau do termo que desejas retirar: ");
                scanf("%d", &elem_grau);

                valor = remove_ord(&L, elem_grau, &elem_coef);

                if(valor == 0){
                    if(lista_vazia(L) == 1)
                        printf("\n\nA lista está vazia\n");
                }
                else if(valor == 3){
                    printf("\nNão existe termo de grau %d\n", elem_grau);
                }
                else
                    printf("\nO elemento %dx^%d foi removido\n", elem_coef, elem_grau);
                }
                break;
            case 6: {
                imprime_lista(L);

            break;
            }      
        }
    }while(op != 7);

    printf("\nVolte sempre!\n");

	return 0;
}

void imprime_lista(Lista L){
    if(lista_vazia(L) == 1){
            printf("\n===LISTA VAZIA===\n");
    }
    else{
        printf("\nP(x) =");
        for (int i = 1; ; i++){
            int elem_coef, elem_grau;
            char sinal = '+';
            if(get_elem_pos(L, i, &elem_coef, &elem_grau) == 0){
                break;
            }
            if (elem_coef >= 0){
                printf("%c %dx^%d ", sinal, elem_coef, elem_grau);
            }
            else
                printf("%c (%dx^%d) ", sinal, elem_coef, elem_grau);    
        }
        printf("\n");
    }
}