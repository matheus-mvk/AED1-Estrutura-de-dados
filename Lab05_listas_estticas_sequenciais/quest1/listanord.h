
typedef struct lista lista;

lista* criar_lista();
int lista_vazia(lista *lst);
int lista_cheia(lista *lst);
int insere_elem(lista *lst, int elem);
int remove_elem(lista *lst, int elem);
void obtem_valor_elem(lista *lst);