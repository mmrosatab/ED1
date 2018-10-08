#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int vetor[] = {0,1,2,3,4};

void imprimir(int v[]){
	
	int i;
	
	for(i=0;i<TAM;i++){
		printf("%d",v[i]);
	}	
}

int main(){
	
	imprimir(vetor);
	
	return 0;
}
