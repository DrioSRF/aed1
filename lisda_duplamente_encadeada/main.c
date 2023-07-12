#include "lista_duplamente_encadeada.h"

int main(int argc, char** argv)
{
    No *lista = criar();

    /* Inserir no início */
    lista = inserir(lista, 23);
    printf("%d\n", buscar(lista, 28));

    lista = inserir(lista, 45);
    printf("%d\n", buscar(lista, 45));

    lista = inserir(lista, 90);
    lista = inserir(lista, 34);

    /* Inserir no fim */
    lista->ant = inserir(lista, 67);
    imprimir(lista);

    /* Excluir do início */
    lista = excluir(lista);
    imprimir(lista);

    /* Excluir do fim */
    lista = excluir(lista->ant);
    imprimir(lista);

    return 0;
}