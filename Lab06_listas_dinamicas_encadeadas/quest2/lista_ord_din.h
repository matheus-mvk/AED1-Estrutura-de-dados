typedef struct no *Lista;

Lista criar_lista();
int lista_vazia(Lista lst);
int insere_elem_ord(Lista *lst, int elem);
int remove_elem_ord(Lista *lst, int elem);
void obtem_valor_elem(Lista *lst);