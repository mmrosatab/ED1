#include<stdlib.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0

// *** LISTA ENCADEADA COM NO CABEÇA ***


typedef struct {
    int chave;
    int valor;

}ITEM;

typedef struct _NO{
    ITEM *info;
    struct _NO* prox;

}NO;

typedef struct {
    NO * cabeca;
    NO * fim;
    int tamanho;

}LISTA_ENCADEADA;

LISTA_ENCADEADA *criar_lista(){

    LISTA_ENCADEADA *lista = (LISTA_ENCADEADA *) malloc(sizeof(LISTA_ENCADEADA));
    lista->cabeca = (NO *) malloc(sizeof(NO));

    if(lista != NULL){

        lista->cabeca->prox = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

ITEM * criar_item (int chave, int valor){
    ITEM *item = (ITEM *) malloc (sizeof(ITEM));

    if(item != NULL){

        item->chave = chave;
        item->valor = valor;
        return item;
    }else{
        printf("Deu ruim\n");
        return NULL;
    }
}

void apagar_no(NO * n){
	free(n->info);
	free(n);
}

int vazia(LISTA_ENCADEADA *lista){

	if(lista->cabeca->prox == NULL)
		return TRUE;

	else
		return FALSE;
}

int inserir_fim(LISTA_ENCADEADA *lista, ITEM *item){
    NO *novo_no = (NO*) malloc (sizeof(NO));

    if(novo_no != NULL){

        novo_no->info = item;
        novo_no->prox = NULL;

        if(vazia(lista)){

            lista->cabeca->prox = novo_no;

        }else{

        	lista->fim->prox = novo_no;
        }

        lista->fim = novo_no;
        lista->tamanho++;
        return TRUE;

    }else

        //printf("Nao foi possivel inserir item.\n");
        return FALSE;
}

void apagar_lista(LISTA_ENCADEADA *lista){

	NO *aux;
	NO *remover = lista->cabeca->prox;
	
	while(lista->tamanho > 0){

		//anda com 2 ponteiros e apaga sempre o anterior, salvando o endereço do prox no
		aux = remover->prox;
		printf("Liberei item %d\n", remover->info->chave+1);
		apagar_no(remover);
		remover = aux;
		lista->tamanho--;

	}

	free(lista->cabeca);

	
}
void imprimir_lista(LISTA_ENCADEADA *lista){

    int n = 1;
    NO *aux = lista->cabeca->prox;

    while(aux != NULL){

        printf("Item(%d) -- chave: %d || valor: %d\n", n, aux->info->chave, aux->info->valor);
        
        aux = aux->prox;
        n++;
    }
}

void remover_item_chave(LISTA_ENCADEADA * lista, int chave){

    NO *aux = lista->cabeca;
    NO *remover;

    while(aux->prox != NULL){

        if(aux->prox->info->chave == chave){

            remover = aux->prox;
            aux->prox = remover->prox;

            if(remover == lista->fim){
                lista->fim = aux;
            }

            apagar_no(remover);
            break;
        }

        aux = aux->prox;
    }

    lista->tamanho--;
}

int remover_item_posicao(LISTA_ENCADEADA *lista, int pos){
	int i = 0;

	NO *aux = lista->cabeca;
	NO *remov;
    
	if(!vazia(lista)){

		while(i<pos){

			remov = aux->prox;
			aux->prox = remov->prox;
			aux = remov;
			i++;
		}

		apagar_no(remov);
		lista->tamanho--;
        return TRUE;
		
	}else{
        printf("lista vazia\n");
        return FALSE;	
	}
}

int inserir_posicao(LISTA_ENCADEADA *lista, ITEM *item, int posicao){

	int i = 1;

	NO *novo_no = (NO *)malloc(sizeof(NO));
	novo_no->info = item;
	NO *aux = lista->cabeca;

    if(i>=1 && i<= lista->tamanho){
	   while(i <= posicao){

		  if(i == posicao){

			 novo_no->prox = aux->prox;
			 aux->prox = novo_no;
		  }
		  aux = aux->prox;
		  i++;
	   }
	   lista->tamanho++;
        return TRUE;
    }else{
        return FALSE;
    }

}

// fiz mais tres funcoes
int numero_itens(LISTA_ENCADEADA *lista){
    return lista->tamanho; 
}

/*
ITEM *recuperar_item_posicao(LISTA_ENCADEADA *lista,int posicao){
    NO *aux = lista->cabeca->prox;
    int i=1;

    if(posicao>=1 && posicao<=lista->tamanho){
        while(i<=posicao){
            if(i==posicao){

                return aux->info;
            }
            aux = aux->prox;
            i++;
        }
    }
    return NULL;
}
*/

ITEM *recuperar_item_posicao(LISTA_ENCADEADA *lista,int posicao){
    NO *aux = lista->cabeca->prox;
    int i=1;

    while(aux != NULL){
        if(i==posicao){

            return aux->info;
        }
        aux = aux->prox;
        i++;
    }
    return NULL;
}

void imprimir_item(ITEM *item){
    printf("A chave eh :%d || O valor eh: %d \n",item->chave,item->valor);
}


int main(){

    LISTA_ENCADEADA *lista = criar_lista();

    ITEM * item = criar_item(0,0);
    ITEM * item2 = criar_item(1,1);

    inserir_fim(lista, item);
    inserir_fim(lista, item2);
    inserir_fim(lista, criar_item(2,2));

    imprimir_lista(lista);
    printf("\n");
    remover_item_posicao(lista,1);
    imprimir_lista(lista);
   
    free(lista);
    return 0; 
    
}
