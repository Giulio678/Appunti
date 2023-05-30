#include <stdio.h>
#include <stdlib.h>


struct elemento{
	int info;
	struct elemento *next;
};

typedef struct elemento ELementoDiLista;
typedef ELementoDiLista *ListaDiElementi;

void inizializza(ListaDiElementi *head)
{
	*head=NULL;
}

void aggiungiintesta(ListaDiElementi *head,int el)
{
	ListaDiElementi aux;

	aux=malloc(sizeof(ELementoDiLista));
	aux->info=el;
	aux->next=*head;
	*head=aux;
}

void InsRec(ListaDiElementi *head)
{
	ListaDiElementi aux;


		if(*head!=NULL)
		{
		if(((*head)->info)%2==0)
		{
			aux=malloc(sizeof(ELementoDiLista));
			aux->info=-1;
			//fprintf(stderr, "%d\n",aux->info);
			aux->next=*head;
			*head=aux;
			InsRec(&(((*head)->next)->next));
			}else
			{
				InsRec(&((*head)->next));
			}
		}
	
}

void stampa(ListaDiElementi head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->info);
		head=head->next;
	}
}




int main()
{
	ListaDiElementi lista;

	inizializza(&lista);

	int val=0;

	while(val>=0)
	{
		scanf("%d",&val);
		if(val>=0)
			aggiungiintesta(&lista,val);

	}

	InsRec(&lista);

	stampa(lista);

return 0;
}