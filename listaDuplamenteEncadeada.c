#include<stdlib.h>
#include<stdio.h>
#define true 1
#define false 0

/*
	-criar item,no lista
	-inserir_fim,inserir_posicao,remover_fim,remover_posicao,remover_chave,vazia,
	imprimir.

*/
typedef struct {
    int chave;
    int valor;

}ITEM;

typedef struct _NO{
    ITEM *item;
    struct _NO* proximo;
    struct _NO* anterior;

}NO;

typedef struct {
    NO * inicio;
    NO * fim;
    int tamanho;

}LISTA_ENCADEADA;


ITEM *criar_item(int chave,int valor){
	ITEM *item = (ITEM*)malloc(sizeof (ITEM));
	item->chave = chave;
	item->valor = valor;
	return item;
}

LISTA_ENCADEADA *criar_lista(){
	
	LISTA_ENCADEADA *lista = (LISTA_ENCADEADA *) malloc (sizeof(LISTA_ENCADEADA));
	
	if(lista != NULL){
		lista->inicio = NULL;
		lista->fim = NULL;
		lista->tamanho = 0;
	}
	return lista;
}
int vazia(LISTA_ENCADEADA *lista){
	if(lista->inicio == NULL){
		return true;
	}
		return false;
}
int inserir_fim(LISTA_ENCADEADA *lista,ITEM *item){

		NO *novo_no = (NO*) malloc (sizeof(NO));

		if(novo_no != NULL) 
		novo_no->item = item;

		if(vazia(lista)){

			lista->inicio = novo_no;
			novo_no->proximo = NULL;
			novo_no->anterior = NULL;
			lista->fim = novo_no;
			return true;
		}else{
			
			lista->fim->proximo = novo_no;
			novo_no->anterior = lista->fim;
			lista->fim = novo_no;		
			return true;
		}
			return false;
}

int inserir(LISTA_ENCADEADA *lista,ITEM *item,int pos){
	
	NO *novo_no = (NO*)malloc(sizeof(NO));
	
	// vejo se tem espaco e se pos eh valida 
	if((novo_no != NULL) && (pos>=1 && pos<=lista->tamanho)){
 
		if(pos==1 && vazia(lista))){

			// setei o item
			novo_no->item = item;

			lista->inicio = novo_no;
			novo_no->proximo = NULL;
			novo_no->anterior = NULL;
			lista->fim = novo_no;
			lista->tamanho++;

			return TRUE;
		}

		if(pos>1 && vazia(lista)){
			return FALSE;
		}
	}else{

		return FALSE;
	}

}

void imprimir(LISTA_ENCADEADA *lista){
	NO *aux = lista->inicio;
	int i=1;
	while(aux != NULL){

		printf("item(%d) -- Chave: %d || Valor: %d \n",i, aux->item->chave, aux->item->valor);
		aux = aux->proximo;
		i++;
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


int main()
{
	LISTA_ENCADEADA *lista = criar_lista();
	inserir_fim(lista, criar_item(1,1));
	inserir_fim(lista, criar_item(2,2));
	inserir_fim(lista, criar_item(3,3));

	imprimir(lista);


	free(lista);
	return 0;
}