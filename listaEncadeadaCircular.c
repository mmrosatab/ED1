#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


// *** LISTA ENCADEADA CIRCULAR***
typedef struct{
	int chave;
	int valor;
}ITEM;

typedef struct _NO{
	ITEM *item;
	struct _NO *prox;
}NO;

typedef struct{
	NO *inicio;
	NO *fim;
	int tamanho;
}LISTA_ENCADEADA;

void apagar_no(NO *no){
	free(no->item);
	free(no);
}

ITEM *criar_item(int novaChave, int novoValor){
	
	ITEM *item = (ITEM*)malloc(sizeof(ITEM));
	item->chave = novaChave;
	item->valor = novoValor;
	return item;
}

void imprimir_item(ITEM *item){
	printf("Chave eh :%d Valor eh :%d\n",item->chave,item->valor);
}

LISTA_ENCADEADA *criar_lista(){
	LISTA_ENCADEADA *lista = (LISTA_ENCADEADA*)malloc(sizeof(LISTA_ENCADEADA));
	if(lista != NULL){
		lista->inicio = NULL;
		lista->fim = NULL;
		lista->tamanho = 0;
	}
	return lista;
}

int vazia(LISTA_ENCADEADA *lista){

	if(lista->inicio == NULL)
		return TRUE;
	else{
		return FALSE;
	}
}

void apagar_lista(LISTA_ENCADEADA *lista){
	NO *aux1 = lista->inicio;
	NO *aux2 = NULL;

	int i=1;
	while(aux1 != NULL){
		aux2 = aux1->prox;
		apagar_no(aux1);
		aux1 = aux2;
		printf("Apagando item %d\n",i);
		i++;
	} 

	puts("A lista foi apagada!\n");
}

int inserir_posicao(LISTA_ENCADEADA *lista,ITEM *item){

	NO * novo_no = (NO *)malloc (sizeof(NO));

	if(novo_no == NULL){
		return FALSE;
	} 

	if(pos != 1 && vazia(lista)){
		return FALSE;
	}

	if(pos == 1 && vazia(lista)){

		novo_no->item = novo_no;
		lista->inicio = novo_no;
		lista->fim = novo_no;
		novo_no->prox = novo_no;
		lista->tamanho++;
		
	}else{

	}	


}



int main(){
	return 0;
}
