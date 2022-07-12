#include <stdio.h>
#include <stdlib.h>


typedef struct lista lista;

lista* criar_lista();
int lista_vazia(lista *lst);
int lista_cheia(lista *lst);
int insere_elem_ord(lista *lst, int elem);
int remove_elem(lista *lst, int elem);
void obtem_valor_elem(lista *lst);
int remove_impares(lista *lst);
int devolve_menor(lista *lst, int *elem);
int ordena_lista(lista *lst);
int tamanho(lista *lst);
lista* concatena(lista *lst1, lista *lst2);
