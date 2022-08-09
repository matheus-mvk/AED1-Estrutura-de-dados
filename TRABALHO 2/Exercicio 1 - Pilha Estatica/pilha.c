#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#define max 20

struct pilha{
    int no[max];
    int topo;
};

/*
Pilha cria_pilha()
    Entrada: nenhuma
    Pré-Condição: nenhuma
    Processo: cria uma pilha e a coloca no estado de pilha vazia
    Saída: endereço da pilha criada
    Pós-Condição: nenhuma
*/

Pilha cria_pilha(){
    Pilha p;
    p = (Pilha)malloc(sizeof(struct pilha));
    if(p != NULL)
        p->topo = -1;
    return p;
}

/*
int pilha_vazia(Pilha p)
    Entrada: endereço da pilha
    Pré-Condição: nenhuma
    Processo: verifica se a pilha está vazia
    Saída: retorna 1 se pilha vazia, 0 caso contrario
    Pós-Condição: nenhuma
*/

int pilha_vazia(Pilha p){
    if(p->topo == -1)
        return 1;
    else
        return 0;
}

/*
int pilha_cheia(Pilha p)
    Entrada: endereço da pilha
    Pré-Condição: nenhuma
    Processo: verifica se a pilha está cheia
    Saída: retorna 1 se pilha cheia, 0 caso contrario
    Pós-Condição: nenhuma
*/

int pilha_cheia(Pilha p){
    if(p->topo == max-1)
        return 1;
    else
        return 0;
}

/*
int push(Pilha p, int elem)
    Entrada: endereço da pilha e o elem a ser inserido
    Pré-Condição: pilha nao estar cheia
    Processo: inserir o elemento informado no topo da pilha
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-Condição: a pilha de entrada com um elem a mais
*/

int push(Pilha p, int elem){
    if(p == NULL || pilha_cheia(p) == 1)
        return 0;
    
    // Insere o elemento no topo
    p->topo++;
    p->no[p->topo] = elem;
        return 1;
}

/*
int pop(Pilha p, int *elem)
    Entrada: endereço da pilha e o elem de retorno do elem do topo da pilha
    Pré-Condição: pilha nao estar vazia
    Processo: remover o elem que esta no topo da pilha e retorna-lo
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-Condição: a pilha de entrada com um elem a menos e a variavel de retorno com o elem removido
*/

int pop(Pilha p, int *elem){
    if(p == NULL || pilha_vazia(p) == 1)
        return 0;
    
    *elem = p->no[p->topo];     // retorna o elem
    p->topo--;      // remove o elem do topo
        return 1;
}


/*
int le_topo(Pilha p, int *elem)
    Entrada: endereço da pilha e o elem de retorno do elem do topo da pilha
    Pré-Condição: pilha nao estar vazia
    Processo: retornar o elem que esta no topo da pilha SEM remove-lo
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-Condição: variavel de retorno com o elemento do topo
*/

int le_topo(Pilha p, int *elem){
    if(p == NULL || pilha_vazia(p) == 1)
        return 0;
    *elem = p->no[p->topo];     // retorna o elem
        return 1;
}

/*
void imprime_pilha(Pilha p)
    Entrada: endereço da pilha
    Pré-Condição: pilha nao estar vazia e estar alocada
    Processo: percorre a pilha e a imprime
    Pós-Condição: nenhuma
    Saída: pilha mostrada na tela para o usuario
*/

void imprime_pilha(Pilha p){
    int elem_removido;
    Pilha p2;
    p2 = cria_pilha();

    while(!pilha_vazia(p)){
        printf("%d ", p->no[p->topo]);
        push(p2, p->no[p->topo]);
        pop(p, &elem_removido);
    }

    if(pilha_vazia(p2) == 0){
        for(int i=0; p2->topo != -1; i++){
            push(p, p2->no[p2->topo]); 
            pop(p2, &elem_removido); 
        }
    }
}

/*
int eh_palindromo(char *vet)
    Entrada: ponteiro pra um vetor
    Pré-Condição: nenhuma
    Processo: verifica se uma string de entrada é uma palíndromo
    Pós-Condição: retorna 1 caso for, 0 se não
    Saída: nenhuma
*/

int eh_palindromo(char *vet){
    int len, mid, ele;
    int i;
    Pilha p;
    p = cria_pilha();

    len = strlen(vet);  // tamanho da string
    mid = len/2;
    for(i = 0; i < mid; i++){
        push(p, vet[i]);   // empilha o elem até a metade
    }      
    if(len%2 !=0)
        i++;

    while(vet[i] != '\0'){
        pop(p, &ele);
            
        if(ele != vet[i])
            return 0;
        
         i++;
        }
    return 1;
}

/*
void libera_pilha(Pilha p)
    Entrada: endereço da Pilha
    Pré-condições: pilha ser válida e não estar vazia
    Processo: libera todos os elementos da pilha
    Saída: 1 caso tenha liberado ou 0 caso o contrário
    Pós-condição: pilha sem nenhum elemento
*/

int libera_pilha(Pilha p){
    if(p == NULL)
        return 0;

    free(p);
    p -> topo = -1;
    return 1;
}

/*
void imprimir_reversa(Pilha p)
    Entrada: endereço da Pilha
    Pré-condições: pilha ser válida e não estar vazia
    Processo: cria uma pilha auxiliar e coloca os elementos da pilha original de modo reverso e a imprime
    Saída: nenhuma
    Pós-condição: pilha imprimida de modo invertido
*/

void imprimir_reversa(Pilha p){
    if(p == NULL ||pilha_vazia(p))
        printf("Pilha vazia");
    else{
        Pilha aux;  // pilha auxiliar
        cria_pilha(&aux);
        int x;  // variavel q armazena cada valor desempilhado
        while(p->topo != -1){
            pop(p, &x);
            push(aux, x);
        }
        imprime_pilha(aux);
    }

}

/*
void pares_impares(Pilha p)
    Entrada: endereço da pilha
    Pré Condição: pilha nao estar vazia e estar alocada
    Processo: imprime os pares e os impares da pilha de forma separada
    Pós Condição: nenhuma
    Saída: elementos pares e impares mostrados na tela pro usuario
*/

void pares_impares(Pilha p){
    if(p == NULL ||pilha_vazia(p))
        printf("Pilha vazia");
    else{
        int x;  // variavel auxiliar
        Pilha p_par = cria_pilha();
        Pilha p_impar= cria_pilha();
        while(p->topo != -1){
            if(p->no[p->topo]% 2 == 0){
                push(p_par, p->no[p->topo]);
            }
            else{
                push(p_impar, p->no[p->topo]);
            }
            pop(p,&x);
         }
        printf("---Elementos pares da pilha:---\n");
        imprime_pilha(p_par);
        printf("\n---Elementos impares da pilha:---\n");
        imprime_pilha(p_impar);
    }
}

/*
int elimina(Pilha p, int elem)
    Entrada: endereço da pilha e elemento a ser eliminado
    Pré Condição: pilha nao estar vazia e estar alocada
    Processo: elimina o elemento desejado
    Pós Condição: retorna 1 se sucesso, 0 se falha
    Saída: fila com um elemento a menos
*/

int elimina(Pilha p, int elem){
    int elem_removido, tam, tam2;
    if(pilha_vazia(p))
        return 0;
    Pilha p2;
    p2 = cria_pilha(); 
    tam = p->topo; 

    for(int i=0; i <= tam; i++){
        if(p->no[p->topo] == elem){
            pop(p, &elem_removido);
            break;
        }
        push(p2, p->no[p->topo]);
        pop(p, &elem_removido);
    }
    imprime_pilha(p);
    printf("\n");

   
    if(pilha_vazia(p2) == 0){
        for(int i=0; p2->topo != -1; i++){
            push(p, p2->no[p2->topo]); 
            pop(p2, &elem_removido); 
        } 
    }
    return 1;
}
