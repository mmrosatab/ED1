#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define FILHO_ESQUERDO 0
#define FILHO_DIREITO 1

typedef struct _No{
	struct _No *dir;
	struct _No *esq;
	int chave;
}NO;

typedef struct _ARVORE{
	NO *raiz;
}ARVORE;

NO * criarNo(int chave){

	NO *novo_no = (NO *) malloc(sizeof(NO));

	if(novo_no != NULL){

		novo_no->chave = chave;
		novo_no->dir = NULL;
		novo_no->esq = NULL;
		return novo_no;
	}

	else
		return NULL;
}

ARVORE *criarArvore(){

	ARVORE *avb = (ARVORE *) malloc(sizeof (ARVORE));

	if(avb != NULL){

		avb->raiz = NULL;
		return avb;
	}

	else
		return NULL;
}

int vazia(ARVORE *avb){
	if(avb->raiz == NULL)
		return true;
	else
		return false;
}

//Insere DE FATO um filho dado um nó específico da árvore
NO *inserir_filho(int filho, NO *raiz, int chave){

	NO* novo_filho = criarNo(chave);

	if(filho == FILHO_ESQUERDO){
		raiz->esq = novo_filho;
		return raiz->esq;
	}

	else{
		raiz->dir = novo_filho;
		return raiz->dir;
	}

	return NULL;

}
//Insere numa árvore específica com o auxílio de outras funções de inserção
void inserir(ARVORE *avb, NO* raiz,  int chave){

	if(vazia(avb)){
		avb->raiz = criarNo(chave);
	}
	else{

		if(chave < raiz->chave){

			if(raiz->esq != NULL)
				inserir(avb, raiz->esq, chave);
			else
				inserir_filho(FILHO_ESQUERDO, raiz, chave);
		}

		else if(chave > raiz->chave){

			if(raiz->dir != NULL)
				inserir(avb, raiz->dir, chave);
			else
				inserir_filho(FILHO_DIREITO, raiz, chave);
		}
	}

}

void emOrdem(NO *raiz){

	if(raiz != NULL){
		emOrdem(raiz->esq);
		printf("%d ", raiz->chave);
		emOrdem(raiz->dir);
	}
}

void preOrdem(NO *raiz){

	if(raiz != NULL){
		printf("%d ",raiz->chave);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

void posOrdem(NO *raiz){

	if(raiz != NULL){

		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf("%d ",raiz->chave);

	}
}

void imprime(ARVORE *avb){

	printf("Em ordem: ");
	emOrdem(avb->raiz);
	printf("\n");

	printf("Pre ordem: ");
	preOrdem(avb->raiz);
	printf("\n");

	printf("Pos ordem: ");
	posOrdem(avb->raiz);
	printf("\n");
}

int main(){

	ARVORE *arvore = criarArvore();
	inserir(arvore, arvore->raiz, 3);
	inserir(arvore, arvore->raiz, 2);
	inserir(arvore, arvore->raiz, 4);
	inserir(arvore, arvore->raiz, 1);
	inserir(arvore, arvore->raiz, 5);

	imprime(arvore);

	return 0;
}