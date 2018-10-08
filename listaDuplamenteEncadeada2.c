#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


// Lista duplamente encadeada 
// Autor Mayara
// 30/09/2015 


typedef struct _NO{
	struct _NO *prox;
	struct _NO *ant;
	int valor;
}NO;

typedef struct{
	NO *inicio;
	NO *fim;
	int tamanho;

}LISTA_DUPLAMENTE;

LISTA_DUPLAMENTE *criar_lista(){

	LISTA_DUPLAMENTE *lista = (LISTA_DUPLAMENTE*) malloc (sizeof(LISTA_DUPLAMENTE));

	if(lista != NULL){
		lista->inicio = NULL;
		lista->fim = NULL;
		lista->tamanho = 0;
		return lista;
	}
	return NULL;
}

int vazia(LISTA_DUPLAMENTE *lista){
	return(lista->fim == 0);
}

int inserir_fim(LISTA_DUPLAMENTE *lista, int valor){
	
	NO *novo = (NO*) malloc (sizeof(NO));
	
	if(novo == NULL){
		return FALSE;
	}

	// setando o valor do NO
	novo->valor = valor;

	// entro aqui caso lista esteja vazia e faço a ligaçao
	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
		lista->tamanho++;
		return TRUE;
	}else{

		// se a lista nao estiver vazia faço a ligacao e atualizo a lista fim
		NO *aux = lista->fim;

		aux->prox = novo;
		novo->ant = aux;
		lista->fim = novo;
		lista->tamanho++;
		return TRUE;
	}
	return FALSE;
}

int remover_fim(LISTA_DUPLAMENTE *lista){

	if(!vazia(lista)){

		lista->fim = lista->fim->ant;
		lista->fim->prox = NULL;

		return TRUE;		
	}else{

		return FALSE;
	}
}

/*
int inserir_pos(LISTA_DUPLAMENTE *lista, int valor, int pos){

	NO *novo = (NO*) malloc (sizeof(NO));
	if(novo == NULL){
		return FALSE;
	}

	// setando valor do NO

	novo->valor = valor; 

	NO *aux = lista->inicio;
	int i = 1;

	if(pos>= 1 && pos<=lista->tamanho){
		while(aux != NULL){
			
			if(i == pos){

				aux->ant
			}
			aux = aux->prox;
			i++;
		}

		return TRUE;
	}else{
		return FALSE;
	}

}	
*/

void imprimir_lista(LISTA_DUPLAMENTE *lista){
	NO *aux = lista->inicio;

	while(aux !=NULL){
		printf("O valor eh :%d\n",aux->valor);
		aux = aux->prox;
	}
	printf("\n");
}

int main (void){

	LISTA_DUPLAMENTE *lista = criar_lista();
	inserir_fim(lista,2);

	imprimir_lista(lista);

	inserir_fim(lista,3);

	imprimir_lista(lista);

	printf("Fiz a remocao !\n");
	remover_fim(lista);

	imprimir_lista(lista);

	return 0;
}