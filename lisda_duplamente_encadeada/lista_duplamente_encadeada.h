#include <stdio.h>
#include <stdlib.h>

/* definição da estrutura de dados */
typedef struct no No;

struct no
{
	int dado;
	No* prox;
    No* ant;
};

No* criar()
{
	return NULL;
}

No* inserir(No *lista, int dado)
{
    No *novo;

	novo = (No *)malloc(sizeof(No));
	novo->dado = dado;

    if(lista == NULL)
    {
        novo->prox = novo;
        novo->ant = novo;
        return novo;
    }
    
    else
    {
        novo->prox = lista;
        novo->ant = lista->ant;
        lista->ant->prox = novo;
        lista->ant = novo;
        return novo;
    }
}

No* excluir(No *lista)
{
    No *temp = lista;

    /* Fazendo o próximo nó ser o novo início */
    lista = lista->prox;
    temp->ant->prox = lista;
    lista->ant = temp->ant;

    /* Desligando o temp do resto da lista e liberando memória */
    temp->ant = NULL;
    temp->prox = NULL;
    free(temp);

    return lista;
}

void imprimir(No *lista)
{
    if(lista != NULL)
    {
        No *temp = lista;
        
        printf("%d ", temp->dado);
        temp = temp->prox;

        while(temp != lista){
            printf("%d ", temp->dado);
            temp = temp->prox;
        }
    }

    printf("\n");
}

int buscar(No *lista, int dado)
{
    if(lista != NULL)
    {
        if(lista->dado == dado)
            return 1;
        
        else
        {
            No *temp;
            
            temp = lista->prox;
            
            while(temp != lista)
            {
                if (temp->dado == dado)
                    return 1;

                temp = temp->prox;
            }
            
            return 0;
        }
    }

    else
        return 0;
}
