#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0


typedef struct{
	int chave;
	int valor;
}ITEM;

ITEM *criar_item(int novaChave, int novoValor){
	
	ITEM *item = (ITEM*)malloc(sizeof(ITEM));
	item->chave = novaChave;
	item->valor = novoValor;
	return item;
}

void apagar_item(ITEM *item){
	free(item);
	printf("O item foi apagado!");
}

void imprimir_item(ITEM *item){
	printf("Chave eh :%d .Valor eh :%d \n",item->chave,item->valor);
}

typedef struct{
	struct ITEM *itens[MAX];
	int fim;
}LISTA_ESTATICA;

LISTA_ESTATICA *criar_lista(){
	LISTA_ESTATICA *lista = (LISTA_ESTATICA*)malloc(sizeof(LISTA_ESTATICA));
	lista->fim = -1;
	return lista;
}

void apagar_lista(LISTA_ESTATICA *lista){
	 free(lista);
}

int vazia(LISTA_ESTATICA *lista){
	if(lista->fim == -1){
		return TRUE;
	}else 
		return FALSE;
}

int cheia(LISTA_ESTATICA *lista){
	if(lista->fim == MAX-1){
		return TRUE;
	}else
		return FALSE;
	
}

int tamanho(LISTA_ESTATICA *lista){ 	
	return lista->fim+1; // retorna o numero de elementos que tem na lista
}

void imprimir_lista(LISTA_ESTATICA *lista){
	int i;
	for(i=0;i<=lista->fim;i++){ //ou posicao<lista->fim+1
		printf("Item %d\n",i);
		printf("Chave eh %d. Valor eh %d\n", lista->itens[i]->chave,lista->itens[i]->valor);
	}
}

int inserir_fim(LISTA_ESTATICA *lista,ITEM *item){
	if(cheia(lista)){
		return FALSE;
	}else{
		lista->itens[lista->fim+1] = item;
		lista->fim = lista->fim+1;
		return TRUE;
	}
		
}

int inserir_posicao(LISTA_ESTATICA *lista,ITEM *item,int posicao){ // coloquei posicao<=lista->fim+1 pq tbm posso inserir no final
	if(!cheia(lista) && posicao>=0 && posicao<=lista->fim+1){  // ou posicao<lista->fim+1 
		int i=0;                               // se posicao>lista->fim , na realidade a pessoa quer inserir no final da lista 
		for(i=lista->fim;i>=posicao;i--){
			lista->itens[i+1] = lista->itens[i];
		}
		lista->itens[posicao] = item;
		lista->fim = lista->fim+1;
		return TRUE;
	}else{
		return FALSE;
	}
		
}
	
//remove item da lista na posicao informada
int remover_posicao(LISTA_ESTATICA *lista,int posicao){
	if(!vazia(lista) && posicao>= 0 && posicao<=lista->fim){
		
		free(lista->itens[posicao]);

		int i;

		for(i=posicao;i<lista->fim;i++){
			lista->itens[i] = lista->itens[i+1];
		}
		lista->fim = lista->fim-1;
		return TRUE;		
	}else{
		return FALSE;
	}	
}

// remove item do fim da lista 
int remover_fim(LISTA_ESTATICA *lista){
	if(!vazia(lista)){
		lista->fim = lista->fim-1;
		return TRUE;		
	}else{
		return FALSE;
	}	
}

ITEM* busca_chave(LISTA_ESTATICA *lista,int chave){
	
	lista->itens[lista->fim]->chave = chave;
	
	int pos = 0;

	while(lista->itens[pos]->chave != chave){
		pos++;	
	}
	if(pos>lista->fim){
		return NULL;
	}else
		return lista->itens[pos];
}

// busca posicao por chave informada
int busca_posicao(LISTA_ESTATICA *lista,int chave){
	
	if(vazia(lista)){
		return -1;
	}

	lista->itens[lista->fim]->chave = chave;
	
	int posicao = 0;

	while(lista->itens[posicao]->chave != chave){
		posicao++;	
	}
	if(posicao>lista->fim){
		return -1;
	}else
		return posicao;

}

int remover_chave(LISTA_ESTATICA *lista,int chave){

	if(vazia(lista)){
		return -1;
	}else
	{
		int posicao = busca_posicao(lista,chave);

		if(posicao == -1)
			return FALSE;
		if(remover_posicao(lista,posicao)){
			return TRUE;
		}else
			return FALSE;

	}
}

LISTA_ESTATICA *copiar_lista(LISTA_ESTATICA *lista){
	LISTA_ESTATICA *novaLista = criar_lista();
	int i;
	for(i=0;i<=lista->fim;i++){
		novaLista->itens[i] = lista->itens[i];
		novaLista->fim = novaLista->fim+1;
	} 
	return novaLista;
}

// return true se lista esta ordenada em forma crescente 
int ordenada_crescente(LISTA_ESTATICA *lista){
	int i;
	for(i=0;i<lista->fim;i++){
		if(lista->itens[i]->valor > lista->itens[i+1]->valor){
			return FALSE;
		}
	}
	return TRUE;
}

// return true se lista esta ordenada em forma decrescente 
int ordenada_decrescente(LISTA_ESTATICA *lista){
	int i;
	for(i=0;i<lista->fim;i++){
		if(lista->itens[i]->valor < lista->itens[i+1]->valor){
			return FALSE;
		}
	}
	return TRUE;
}

int main(){
	return 0;
}


