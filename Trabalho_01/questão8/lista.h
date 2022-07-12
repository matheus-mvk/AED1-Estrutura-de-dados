typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista );
int insere_ord (Lista *, int , int);
int remove_ord (Lista *, int , int *);
int esvazia_lista(Lista *);
int apaga_lista(Lista *);
int get_elem_pos(Lista , int , int *, int *);
void imprime_lista(Lista L);
int calcula(Lista , int );