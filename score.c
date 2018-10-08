#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define TRUE 1
#define FALSE 0

//prototipos das funcoes 
typedef struct Score *criarScore(char novoNome, int novaPontuacao);
typedef struct Lista *criaLista();
int adicionarScore(Lista *lista, Score *score);
int vazia(Lista *lista);
int cheia(Lista *lista);
void ordenarDescrescente(Lista *lista);
void imprimirLista(Lista *lista);

typedef struct Score{
	char nome[20];
	int pontuacao;
};

Score *criarScore(char novoNome, int novaPontuacao){
	Score *score = (Score*) malloc (sizeof(Score));
	score->nome = novoNome;  
	score->pontuacao = novaPontuacao;
	return score;
}

typedef struct Lista{
	Score *scores[MAX];
	int fim;	
};

Lista *criaLista(){
	Lista *lista = (Lista*) malloc (sizeof(Lista));
	lista->fim = -1;
	return lista;
}

int adicionarScore(Lista *lista,Score *score){
	if(!cheia){
		lista->scores[lista->fim+1] = score;
		lista->fim++;
		return TRUE;	
	}else
		return FALSE;
}

int vazia(Lista *lista){
	if(lista->fim == -1){
		return TRUE;
	}
	return FALSE;
	
}

int cheia(Lista *lista){
	if(lista->fim == MAX-1){
		return TRUE;
	}else
		return FALSE;
}


void ordenarDescrescente(Lista *lista){
	if(!vazia(lista)){	
		int i;
		Score *auxScore;
		for(i=0;i<=lista->fim;i++){
			if(lista->scores[i]->pontuacao<lista->scores[i+1]->pontuacao){
				auxScore = lista->scores[i];
				lista->scores[i] = lista->scores[i+1];
				lista->scores[i+1] = auxScore;
			}
		}
	}
}

void imprimirLista(Lista *lista){
	int i;
	for(i=0;i<=lista->fim;i++){ //ou posicao<lista->fim+1
		printf("Score %d\n",i);
		printf("Nome eh %s. Pontuacao eh %d\n",lista->scores[i]->nome,lista->scores[i]->pontuacao);
	}
}

int main(void){
	
	Lista *lista = criaLista();

	Score *score1 = criarScore("M",100);
	Score *score2 = criarScore("S",130);
	Score *score3 = criarScore("O",50);
	Score *score4 = criarScore("J",500);
	
	adicionarScore(lista,score1);
	adicionarScore(lista,score2);
	adicionarScore(lista,score3);
	adicionarScore(lista,score4);

	imprimirLista(lista);
	
	return 0;
}
