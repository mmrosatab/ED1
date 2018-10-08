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
	printf("O item foi apagado!\n");
}

void imprimir_item(ITEM *item){
	printf("Chave eh :%d .Valor eh :%d \n",item->chave,item->valor);
}

typedef struct{
	ITEM *itens[MAX];
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
	}else{
		return FALSE;
	} 
}

int cheia(LISTA_ESTATICA *lista){
	if(lista->fim == MAX-1){
		return TRUE;
	}else{
		return FALSE;
	}
		
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

// inseri elemento de forma ordenada(criterio por valor)
int insercao_ordenada_valor(LISTA_ESTATICA *lista,ITEM *item){
	
	if(!cheia(lista)){		
		
		int i,pos;
		pos = lista->fim + 1;
		
		for(i=0;i<=lista->fim;i++){
			if(item->valor < lista->itens[i]->valor){
					pos = i;
					break;			
			}
		}
		
		for(i=lista->fim;i>=pos;i--){
			lista->itens[i+1] = lista->itens[i];
		}
		
		lista->itens[pos] = item;
		lista->fim = lista->fim + 1;
		return TRUE;		
	}else{
		return FALSE;
	}
	
}

// inseri elemento de forma ordenada(criterio por chave)
int insercao_ordenada_chave(LISTA_ESTATICA *lista,ITEM *item){
	
	if(!cheia(lista)){		
		
		int i,pos;
		pos = lista->fim + 1;
		
		for(i=0;i<=lista->fim;i++){
			if(item->chave < lista->itens[i]->chave){
					pos = i;
					break;			
			}
		}
		
		for(i=lista->fim;i>=pos;i--){
			lista->itens[i+1] = lista->itens[i];
		}
		
		lista->itens[pos] = item;
		lista->fim = lista->fim + 1;
		return TRUE;
	}else{
		return FALSE;
	}
}

// inseri elemento de forma ordenada(criterio por valor) com while 
int insercao_ordenada_chave2(LISTA_ESTATICA *lista,ITEM *item){
	
	if(!cheia(lista)){		
		
		int pos;
		pos = lista->fim + 1;
		
		while (pos > 0 && lista->itens[pos-1]->chave > item->chave){
			lista->itens[pos] = lista->itens[pos-1];
			pos--;
		}
		
		lista->itens[pos] = item;
		lista->fim = lista->fim + 1;
		return TRUE;	
	}else{
		return FALSE;
	}

		
}

int remover_ordenado_posicao(LISTA_ESTATICA *lista, int pos){
	
	if(!vazia(lista) && pos>=0 && pos<=lista->fim){
		    free(lista->itens[pos]);
		    
			int i;
			for(i=pos;i<lista->fim;i++){
				lista->itens[i] = lista->itens[i+1];
			}			
			
		lista->fim = lista->fim - 1;
		return TRUE;
	}else{
		return FALSE;
	}
}


ITEM* busca_binaria(LISTA_ESTATICA *lista, int valor){
	
	int sup,inf,meio;
	
	if(!vazia(lista)){
		
		inf = 0;
		sup = lista->fim+1;
		
		while(inf<=sup){
			
			meio = (inf+sup)/2;
			
			if(lista->itens[meio]->valor == valor){
				return lista->itens[meio];
			}else{
				
				if(lista->itens[meio]->valor<valor){
					inf = meio+1;
				}else{
					sup = meio-1;
				}
			}
			
		}
		
		return NULL;
	}else{
		return NULL;
	}	
}


int main(void){
	
	LISTA_ESTATICA *l1 = criar_lista();
	
	ITEM *item1 = criar_item(3,3);
	ITEM *item2 = criar_item(2,1);
	ITEM *item3 = criar_item(1,5);
	ITEM *item4 = criar_item(5,6);
	ITEM *item5 = criar_item(6,9);
	
	insercao_ordenada_valor(l1,item1);
	insercao_ordenada_valor(l1,item2);	
	insercao_ordenada_valor(l1,item3);
	insercao_ordenada_valor(l1,item4);
	insercao_ordenada_valor(l1,item5);
	
	imprimir_lista(l1);
	
	printf("\n");

	imprimir_item(busca_binaria(l1,3));
	
	free(l1);
	return 0;
	
}
