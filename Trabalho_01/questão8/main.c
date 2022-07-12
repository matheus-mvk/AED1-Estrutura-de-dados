#include <stdlib.h>
#include <math.h>
#include "lista.h"

struct no{
    int info_coef;
    int info_grau;
    struct no *prox;
};

/*
Operação: cria_lista()
    -Entrada: nenhuma.
    -Pré-condição: nenhuma.
    -Processo: Aloca um nó cabeçalho para a lista.
    -Saída: retorna o nó cabeçalho alocado.
    -Pós-condição: nenhuma.
*/

Lista cria_lista(){
    //Aloca nó cabeçalho
    Lista cab;
    cab = (Lista) malloc(sizeof(struct no));
    if(cab != NULL){
        cab->prox = NULL;
        cab->info_coef = 0;
        cab->info_grau = 0; //opcional: guardar qtde
    }
    return cab; //se falhar retorna NULL
}

/*
Operação: lista_vazia
    -Entrada: Uma lista.
    -Pré-condição: Lista precisa ser instanciada.
    -Processo: Verifica se a lista está vazia.
    -Saída: 1 se é vazia e 0 se não.
    -Pós-condição: nenhuma
*/

int lista_vazia(Lista L) {
    if(L == NULL){
        return 1;
    }
    else
        return 0; 
}

/*
Operação: insere_ord
    -Entrada: O endereço de uma lista com o elemento a ser inserido.
    -Pré-condição: nenhuma.
    -Processo: Insere ordenadamente um elemento por meio de uma alocação a cada inserção.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: lista com o elemento inserido ordenadamente.
*/

int insere_ord (Lista *L, int elem_coef, int elem_grau) {
    // Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL)  return 0;  // Falha: nó não alocado

    N->info_coef = elem_coef; // Insere o conteúdo (valor do elem)
    N->info_grau = elem_grau;
    
    // Percorrimento da lista (elem > 1o nó da lista)
    Lista aux = *L; // Faz aux apontar para 1o nó

    if (elem_grau == 0){
        aux->info_coef += elem_coef;
        return 3;
    }

    while (aux->prox != NULL && aux->prox->info_grau <= elem_grau){
        if(elem_grau == aux->prox->info_grau){
            aux->prox->info_coef += (elem_coef);
            
            return 3;
        }
        aux = aux->prox; // Avança
    }
    // Insere o novo elemento na lista
    N->prox = aux->prox;

    aux->prox = N;

    return 1;
}

/*
Operação: remove_ord
    -Entrada: O endereço de uma lista e um elemento.
    -Pré-condição: Lista precisa ser instanciada e não pode estar vazia.
    -Processo: remove da lista o elemento selecionado.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Elemento selecionado removido da lista.
*/

int remove_ord (Lista *L, int elem_grau, int *elem_coef) {
    if (lista_vazia(*L) == 1)
        return 0; // Falha

    Lista aux = *L; // Ponteiro auxiliar para o 1o nó

    // Percorrimento até final de lista, achar elem ou nó maior
    while (aux->prox != NULL && aux->prox->info_coef < elem_grau)
        aux = aux->prox;

    if (aux->prox == NULL)
        return 3; // Falha

    // Remove elemento ≠ 1o nó da lista
    Lista aux2 = aux->prox; // Aponta nó a ser removido

    aux->prox = aux2->prox; // Retira nó da lista
    
    free(aux2); // Libera memória alocada

    return 1;
}

/*
Operação: esvazia_lista
    -Entrada: Endereço de uma lista.
    -Pré-condição: Lista existir.
    -Processo: Remove elemento a elemento liberando a memória alocada por eles.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista vazia com a memória alocada por eles liberada.
*/

int esvazia_lista(Lista *L){
    if(L == NULL) return 0;

    while(*L != NULL){
        Lista aux = *L; //Aponta para os primeiros elementos da lista
        *L = aux->prox; //Aponta pra o próximo el
        free(aux); //Libera os primeiros elementos até l -> NULL
    }

    return 1; //Sucesso
}

/*
Operação: apaga_lista
    -Entrada: Endereço de uma lista.
    -Pré-condição: Lista existir.
    -Processo: Chama o esvazia_lista e remove elemento a elemento liberando a memória alocada por eles.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: Lista vazia com a memória alocada por eles liberada.
*/

int apaga_lista(Lista *L){
    return (esvazia_lista(L));
}

/*
Operação: get_elem_pos
    -Entrada: Uma lista, a posição do elemento e o endereço do elemento.
    -Pré-condição: Lista existir, não ser vazia, além de ter as posições válidas.
    -Processo: Pega o elemento da sua respectiva posição.
    -Saída: 1 se Sucesso e 0 se falha.
    -Pós-condição: o endereço do elemento com o valor da sua posição na lista.
*/

int get_elem_pos(Lista L, int pos, int *elem_coef, int *elem_grau){
    if(lista_vazia(L) || pos <= 0) return 0;

    int cont = 1;
    Lista Aux = L;

    while (Aux->prox != NULL && cont < pos){
        Aux = Aux->prox;//Avança
        cont++;
    }
    if(cont != pos) return 0; //FALHA não existe posição solicitada

    *elem_coef = Aux->info_coef;
    *elem_grau = Aux->info_grau;

    return 1;
}

int calcula(Lista L, int x){
    if (lista_vazia(L)){
        return 0;
    }
    int resp = 0, conta = 0;
    Lista aux = L;

    while (aux != NULL){
        conta = aux->info_coef * (pow(x,aux->info_grau));
        resp += conta;
        aux = aux->prox;
    }

    return resp;
}