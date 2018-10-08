#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct ITEM *criar_item(int novaChave, int novoValor);
struct LISTA_ENCADEADA *criar_lista();

struct ITEM{
	int chave;
	int valor;
};

struct NO{
	struct ITEM *item;
	struct NO *prox;
};

struct LISTA_ENCADEADA{
	struct NO *inicio;
	struct NO *fim;
	int tamanho;
};

struct ITEM *criar_item(int novaChave, int novoValor){
	
	struct ITEM *item = (struct ITEM*)malloc(sizeof(struct ITEM));
	item->chave = novaChave;
	item->valor = novoValor;
	return item;
}

void imprimir_item(struct ITEM *item){
	printf("Chave eh :%d Valor eh :%d\n",item->chave,item->valor);
}

struct LISTA_ENCADEADA *criar_lista(){
	struct LISTA_ENCADEADA *lista = (struct LISTA_ENCADEADA*)malloc(sizeof(struct LISTA_ENCADEADA));
	if(lista != NULL){
		lista->inicio = NULL;
		lista->fim = NULL;
		lista->tamanho = 0;
	}
	return lista;
}

struct ITEM *recuperarItem(struct LISTA_ENCADEADA *lista, int chave){
	
	struct NO *paux = lista->inicio;
	
	while(lista->fim){
		if(paux->item->chave == chave){
			return paux->item;
		}
		paux = paux->prox;
	}

	return NULL;
}

int inserirItem(struct LISTA_ENCADEADA *lista,struct ITEM *item){

	struct NO *pnovo = (struct NO*) malloc(sizeof(struct NO));
	if(pnovo != NULL){
		pnovo->item = item;
		pnovo->prox = NULL;
		
		if(lista->inicio == NULL){
			lista->inicio = pnovo;		
		}else{
			lista->fim->prox = pnovo;
		}

	lista->fim = pnovo;
	lista->tamanho++;
	    return 1;
	}else{
		return 0;
	}		
}

void imprimirLista(struct LISTA_ENCADEADA *lista){
	struct NO *paux = lista->inicio;
	while(paux != NULL)
	{
		printf("Chave eh :%d Valor eh :%d\n",paux->item->chave,paux->item->valor);
		paux = paux->prox;	
	}
}

/*
	Para Casa

	apagarlista
	inserirItem
	removerItem
	recuperarItem
	contarNumeroItens
	imprimirLista
	
*/

int main(){

	struct LISTA_ENCADEADA *lista = criar_lista(); 

	struct ITEM *item1 = criar_item(2,20);
	struct ITEM *item2 = criar_item(1,10);
	struct ITEM *item3 = criar_item(3,30);
	struct ITEM *item4 = criar_item(4,40);
	struct ITEM *item5 = criar_item(2,20);

	inserirItem(lista,item1);
	inserirItem(lista,item2);
	inserirItem(lista,item3);
	inserirItem(lista,item4);

	imprimirLista(lista);
	
	return 0;
}
