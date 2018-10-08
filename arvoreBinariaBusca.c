#include <stdio.h>
#include <stdlib.h>
#define FILHOESQUERDO 0
#define FILHODIREITO 1

typedef struct No{
	
	int valor;
	struct No *filhorEsq;
	struct No *filhorDir;

}No;

typedef struct Arvore{
	No *raiz;
}Arvore;

Arvore *criarArvore(){
	Arvore *arv = (Arvore*) malloc (sizeof(Arvore));
	
	if(arv != NULL){
		arv->raiz = NULL;
	}else{
		return NULL;
	}
}

No *criarRaiz(Arvore *arv, int valor){
	arv->ra = (No*) malloc (sizeof(No));
	
	if(no != NULL){
		
		arv->raiz->valor = valor;
		arv->raiz->filhorEsq = NULL;
		arv->raiz->filhorDir = NULL;
		
	}
		
}


int main(){
	
	
	return 0;
}
